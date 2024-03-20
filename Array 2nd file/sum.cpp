#include <stdio.h>
#include <limits.h>

int main() {
    int N;
    printf("Enter the total number of elements: ");
    scanf("%d", &N);
    
    int arr[N];
    printf("Enter the array elements: ");
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    int min_sum = INT_MAX;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int sum = arr[i] + arr[j];
            if (sum < min_sum)
                min_sum = sum;
        }
    }
    
    printf("Minimum sum: %d\n", min_sum);
    
    return 0;
}

