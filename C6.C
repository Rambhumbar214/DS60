#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function prototypes
struct Node* createNode(int data);
struct Node* insert(struct Node* node, int data);
void inorderTraversal(struct Node* node);
void freeTree(struct Node* node);

int main() {
    struct Node* root = NULL;
    int n, data;
     int i;
    printf("Enter the number of integers to insert into the BST: ");
    scanf("%d", &n);

    for ( i = 0; i < n; i++) {
        printf("Enter integer %d: ", i + 1);
        scanf("%d", &data);
        root = insert(root, data);
    }

    printf("\nInorder Traversal of the BST:\n");
    inorderTraversal(root);
    printf("\n");

    // Free the allocated memory for the tree
    freeTree(root);

    return 0;
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new node in the BST
struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

// Function to perform inorder traversal
void inorderTraversal(struct Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

// Function to free the tree
void freeTree(struct Node* node) {
    if (node != NULL) {
        freeTree(node->left);
        freeTree(node->right);
        free(node);
    }
}
