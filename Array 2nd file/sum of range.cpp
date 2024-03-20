#include <stdio.h>

int main() {
    int N, Q;
    printf("Enter the number of elements and number of queries: ");
    scanf("%d %d", &N, &Q);
    
    int arr[N];
    printf("Enter the array elements: ");
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);
    
    int prefix_sum[N + 1];
    prefix_sum[0] = 0;
    for (int i = 1; i <= N; i++)
        prefix_sum[i] = prefix_sum[i - 1] + arr[i - 1];
    
    printf("Enter the queries (L R): \n");
    for (int i = 0; i < Q; i++) {
        int L, R;
        scanf("%d %d", &L, &R);
        int sum = prefix_sum[R] - prefix_sum[L - 1];
        printf("Sum of elements between %d and %d inclusive: %d\n", L, R, sum);
    }
    
    return 0;
}

