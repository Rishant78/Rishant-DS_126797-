#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int *queue;
int *front = NULL;
int *rear = NULL;

// Function to initialize the linear queue
void initializeQueue() {
    queue = (int *)malloc(MAX_SIZE * sizeof(int));
    if (queue == NULL) {
        printf("Memory allocation failed. Exiting.\n");
        exit(1);
    }
    front = queue;
    rear = queue;
}

// Function to check if the queue is full
int isFull() {
    return rear == queue + MAX_SIZE;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == rear;
}

// Function to enqueue an item into the linear queue
void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Can't enqueue item.\n");
    } else {
        *rear = item;
        rear++;
        printf("Enqueued %d to the queue.\n", item);
    }
}

// Function to dequeue an item from the linear queue
int dequeue() {
    int item;
    if (isEmpty()) {
        printf("Queue is empty. Can't dequeue item.\n");
        return -1;
    } else {
        item = *front;
        front++;
        printf("Dequeued %d from the queue.\n", item);
        return item;
    }
}

// Function to display the linear queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue contents: ");
        int *ptr = front;
        while (ptr != rear) {
            printf("%d ", *ptr);
            ptr++;
        }
        printf("\n");
    }
}

// Function to deallocate memory allocated for the linear queue
void destroyQueue() {
    free(queue);
}

int main() {
    int choice, item;

    initializeQueue();

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter again.\n");
        }
    } while (choice != 4);

    destroyQueue();

    return 0;
}

