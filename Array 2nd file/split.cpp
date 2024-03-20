#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Find the index to split the array
    int split_index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            split_index = i;
            break;
        }
    }

    // If no non-zero element found, print "NO"
    if (split_index == -1) {
        printf("NO\n");
        return 0;
    }

    // Print "YES" and split the array
    printf("YES\n");
    printf("2\n");
    printf("1 %d\n", split_index);
    printf("%d %d\n", split_index + 1, n);

    return 0;
}

