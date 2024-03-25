#include <stdio.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front, rear;
} Queue;

void initializeQueue(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

int isFull(Queue queue) {
    return queue.rear == MAX_SIZE - 1;
}

int isEmpty(Queue queue) {
    return queue.front == -1;
}

void enqueue(Queue *queue, int item) {
    if (isFull(*queue)) {
        printf("Queue is full. Can't enqueue item.\n");
    } else {
        if (isEmpty(*queue)) {
            queue->front = 0; // Initialize front
        }
        queue->rear++;
        queue->items[queue->rear] = item;
        printf("Enqueued %d to the queue.\n", item);
    }
}

int dequeue(Queue *queue) {
    int item;
    if (isEmpty(*queue)) {
        printf("Queue is empty. Can't dequeue item.\n");
        return -1;
    } else {
        item = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front++;
        }
        printf("Dequeued %d from the queue.\n", item);
        return item;
    }
}

void display(Queue queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue contents: ");
        for (int i = queue.front; i <= queue.rear; i++) {
            printf("%d ", queue.items[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue queue;
    initializeQueue(&queue);

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
                enqueue(&queue, item);
                break;
            case 2:
                dequeue(&queue);
                break;
            case 3:
                display(queue);
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

