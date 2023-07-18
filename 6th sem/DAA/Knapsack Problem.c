#include <stdio.h>
#include <stdbool.h>

// Struct to represent an item
typedef struct {
    int value;
    int weight;
} Item;

// Function prototypes
void knapsackGreedy(Item items[], int n, int capacity);
void printKnapsack(Item items[], int n);

int main() {
    Item items[100];
    int n, capacity;

    printf("Enter the number of items (up to 100): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid input for the number of items. Exiting.\n");
        return 1;
    }

    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d %d", &items[i].value, &items[i].weight) != 2) {
            printf("Invalid input for item value or weight. Exiting.\n");
            return 1;
        }
    }

    printf("Enter the capacity of the knapsack: ");
    if (scanf("%d", &capacity) != 1) {
        printf("Invalid input for the knapsack capacity. Exiting.\n");
        return 1;
    }

    printf("Items available:\n");
    printKnapsack(items, n);

    printf("Knapsack solution (Greedy Algorithm):\n");
    knapsackGreedy(items, n, capacity);

    return 0;
}

// Compare function for qsort
int compare(const void* a, const void* b) {
    Item itemA = *(const Item*)a;
    Item itemB = *(const Item*)b;
    double ratioA = (double)itemA.value / itemA.weight;
    double ratioB = (double)itemB.value / itemB.weight;

    if (ratioA > ratioB) {
        return -1;
    } else if (ratioA < ratioB) {
        return 1;
    } else {
        return 0;
    }
}

// Greedy Algorithm for Knapsack
void knapsackGreedy(Item items[], int n, int capacity) {
    // Sort items based on value/weight ratio in descending order
    qsort(items, n, sizeof(Item), compare);

    int totalWeight = 0;
    int totalValue = 0;

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalValue += items[i].value;
            printf("Item %d: Value = %d, Weight = %d\n", i + 1, items[i].value, items[i].weight);
        }
    }

    printf("Total Value: %d, Total Weight: %d\n", totalValue, totalWeight);
}

// Print the items in the knapsack
void printKnapsack(Item items[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Item %d: Value = %d, Weight = %d\n", i + 1, items[i].value, items[i].weight);
    }
}
