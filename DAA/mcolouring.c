#include <stdio.h>
#include <stdbool.h>

#define V 4  // Number of vertices in the graph

int graph[V][V];      // Adjacency matrix
int color[V];         // Color assigned to each vertex

// Check if it's safe to assign color c to vertex v
bool isSafe(int v, int c, int m) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c)
            return false;
    }
    return true;
}

// Recursive utility function to solve the M-coloring problem
bool graphColoringUtil(int m, int v) {
    if (v == V)
        return true;  // All vertices are assigned a color

    // Try different colors for vertex v
    for (int c = 1; c <= m; c++) {
        if (isSafe(v, c, m)) {
            color[v] = c;

            if (graphColoringUtil(m, v + 1))
                return true;

            // Backtrack
            color[v] = 0;
        }
    }
    return false;  // No color can be assigned
}

// Function to solve the problem
bool graphColoring(int m) {
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColoringUtil(m, 0) == false) {
        printf("No solution exists with %d colors.\n", m);
        return false;
    }

    printf("Solution exists with %d colors:\n", m);
    for (int i = 0; i < V; i++)
        printf("Vertex %d ---> Color %d\n", i, color[i]);

    return true;
}

// Main function
int main() {
    // Example graph (adjacency matrix)
    int example[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    // Copy example to global graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = example[i][j];

    int m;
    printf("Enter number of colors: ");
    scanf("%d", &m);

    graphColoring(m);

    return 0;
}
