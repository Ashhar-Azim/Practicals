#include <stdio.h>
#include <limits.h>

// Function prototypes
void floydWarshall(int graph[][100], int vertices);
void printSolution(int dist[][100], int vertices);

int main() {
    int graph[100][100];
    int vertices;

    printf("Enter the number of vertices in the graph (up to 100): ");
    if (scanf("%d", &vertices) != 1 || vertices <= 0 || vertices > 100) {
        printf("Invalid input for the number of vertices. Exiting.\n");
        return 1;
    }

    printf("Enter the adjacency matrix of the graph (enter INF for unconnected edges):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (scanf("%d", &graph[i][j]) != 1) {
                printf("Invalid input for adjacency matrix element. Exiting.\n");
                return 1;
            }
        }
    }

    printf("Original adjacency matrix:\n");
    printSolution(graph, vertices);

    // Perform Floyd-Warshall algorithm
    floydWarshall(graph, vertices);

    printf("Shortest path distances between all pairs of vertices:\n");
    printSolution(graph, vertices);

    return 0;
}

// Floyd-Warshall algorithm
void floydWarshall(int graph[][100], int vertices) {
    int dist[100][100];
    int i, j, k;

    // Initialize the distance matrix with the values from the graph
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Find the shortest path between all pairs of vertices
    for (k = 0; k < vertices; k++) {
        for (i = 0; i < vertices; i++) {
            for (j = 0; j < vertices; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Copy the shortest path distances back to the graph matrix
    for (i = 0; i < vertices; i++) {
        for (j = 0; j < vertices; j++) {
            graph[i][j] = dist[i][j];
        }
    }
}

// Print the solution (distance matrix)
void printSolution(int dist[][100], int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            if (dist[i][j] == INT_MAX) {
                printf("INF ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }
}
