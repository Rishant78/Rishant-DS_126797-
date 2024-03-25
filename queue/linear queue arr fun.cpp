#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = 0;
int rear = 0;
int itemCount = 0;

// Function to check if the queue is full
int isFull() {
    return itemCount == MAX_SIZE;
}

// Function to check if the queue is empty
int isEmpty() {
    return itemCount == 0;
}

// Function to enqueue an item into the linear queue
void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Can't enqueue item.\n");
    } else {
        queue[rear] = item;
        rear = (rear + 1) % MAX_SIZE;
        itemCount++;
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
        item = queue[front];
        front = (front + 1) % MAX_SIZE;
        itemCount--;
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
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("\n");
    }
}

int main() {
    int choice, item;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (isFull()) {
                    printf("Queue is full. Can't enqueue item.\n");
                } else {
                    printf("Enter the element to enqueue: ");
                    scanf("%d", &item);
                    enqueue(item);
                }
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

    return 0;
}

