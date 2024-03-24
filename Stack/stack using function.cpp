#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Overflow\n");
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Underflow\n");
        return -1; // or any appropriate value indicating underflow
    } else {
        int popped = s->items[s->top];
        s->top--;
        return popped;
    }
}

int main() {
    Stack s;
    initialize(&s);

    int n, i, value;

    printf("Enter the number of elements to push: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &value);
        push(&s, value);
    }

    printf("Elements popped from the stack:\n");
    while (!isEmpty(&s)) {
        printf("%d\n", pop(&s));
    }

    return 0;
}

