#include <stdio.h>
#include <stdlib.h>

#define MAX 20
// Node structure for adjacency list
typedef struct node
{
    int vertex;
    struct node *next;
} Node;
// Array of adjacency lists (graph)
Node *graph[MAX];

// Number of vertices currently in use
int n = 0;
// Function to create a new node
Node *createNode(int vertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph (undirected)
void addEdge(int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph[src];
    graph[src] = newNode;
    // For undirected graph, add an edge from dest to src also
    newNode = createNode(src);
    newNode->next = graph[dest];
    graph[dest] = newNode;
}

void displayGraph()
{
    for (int i = 0; i < n; i++)
    {
        Node *temp = graph[i];
        printf("Vertex %d: ", i);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    // Initialize graph
    for (int i = 0; i < n; i++)
    {
        graph[i] = NULL;
    }
    int edges;
    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter each edge (source destination):\n");
    for (int i = 0; i < edges; i++)
    {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }
    printf("\nAdjacency List Representation:\n");
    displayGraph();
    return 0;
}