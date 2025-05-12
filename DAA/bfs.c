#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];  // Adjacency matrix
int visited[MAX];   // Visited array
int n;              // Number of vertices

// BFS function
void bfs(int start) {
    int queue[MAX];
    int front = 0, rear = 0;

    // Mark all vertices as unvisited
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // Start from the given vertex
    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS traversal starting from vertex %d: ", start);

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        // Visit all adjacent unvisited vertices
        for (int i = 0; i < n; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

// Main function
int main() {
    int edges, src, dest, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix to 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // Input edges
    printf("Enter edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;
        adj[dest][src] = 1;  // For undirected graph
    }

    printf("Enter starting vertex for BFS: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}
