#include <stdio.h>
#include <stdlib.h>

// Define the structure of a stack node
struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* top = NULL; // Initialize stack top pointer

    // Push some elements onto the stack
    struct Node* newNode1 = (struct Node*)malloc(sizeof(struct Node));
    if (newNode1 == NULL) {
        printf("Memory allocation failed. Stack overflow.\n");
        return -1;
    }
    newNode1->data = 10;
    newNode1->next = top;
    top = newNode1;

    struct Node* newNode2 = (struct Node*)malloc(sizeof(struct Node));
    if (newNode2 == NULL) {
        printf("Memory allocation failed. Stack overflow.\n");
        return -1;
    }
    newNode2->data = 20;
    newNode2->next = top;
    top = newNode2;

    struct Node* newNode3 = (struct Node*)malloc(sizeof(struct Node));
    if (newNode3 == NULL) {
        printf("Memory allocation failed. Stack overflow.\n");
        return -1;
    }
    newNode3->data = 30;
    newNode3->next = top;
    top = newNode3;

    // Display the stack
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        struct Node* current = top;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }

    // Pop an element from the stack
    if (top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
    } else {
        struct Node* temp = top;
        top = top->next;
        free(temp);
        printf("Popped element: %d\n", temp->data);
    }

    // Display the stack after popping
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        struct Node* current = top;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }

    return 0;
}

