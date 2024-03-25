#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5

typedef struct {
    int items[MAX_SIZE];
    int front, rear;
    bool full;
} Queue;

Queue createQueue() {
    Queue queue;
    queue.front = 0;
    queue.rear = -1;
    queue.full = false;
    return queue;
}

bool isFull(Queue queue) {
    return queue.full;
}

bool isEmpty(Queue queue) {
    return (!queue.full && (queue.rear == -1)) || (queue.front == (queue.rear + 1) % MAX_SIZE);
}

void enqueue(Queue *queue, int item) {
    if (isFull(*queue)) {
        printf("Queue is full. Can't enqueue item.\n");
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = item;
        if (queue->front == queue->rear) {
            queue->full = true;
        }
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
            queue->front = 0;
            queue->rear = -1;
            queue->full = false;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        printf("Dequeued %d from the queue.\n", item);
        return item;
    }
}

void display(Queue queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue contents: ");
        if (queue.front <= queue.rear) {
            for (i = queue.front; i <= queue.rear; i++) {
                printf("%d ", queue.items[i]);
            }
        } else {
            for (i = queue.front; i < MAX_SIZE; i++) {
                printf("%d ", queue.items[i]);
            }
            for (i = 0; i <= queue.rear; i++) {
                printf("%d ", queue.items[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    Queue queue = createQueue();

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);  // This will print "Queue is full. Can't enqueue item."

    display(queue);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);  // This will print "Queue is empty. Can't dequeue item."

    return 0;
}

