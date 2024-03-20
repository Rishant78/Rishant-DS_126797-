#include <stdio.h>

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Subsets with equal sums:\n");
    int equalSumFound = 0;
    // Loop for generating subsets and calculating sums
    for (int i = 0; i < (1 << n); i++) { // (1 << n) calculates 2^n
        int sum = 0;
        printf("Subset %d: ", i + 1);
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                sum += arr[j];
                printf("%d ", arr[j]); // Print the included element
            }
        }
        printf("(Sum = %d)\n", sum);

        // Check for equal sums with subsequent subsets
        for (int k = i + 1; k < (1 << n); k++) {
            int sum2 = 0;
            for (int j = 0; j < n; j++) {
                if ((k & (1 << j)) != 0) {
                    sum2 += arr[j];
                }
            }
            if (sum == sum2) {
                equalSumFound = 1;
                printf("Equal sum found in subsets %d and %d\n", i + 1, k + 1);
            }
        }
    }
    if (!equalSumFound) {
        printf("No subsets with equal sums found.\n");
    }

    return 0;
}

