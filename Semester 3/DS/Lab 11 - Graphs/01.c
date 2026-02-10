#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int adjMat[MAX][MAX];
int visited[MAX];
int n;

typedef struct Node {
    int vertex;
    Node* next;
} Node;

Node* adjList[MAX];

void createAdjMatrix(int directed) {
    int i, j, edges, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            adjMat[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d%d", &src, &dest);
        adjMat[src][dest] = 1;
        if (!directed)
            adjMat[dest][src] = 1;
    }

    printf("\nAdjacency Matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", adjMat[i][j]);
        printf("\n");
    }
}

void addEdgeList(int src, int dest) {
    Node* n = (Node*)malloc(sizeof(struct Node));
    n->vertex = dest;
    n->next = adjList[src];
    adjList[src] = n;
}

void createAdjList(int directed) {
    int i, edges, src, dest;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) adjList[i] = NULL;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d%d", &src, &dest);
        addEdgeList(src, dest);
        if (!directed)
            addEdgeList(dest, src);
    }

    printf("\nAdjacency List:\n");
    for (i = 0; i < n; i++) {
        Node* temp = adjList[i];
        printf("%d -> ", i);
        while (temp) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

void BFS(int start) {
    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++) visited[i] = 0;
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS Traversal: ");
    while (front < rear) {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (adjMat[v][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

void DFSRec(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
        if (adjMat[v][i] && !visited[i])
            DFSRec(i);
}

void DFS(int start) {
    for (int i = 0; i < n; i++) visited[i] = 0;
    printf("DFS Traversal: ");
    DFSRec(start);
    printf("\n");
}

int main() {
    int choice, start;
    while (1) {
        printf("\n---- GRAPH MENU ----\n");
        printf("1. Directed Graph (Matrix)\n");
        printf("2. Undirected Graph (Matrix)\n");
        printf("3. Directed Graph (List)\n");
        printf("4. Undirected Graph (List)\n");
        printf("5. BFS Traversal\n");
        printf("6. DFS Traversal\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAdjMatrix(1); break;
            case 2: createAdjMatrix(0); break;
            case 3: createAdjList(1); break;
            case 4: createAdjList(0); break;
            case 5:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                BFS(start);
                break;
            case 6:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                DFS(start);
                break;
            case 7: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}