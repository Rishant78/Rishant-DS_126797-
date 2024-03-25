#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

int isEmpty() {
    return front == -1;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Can't enqueue item.\n");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = item;
        printf("Enqueued %d to the queue.\n", item);
    }
}

int dequeue() {
    int item;
    if (isEmpty()) {
        printf("Queue is empty. Can't dequeue item.\n");
        return -1;
    } else {
        item = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("Dequeued %d from the queue.\n", item);
        return item;
    }
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue contents: ");
        if (front <= rear) {
            for (i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        } else {
            for (i = front; i < MAX_SIZE; i++) {
                printf("%d ", queue[i]);
            }
            for (i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
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

    return 0;
}

