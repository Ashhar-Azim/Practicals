#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Maximum number of vertices in the graph
#define MAX_VERTICES 100

// Struct to represent an edge
typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

// Struct to represent a graph
typedef struct {
    int numVertices;
    int numEdges;
    Edge edges[MAX_VERTICES];
} Graph;

// Function prototypes
void primMST(Graph* graph);
void kruskalMST(Graph* graph);
int find(int parent[], int i);
void unionSet(int parent[], int rank[], int x, int y);
int compareEdges(const void* a, const void* b);
void printMST(Edge mst[], int numEdges);

int main() {
    Graph graph;
    int choice;

    printf("Enter the number of vertices in the graph (up to %d): ", MAX_VERTICES);
    if (scanf("%d", &graph.numVertices) != 1 || graph.numVertices <= 0 || graph.numVertices > MAX_VERTICES) {
        printf("Invalid input for the number of vertices. Exiting.\n");
        return 1;
    }

    printf("Enter the number of edges in the graph: ");
    if (scanf("%d", &graph.numEdges) != 1 || graph.numEdges < 0 || graph.numEdges > (graph.numVertices * (graph.numVertices - 1) / 2)) {
        printf("Invalid input for the number of edges. Exiting.\n");
        return 1;
    }

    printf("Enter the edges of the graph (source, destination, weight):\n");
    for (int i = 0; i < graph.numEdges; i++) {
        if (scanf("%d %d %d", &graph.edges[i].src, &graph.edges[i].dest, &graph.edges[i].weight) != 3 ||
            graph.edges[i].src < 0 || graph.edges[i].src >= graph.numVertices ||
            graph.edges[i].dest < 0 || graph.edges[i].dest >= graph.numVertices ||
            graph.edges[i].weight < 0) {
            printf("Invalid input for edge. Exiting.\n");
            return 1;
        }
    }

    printf("Select the MST algorithm:\n");
    printf("1. Prim's Algorithm\n");
    printf("2. Kruskal's Algorithm\n");
    printf("Enter your choice (1 or 2): ");
    if (scanf("%d", &choice) != 1 || (choice != 1 && choice != 2)) {
        printf("Invalid input for the choice. Exiting.\n");
        return 1;
    }

    if (choice == 1) {
        printf("Minimum Spanning Tree using Prim's Algorithm:\n");
        primMST(&graph);
    } else if (choice == 2) {
        printf("Minimum Spanning Tree using Kruskal's Algorithm:\n");
        kruskalMST(&graph);
    }

    return 0;
}

// Prim's Algorithm for MST
void primMST(Graph* graph) {
    int parent[MAX_VERTICES]; // Array to store the parent of each vertex in the MST
    int key[MAX_VERTICES]; // Array to store the key values used to pick the minimum weight edge

    bool visited[MAX_VERTICES] = { false }; // Array to track visited vertices
    for (int i = 0; i < graph->numVertices; i++) {
        key[i] = INT_MAX;
    }

    key[0] = 0;
    parent[0] = -1; // Start vertex has no parent

    for (int count = 0; count < graph->numVertices - 1; count++) {
        int minKey = INT_MAX;
        int minIndex = -1;

        // Find the vertex with the minimum key value among the vertices not yet included in MST
        for (int v = 0; v < graph->numVertices; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                minIndex = v;
            }
        }

        visited[minIndex] = true;

        // Update the key values and parents of the adjacent vertices of the picked vertex
        for (int v = 0; v < graph->numVertices; v++) {
            if (graph->edges[minIndex][v] != 0 && !visited[v] && graph->edges[minIndex][v] < key[v]) {
                parent[v] = minIndex;
                key[v] = graph->edges[minIndex][v];
            }
        }
    }

    // Print the constructed MST
    Edge mst[MAX_VERTICES - 1];
    int mstIndex = 0;
    for (int i = 1; i < graph->numVertices; i++) {
        mst[mstIndex].src = parent[i];
        mst[mstIndex].dest = i;
        mst[mstIndex].weight = graph->edges[i][parent[i]];
        mstIndex++;
    }

    printMST(mst, graph->numVertices - 1);
}

// Kruskal's Algorithm for MST
void kruskalMST(Graph* graph) {
    Edge result[MAX_VERTICES];
    int resultIndex = 0;

    // Sort the edges in non-decreasing order of their weights
    qsort(graph->edges, graph->numEdges, sizeof(Edge), compareEdges);

    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int numEdges = 0;
    int i = 0;

    while (numEdges < graph->numVertices - 1 && i < graph->numEdges) {
        Edge nextEdge = graph->edges[i++];

        int x = find(parent, nextEdge.src);
        int y = find(parent, nextEdge.dest);

        if (x != y) {
            result[resultIndex++] = nextEdge;
            unionSet(parent, rank, x, y);
            numEdges++;
        }
    }

    printMST(result, numEdges);
}

// Find the subset of an element
int find(int parent[], int i) {
    if (parent[i] != i) {
        parent[i] = find(parent, parent[i]);
    }
    return parent[i];
}

// Perform union of two subsets
void unionSet(int parent[], int rank[], int x, int y) {
    int xRoot = find(parent, x);
    int yRoot = find(parent, y);

    if (rank[xRoot] < rank[yRoot]) {
        parent[xRoot] = yRoot;
    } else if (rank[xRoot] > rank[yRoot]) {
        parent[yRoot] = xRoot;
    } else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

// Compare function for sorting edges
int compareEdges(const void* a, const void* b) {
    Edge edgeA = *(const Edge*)a;
    Edge edgeB = *(const Edge*)b;

    return edgeA.weight - edgeB.weight;
}

// Print the MST
void printMST(Edge mst[], int numEdges) {
    for (int i = 0; i < numEdges; i++) {
        printf("Edge %d: %d - %d, Weight: %d\n", i + 1, mst[i].src, mst[i].dest, mst[i].weight);
    }
}
