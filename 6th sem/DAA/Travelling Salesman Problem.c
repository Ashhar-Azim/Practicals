#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

// Maximum number of cities
#define MAX_CITIES 10

// Function prototypes
int tsp(int graph[][MAX_CITIES], int n, int startCity);
void printPath(int path[], int n, int startCity);
bool isValidCity(int city, int path[], int index);

int main() {
    int graph[MAX_CITIES][MAX_CITIES];
    int n, startCity;

    printf("Enter the number of cities (up to %d): ", MAX_CITIES);
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_CITIES) {
        printf("Invalid input for the number of cities. Exiting.\n");
        return 1;
    }

    printf("Enter the adjacency matrix of the graph (enter INF for unconnected edges):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &graph[i][j]) != 1) {
                printf("Invalid input for adjacency matrix element. Exiting.\n");
                return 1;
            }
        }
    }

    printf("Enter the starting city (0 to %d): ", n - 1);
    if (scanf("%d", &startCity) != 1 || startCity < 0 || startCity >= n) {
        printf("Invalid input for the starting city. Exiting.\n");
        return 1;
    }

    int minCost = tsp(graph, n, startCity);

    printf("Minimum cost: %d\n", minCost);

    return 0;
}

// Traveling Salesman Problem using Dynamic Programming
int tsp(int graph[][MAX_CITIES], int n, int startCity) {
    int path[MAX_CITIES];
    bool visited[MAX_CITIES] = { false };
    int currentCity = startCity;
    int pathIndex = 0;
    int minCost = INT_MAX;

    path[pathIndex++] = currentCity;
    visited[currentCity] = true;

    while (pathIndex < n) {
        int nearestCity = -1;
        int minDistance = INT_MAX;

        // Find the nearest unvisited city from the current city
        for (int city = 0; city < n; city++) {
            if (graph[currentCity][city] != 0 && !visited[city] && graph[currentCity][city] < minDistance) {
                nearestCity = city;
                minDistance = graph[currentCity][city];
            }
        }

        if (nearestCity == -1) {
            // No unvisited city found, return to the starting city
            minCost += graph[currentCity][startCity];
            currentCity = startCity;
            path[pathIndex++] = currentCity;
        } else {
            // Visit the nearest unvisited city
            minCost += graph[currentCity][nearestCity];
            currentCity = nearestCity;
            path[pathIndex++] = currentCity;
            visited[currentCity] = true;
        }
    }

    // Add the cost to return to the starting city
    minCost += graph[currentCity][startCity];

    printf("Optimal path: ");
    printPath(path, n, startCity);

    return minCost;
}

// Print the optimal path
void printPath(int path[], int n, int startCity) {
    for (int i = 0; i < n; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", startCity);
}

// Check if a city is valid to visit next in the path
bool isValidCity(int city, int path[], int index) {
    if (index == 0) {
        return true;
    }

    if (path[index - 1] == city) {
        return false;
    }

    return true;
}
