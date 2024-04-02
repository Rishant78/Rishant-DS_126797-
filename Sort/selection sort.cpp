#include <stdio.h>

void main() {
    int arr[10],n;
    int i, j, l, temp;
    printf("Enter the elements in array:");
    scanf("%d",&n);
    printf("Enter the elemnts in array:");
    for(i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
	}

    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

   
    for (i = 0; i < n - 1; i++) {
        l = i;
       
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[l]) {
                l = j;
            }
        }
       
        temp = arr[i];
        arr[i] = arr[l];
        arr[l] = temp;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

