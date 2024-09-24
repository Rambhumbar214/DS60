#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtEnd(struct Node** head, int data);
struct Node* findIntersection(struct Node* list1, struct Node* list2);
void displayList(struct Node* node);
void freeList(struct Node* node);

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* intersection = findIntersection(list1, list2);
    int n1, n2, data;
     int i;
    // Input for first linked list
    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n1);
    printf("Enter the elements:\n");
    for ( i = 0; i < n1; i++) {
	scanf("%d", &data);
	insertAtEnd(&list1, data);
    }

    // Input for second linked list
    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &n2);
    printf("Enter the elements:\n");
    for ( i = 0; i < n2; i++) {
	scanf("%d", &data);
	insertAtEnd(&list2, data);
    }

    // Find intersection

    
    // Display results
    printf("Intersection of the two linked lists:\n");
    displayList(intersection);

    // Free allocated memory
    freeList(list1);
    freeList(list2);
    freeList(intersection);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
     struct Node* last = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }


    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

// Function to find the intersection of two linked lists
struct Node* findIntersection(struct Node* list1, struct Node* list2) {
    struct Node* intersection = NULL;

    while (list1 != NULL) {
        struct Node* temp = list2;
        while (temp != NULL) {
            if (list1->data == temp->data) {
                insertAtEnd(&intersection, list1->data);
                break;
            }
            temp = temp->next;
        }
        list1 = list1->next;
    }
    return intersection;
}

// Function to display the linked list
void displayList(struct Node* node) {
    if (node == NULL) {
        printf("No intersection.\n");
        return;
    }
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to free the linked list
void freeList(struct Node* node) {
    struct Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}
