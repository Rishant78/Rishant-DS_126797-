#include <stdio.h>

// Function to perform binary search
int binarySearch(int *arr, int size, int key) {
    int left = 0; // Initialize left pointer
    int right = size - 1; // Initialize right pointer

    // Binary search loop
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate mid index

        // Check if the key is present at mid
        if (*(arr + mid) == key)
            return mid; // Return index of key if found

        // If key is greater, ignore left half
        if (*(arr + mid) < key)
            left = mid + 1; // Move left pointer

        // If key is smaller, ignore right half
        else
            right = mid - 1; // Move right pointer
    }

    // If the key is not present in the array
    return -1; // Return -1 to indicate key not found
}

int main() {
    int size, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size); // Input size of the array

    int arr[size]; // Declare array of given size

    printf("Enter the elements of the array in sorted order:\n");
    // Input elements of the array
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key); // Input key to search for

    // Call binary search function and store the result
    int result = binarySearch(arr, size, key);

    // Output the result of binary search
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0; // Return 0 to indicate successful completion
}

