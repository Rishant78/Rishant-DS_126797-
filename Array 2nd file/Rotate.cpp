#include <stdio.h>

// Function to find the last element to be deleted
int lastDeletedElement(int arr[], int n) {
    int i, lastDeleted = -1;
    for (i = 0; i < n; i++) {
        lastDeleted = arr[i];
    }
    return lastDeleted;
}

// Function to minimize the sum of product
int minimizeSumOfProduct(int A[], int B[], int n) {
    int i, minSum = 0;

    // Sorting the arrays A and B
    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
            if (B[i] > B[j]) {
                int temp = B[i];
                B[i] = B[j];
                B[j] = temp;
            }
        }
    }

    // Finding the sum of product
    for (i = 0; i < n; i++) {
        minSum += A[i] * B[n - i - 1];
    }
    return minSum;
}

int main() {
    int T;
    printf("Enter the number of test cases: ");
    scanf("%d", &T);

    // For each test case
    while (T--) {
        int N;
        printf("Enter the size of the array: ");
        scanf("%d", &N);

        int arr[N];
        printf("Enter the elements of the array: ");
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }

        // Finding the last deleted element
        int lastDeleted = lastDeletedElement(arr, N);
        printf("Last deleted element: %d\n", lastDeleted);

        // Input arrays A and B for minimizing sum of product
        int A[N], B[N];
        printf("Enter the elements of array A: ");
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        printf("Enter the elements of array B: ");
        for (int i = 0; i < N; i++) {
            scanf("%d", &B[i]);
        }

        // Finding the minimum sum of product
        int minSum = minimizeSumOfProduct(A, B, N);
        printf("Minimum sum of product: %d\n\n", minSum);
    }
    return 0;
}

