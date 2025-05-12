#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

// Function to find the vertex with minimum distance value
int minDistance(int dist[], bool visited[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print shortest path distances
void printSolution(int dist[], int V, int src) {
    printf("Vertex\tDistance from Source (%d)\n", src);
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            printf("%d \t\tINF\n", i);
        else
            printf("%d \t\t%d\n", i, dist[i]);
    }
}

// Dijkstra's algorithm
void dijkstra(int graph[MAX][MAX], int src, int V) {
    int dist[MAX];        // Output array. dist[i] will hold shortest distance from src to i
    bool visited[MAX];    // visited[i] will be true if vertex i is included in shortest path

    for (int i = 0; i < V; i++)
        dist[i] = INF, visited[i] = false;

    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        visited[u] = true;

        for (int v = 0; v < V; v++)
            if (!visited[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist, V, src);
}

// Main function
int main() {
    int V, src;
    int graph[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter the adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter source vertex (0 to %d): ", V - 1);
    scanf("%d", &src);

    dijkstra(graph, src, V);

    return 0;
}
