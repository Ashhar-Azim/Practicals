#include <stdio.h>

// Function prototypes
void heapSort(int arr[], int size);
void buildMaxHeap(int arr[], int size);
void maxHeapify(int arr[], int size, int i);
void swap(int* a, int* b);

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

    // Perform Heap Sort
    heapSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Heap Sort
void heapSort(int arr[], int size) {
    // Build max heap
    buildMaxHeap(arr, size);

    // Perform sorting
    for (int i = size - 1; i >= 1; i--) {
        // Swap root (max element) with the last element
        swap(&arr[0], &arr[i]);

        // Heapify the reduced heap
        maxHeapify(arr, i, 0);
    }
}

// Build Max Heap
void buildMaxHeap(int arr[], int size) {
    // Start from the last non-leaf node
    for (int i = size / 2 - 1; i >= 0; i--) {
        maxHeapify(arr, size, i);
    }
}

// Max Heapify
void maxHeapify(int arr[], int size, int i) {
    int largest = i;     // Initialize largest as root
    int left = 2 * i + 1;    // Left child
    int right = 2 * i + 2;   // Right child

    // If left child is larger than root
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than the largest so far
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected sub-tree
        maxHeapify(arr, size, largest);
    }
}

// Swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
