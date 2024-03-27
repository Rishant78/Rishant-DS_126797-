#include <stdio.h>
#include <stdlib.h>

// Define the structure of a queue node
struct Node {
    int data;
    struct Node* next;
};

// Define the structure of a circular queue
struct CircularQueue {
    struct Node *rear;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

// Function to create an empty circular queue
struct CircularQueue* createCircularQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->rear = NULL;
    return queue;
}

// Function to check if the circular queue is empty
int isEmpty(struct CircularQueue* queue) {
    return (queue->rear == NULL);
}

// Function to add an element to the circular queue
void enqueue(struct CircularQueue* queue, int data) {
    struct Node* temp = newNode(data);
    if (isEmpty(queue)) {
        queue->rear = temp;
        temp->next = temp; // Point to itself to create circularity
    } else {
        temp->next = queue->rear->next; // New node points to the first node
        queue->rear->next = temp; // Rear node points to the new node
        queue->rear = temp; // Rear is updated to the new node
    }
    printf("Enqueued %d to the queue.\n", data);
}

// Function to remove an element from the circular queue
int dequeue(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    struct Node* temp = queue->rear->next;
    int data = temp->data;
    if (temp == queue->rear) { // If only one node is present
        queue->rear = NULL;
    } else {
        queue->rear->next = temp->next; // Rear node points to the second node
    }
    free(temp);
    printf("Dequeued %d from the queue.\n", data);
    return data;
}

// Function to traverse and print elements of the circular queue
void traverse(struct CircularQueue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    struct Node* current = queue->rear->next; // Start from the first node
    printf("Queue elements: ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->rear->next); // Traverse until we reach the rear node again
    printf("\n");
}

int main() {
    // Create a circular queue
    struct CircularQueue* queue = createCircularQueue();

    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traverse\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue(queue));
                break;
            case 3:
                traverse(queue);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 4);

    return 0;
}

