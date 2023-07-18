#include <stdio.h>

// Function prototypes
void shellSort(int arr[], int size);
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

    // Perform Shell Sort
    shellSort(arr, size);

    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}

// Shell Sort
void shellSort(int arr[], int size) {
    // Start with a large gap and reduce it on each iteration
    for (int gap = size / 2; gap > 0; gap /= 2) {
        // Perform insertion sort for the elements at each gap
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;

            // Shift elements that are greater than temp to the right
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
    }
}

// Print the elements of an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
