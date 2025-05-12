#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Structure to represent an edge
typedef struct {
    int u, v, weight;
} Edge;

int parent[MAX];

// Find with path compression
int find(int i) {
    if (parent[i] != i)
        parent[i] = find(parent[i]);
    return parent[i];
}

// Union by rank can be added here for optimization (optional)
void unionSet(int u, int v) {
    int uRoot = find(u);
    int vRoot = find(v);
    parent[uRoot] = vRoot;
}

// Compare function for sorting edges by weight
int compareEdges(const void* a, const void* b) {
    Edge* edge1 = (Edge*)a;
    Edge* edge2 = (Edge*)b;
    return edge1->weight - edge2->weight;
}

void kruskalMST(Edge edges[], int V, int E) {
    int totalCost = 0;
    Edge result[MAX];
    int e = 0;  // Index for result[]

    // Initialize disjoint sets
    for (int i = 0; i < V; i++)
        parent[i] = i;

    // Sort edges by weight
    qsort(edges, E, sizeof(Edge), compareEdges);

    for (int i = 0; i < E && e < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;

        if (find(u) != find(v)) {
            result[e++] = edges[i];
            unionSet(u, v);
            totalCost += edges[i].weight;
        }
    }

    printf("Edge \tWeight\n");
    for (int i = 0; i < e; i++)
        printf("%d - %d \t%d\n", result[i].u, result[i].v, result[i].weight);
    
    printf("Total cost of MST: %d\n", totalCost);
}

int main() {
    int V, E;
    Edge edges[MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter each edge (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d%d%d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskalMST(edges, V, E);

    return 0;
}
