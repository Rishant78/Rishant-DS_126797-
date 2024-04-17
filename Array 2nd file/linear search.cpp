#include <stdio.h>

// Function to perform linear search
int linearSearch(int *arr, int size, int key) {
    // Iterate through the array
    for (int i = 0; i < size; i++) {
        // If the current element equals the key, return the index
        if (*(arr + i) == key)
            return i;
    }
    // If key is not found, return -1
    return -1;
}

int main() {
    int size, key;
    printf("Enter the size of the array: ");
    scanf("%d", &size); // Input size of the array

    int arr[size]; // Declare array of given size

    printf("Enter the elements of the array:\n");
    // Input elements of the array
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key); // Input key to search for

    // Call linear search function and store the result
    int result = linearSearch(arr, size, key);

    // Output the result of linear search
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0; // Return 0 to indicate successful completion
}

