#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the adjacency list
struct Node {
    int vertex;
    struct Node* next;
};

// Define the structure for the adjacency list
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Function prototypes
struct Node* createNode(int vertex);
struct Graph* createGraph(int vertices);
void addEdge(struct Graph* graph, int src, int dest);
void displayGraph(struct Graph* graph);
void freeGraph(struct Graph* graph);

int main() {
    int i, vertices, edges, src, dest;
	    struct Graph* graph = createGraph(vertices);
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);



    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (src dest):\n");
    for ( i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("\nAdjacency List Representation of the Graph:\n");
    displayGraph(graph);

    // Free allocated memory
    freeGraph(graph);

    return 0;
}

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int vertices) {
    int i;
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    // Initialize each adjacency list as NULL
    for ( i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add an edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to display the graph
void displayGraph(struct Graph* graph) {
    int i;
    for ( i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("-> %d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to free the allocated memory for the graph
void freeGraph(struct Graph* graph) {
    int i;
    for ( i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        while (temp) {
            struct Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }
    free(graph->adjLists);
    free(graph);
}
