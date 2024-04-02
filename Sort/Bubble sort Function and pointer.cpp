#include <stdio.h>

// Function prototypes
void bubbleSort(int *arr, int size, int order);
void printArray(int *arr, int size);

int main() {
    char t;
    
    do {
        int i, n, ch;
        int a[10]; // Array to store elements

        printf("Enter the number of terms (max 10): ");
        scanf("%d", &n);

        if (n <= 0 || n > 10) {
            printf("Invalid input! Please enter a number between 1 and 10.\n");
            continue; // Restart the loop to prompt for valid input
        }

        // Input array elements from the user
        for (i = 0; i < n; i++) {
            printf("Enter term %d: ", i + 1); // Adjust index to start from 1
            scanf("%d", &a[i]);
        }

        // Ask the user for their choice of sorting order
        printf("Enter your choice (Ascending=1 & Descending=2): ");
        scanf("%d", &ch);

        // Perform sorting based on user choice
        bubbleSort(a, n, ch);

        // Print the sorted array
        printf("Sorted array:\n");
        printArray(a, n);

        // Ask the user if they want to run the program again
        printf("Do you want to sort another array? (Enter 'y' for yes, 'n' for no): ");
        scanf(" %c", &t); // Note: space before %c to consume any leading whitespace
    } while (t == 'y' || t == 'Y'); // Repeat if user enters 'y' or 'Y'

    printf("Thank you for using the sorting program. Goodbye!\n");

    return 0;
}

// Function to perform bubble sort
// arr: pointer to the array
// size: size of the array
// order: sorting order (1 for ascending, 2 for descending)
void bubbleSort(int *arr, int size, int order) {
    int i, j, temp;
    // Sorting in ascending order
    if (order == 1) {
        for (i = 0; i < size; i++) {
            for (j = 0; j < size - i - 1; j++) {
                if (*(arr + j) > *(arr + j + 1)) {
                    temp = *(arr + j);
                    *(arr + j) = *(arr + j + 1);
                    *(arr + j + 1) = temp;
                }
            }
        }
    }
    // Sorting in descending order
    else if (order == 2) {
        for (i = 0; i < size; i++) {
            for (j = 0; j < size - i - 1; j++) {
                if (*(arr + j) < *(arr + j + 1)) {
                    temp = *(arr + j);
                    *(arr + j) = *(arr + j + 1);
                    *(arr + j + 1) = temp;
                }
            }
        }
    }
    // Invalid sorting order
    else {
        printf("Error! Invalid sorting order.\n");
    }
}

// Function to print the array elements
// arr: pointer to the array
// size: size of the array
void printArray(int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\n", *(arr + i));
    }
}

