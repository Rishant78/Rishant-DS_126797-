#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int main() {
    int choice, item;

    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (rear == MAX_SIZE - 1) {
                    printf("Queue is full. Can't enqueue item.\n");
                } else {
                    if (front == -1)
                        front = 0;
                    rear++;
                    printf("Enter the element to enqueue: ");
                    scanf("%d", &item);
                    queue[rear] = item;
                    printf("Enqueued %d to the queue.\n", item);
                }
                break;
            case 2:
                if (front == -1 || front > rear) {
                    printf("Queue is empty. Can't dequeue item.\n");
                } else {
                    item = queue[front];
                    front++;
                    printf("Dequeued %d from the queue.\n", item);
                }
                break;
            case 3:
                if (front == -1 || front > rear) {
                    printf("Queue is empty.\n");
                } else {
                    printf("Queue contents: ");
                    for (int i = front; i <= rear; i++) {
                        printf("%d ", queue[i]);
                    }
                    printf("\n");
                }
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

