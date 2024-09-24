#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

// Function prototypes
struct Node* createNode(int data);
void insertAtEnd(struct Node** head, int data);
void deleteNode(struct Node** head, int key);
void displayList(struct Node* node);
void freeList(struct Node* node);

int main() {
    struct Node* head = NULL;
    int choice, data;

    do {
        printf("\nDoubly Linked List Menu:\n");
        printf("1. Insert at end\n");
        printf("2. Delete a node\n");
        printf("3. Display the list\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to insert: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 2:
                printf("Enter the integer to delete: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;

            case 3:
                printf("The doubly linked list is: ");
                displayList(head);
                break;

            case 4:
                printf("Exiting the program.\n");
                freeList(head);
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
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
    newNode->prev = last;
}

// Function to delete a node with a given key
void deleteNode(struct Node** head, int key) {
     struct Node* temp = *head;
    if (*head == NULL) {
	printf("List is empty!\n");
	return;
    }



    // Check if head node is the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        free(temp);
        printf("Deleted %d from the list.\n", key);
        return;
    }

    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) {
        printf("Key %d not found in the list.\n", key);
        return;
    }

    // Unlink the node from the linked list
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    free(temp);
    printf("Deleted %d from the list.\n", key);
}

// Function to display the list
void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to free the list
void freeList(struct Node* node) {
    struct Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}
