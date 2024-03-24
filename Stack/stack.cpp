#include <stdio.h>
#include <stdlib.h>

int main() {
    int *s;
    int n, i, a;
    int top = -1;
    int UB;

    printf("Enter the size of Stack: ");
    scanf("%d", &n);
    s = (int *)malloc(n * sizeof(int));

    if (s == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the size: ");
    scanf("%d", &UB);

    for (i = 0; i < UB; i++) {
        printf("Enter the element: ");
        scanf("%d", &a);
        if (top == n - 1) {
            printf("Overflow\n");
            break;
        } else {
            top++;
            s[top] = a;
        }
    }

    if (top == -1) {
        printf("Enter the value you want to enter: ");
        scanf("%d", &a);
        top++;
        s[top] = a;
    }

    free(s); // Deallocate the memory

    return 0;
}

