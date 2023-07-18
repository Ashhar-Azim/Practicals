#include <stdio.h>

// Function prototypes
int linearSearch(int arr[], int size, int key);
int binarySearch(int arr[], int low, int high, int key);

int main() {
    int arr[100];
    int size, key, result;

    printf("Enter the number of elements in the array (up to 100): ");
    if (scanf("%d", &size) != 1 || size <= 0 || size > 100) {
        printf("Invalid input for size. Exiting.\n");
        return 1;
    }

    printf("Enter the elements in the array in sorted order: ");
    for (int i = 0; i < size; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("Invalid input for array element. Exiting.\n");
            return 1;
        }
    }

    printf("Enter the element to search: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input for search key. Exiting.\n");
        return 1;
    }

    // Linear Search
    result = linearSearch(arr, size, key);
    if (result != -1) {
        printf("Element found at index %d using linear search.\n", result);
    } else {
        printf("Element not found using linear search.\n");
    }

    // Binary Search
    result = binarySearch(arr, 0, size - 1, key);
    if (result != -1) {
        printf("Element found at index %d using binary search.\n", result);
    } else {
        printf("Element not found using binary search.\n");
    }

    return 0;
}

// Linear Search
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Element found, return index
        }
    }
    return -1; // Element not found
}

// Binary Search
int binarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1; // Element not found
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) {
        return mid; // Element found at mid index
    } else if (arr[mid] > key) {
        return binarySearch(arr, low, mid - 1, key); // Search in the left half
    } else {
        return binarySearch(arr, mid + 1, high, key); // Search in the right half
    }
}
