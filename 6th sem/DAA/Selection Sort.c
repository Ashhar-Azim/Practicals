#include <stdio.h>

// Function prototypes
void selectionSort(int arr[], int size);
void swap(int* a, int* b);
void printArray(int arr[], int size);

int main() {
    int arr[100];
    int size;

    printf("Enter the number of elements in the array (up to 100): ");
    if (scanf("%d", &size) != 1 || size <= 0 || size > 100) {
        printf("Invalid input for size. Exiting.\n");
        return 1;
    }

    printf("Enter the elements in the array: ");
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input for array element. Exiting.\n");
            return 1;
        }
    }

    printf("Original array: ");
    printArray(arr, size);

    // Perform Selection Sort
    selectionSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}

// Selection Sort
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;

        // Find the minimum element in the unsorted part of the array
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the minimum element with the first element of the unsorted part
        swap(&arr[i], &arr[minIndex]);
    }
}

// Swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
