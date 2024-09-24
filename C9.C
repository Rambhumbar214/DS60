#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top != -1) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top != -1) {
        return stack[top];
    }
    return '\0';
}

int precedence(char c) {
    switch (c) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int is_operator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infix_to_postfix(const char *infix, char *postfix) {
    int j = 0;
    int i;

    for ( i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        
        if (isalnum(c)) {
            postfix[j++] = c; // If the character is an operand, add it to output
        } else if (c == '(') {
            push(c); // If the character is '(', push it to the stack
        } else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[j++] = pop(); // Pop until '(' is found
            }
            pop(); // Remove '(' from stack
        } else if (is_operator(c)) {
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop(); // Pop operators from the stack
            }
            push(c); // Push the current operator to the stack
        }
    }

    while (top != -1) {
        postfix[j++] = pop(); // Pop all remaining operators from the stack
    }
    postfix[j] = '\0'; // Null-terminate the postfix string
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0; // Remove newline character

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
