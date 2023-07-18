#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool isSubsetSum(int set[], int n, int sum);
bool subsetSumUtil(int set[], int n, int sum, int currentSum, int currentIndex);

int main() {
    int set[100];
    int n, sum;

    printf("Enter the number of elements in the set (up to 100): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 100) {
        printf("Invalid input for the number of elements. Exiting.\n");
        return 1;
    }

    printf("Enter the elements of the set: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &set[i]) != 1) {
            printf("Invalid input for set element. Exiting.\n");
            return 1;
        }
    }

    printf("Enter the target sum: ");
    if (scanf("%d", &sum) != 1) {
        printf("Invalid input for the target sum. Exiting.\n");
        return 1;
    }

    if (isSubsetSum(set, n, sum)) {
        printf("Subset with sum %d exists in the given set.\n", sum);
    } else {
        printf("No subset with sum %d exists in the given set.\n", sum);
    }

    return 0;
}

// Check if there exists a subset with the given sum
bool isSubsetSum(int set[], int n, int sum) {
    return subsetSumUtil(set, n, sum, 0, 0);
}

// Subset Sum recursive utility function
bool subsetSumUtil(int set[], int n, int sum, int currentSum, int currentIndex) {
    if (currentSum == sum) {
        return true;
    }

    if (currentIndex >= n || currentSum > sum) {
        return false;
    }

    bool include = subsetSumUtil(set, n, sum, currentSum + set[currentIndex], currentIndex + 1);
    bool exclude = subsetSumUtil(set, n, sum, currentSum, currentIndex + 1);

    return include || exclude;
}
