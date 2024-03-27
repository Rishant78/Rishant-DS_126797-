#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int front = -1;
int rear = -1;
int queue[MAX_SIZE];

int main() {
    int choice, item;
    while (1) {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                if ((rear + 1) % MAX_SIZE == front) {
                    printf("Queue is full. Can't enqueue item.\n");
                    break;
                }
                if (front == -1)
                    front = 0;
                rear = (rear + 1) % MAX_SIZE;
                queue[rear] = item;
                printf("Enqueued %d to the queue.\n", item);
                break;
            case 2:
                if (front == -1) {
                    printf("Queue is empty. Can't dequeue item.\n");
                    break;
                }
                item = queue[front];
                if (front == rear) {
                    front = -1;
                    rear = -1;
                } else {
                    front = (front + 1) % MAX_SIZE;
                }
                printf("Dequeued %d from the queue.\n", item);
                break;
            case 3:
                if (front == -1) {
                    printf("Queue is empty.\n");
                    break;
                }
                printf("Queue contents: ");
                if (front <= rear) {
                    for (int i = front; i <= rear; i++) {
                        printf("%d ", queue[i]);
                    }
                } else {
                    for (int i = front; i < MAX_SIZE; i++) {
                        printf("%d ", queue[i]);
                    }
                    for (int i = 0; i <= rear; i++) {
                        printf("%d ", queue[i]);
                    }
                }
                printf("\n");
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
        }
    }

    return 0;
}

