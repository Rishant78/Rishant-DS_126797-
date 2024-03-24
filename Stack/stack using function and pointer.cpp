#include <stdio.h>
#include <stdlib.h>

void push(int *stack, int *top, int n, int value) {
    if (*top == n - 1) {
        printf("Overflow\n");
    } else {
        *top = *top + 1;
        stack[*top] = value;
    }
}

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
        push(s, &top, n, a);
    }

    if (top == -1) {
        printf("Enter the value you want to enter: ");
        scanf("%d", &a);
        push(s, &top, n, a);
    }

    free(s); // Deallocate the memory

    return 0;
}

