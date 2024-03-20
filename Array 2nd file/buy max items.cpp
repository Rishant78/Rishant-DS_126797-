#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (for qsort)
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

// Function to find the maximum number of items that can be bought within the budget
int max_items(int N, long long B, int A[]) {
    // Sort the array of item costs
    qsort(A, N, sizeof(int), compare);

    // Initialize variables
    long long total_cost = 0;
    int items_bought = 0;

    // Iterate through the sorted array
    for (int i = 0; i < N; i++) {
        // If adding the current item cost doesn't exceed the budget
        if (total_cost + A[i] <= B) {
            total_cost += A[i];
            items_bought++;
        } else {
            break;
        }
    }

    return items_bought;
}

int main() {
    int N;
    long long B;
    
    // Reading input
    printf("Enter the total number of items and the budget: ");
    scanf("%d %lld", &N, &B);
    int A[N];
    printf("Enter the costs of the items: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    // Calling the function and printing the result
    printf("Maximum number of items you can buy: %d\n", max_items(N, B, A));

    return 0;
}

