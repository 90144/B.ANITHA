#include <stdio.h>
#include <stdbool.h>

#define V 5  // Max number of vertices (adjustable)

int graph[V][V];     // Adjacency matrix
int path[V];         // Stores the current Hamiltonian path

// Check if vertex v can be added at index 'pos' in the Hamiltonian Cycle
bool isSafe(int v, int pos) {
    // Check if this vertex is adjacent to the previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if vertex has already been included
    for (int i = 0; i < pos; i++) {
        if (path[i] == v)
            return false;
    }

    return true;
}

// Recursive utility function to solve the Hamiltonian Cycle problem
bool hamiltonianCycleUtil(int pos) {
    // Base case: all vertices are included
    if (pos == V) {
        // Check if there's an edge from the last vertex to the first
        return graph[path[pos - 1]][path[0]] == 1;
    }

    // Try different vertices as the next candidate
    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos)) {
            path[pos] = v;

            // Recur to construct rest of the path
            if (hamiltonianCycleUtil(pos + 1))
                return true;

            // Backtrack
            path[pos] = -1;
        }
    }

    return false;
}

// Solve the Hamiltonian Cycle problem
bool hamiltonianCycle() {
    // Initialize path
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0; // Start at vertex 0

    if (hamiltonianCycleUtil(1) == false) {
        printf("No Hamiltonian Cycle exists.\n");
        return false;
    }

    // Print the cycle
    printf("Hamiltonian Cycle exists:\n");
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]); // Return to starting vertex

    return true;
}

// Main function
int main() {
    // Example graph (adjacency matrix)
    int example[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    // Copy example to global graph
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            graph[i][j] = example[i][j];

    hamiltonianCycle();

    return 0;
}
