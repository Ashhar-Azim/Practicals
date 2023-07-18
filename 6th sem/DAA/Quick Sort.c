#include <stdio.h>

// Function prototypes
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
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

    // Perform Quick Sort
    quickSort(arr, 0, size - 1);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}

// Quick Sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pivotIndex = partition(arr, low, high);

        // Sort the sub-arrays
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

// Partition the array
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
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
