#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
struct Node {
    int data;              // Data of the node
    struct Node* next;     // Pointer to the next node
    struct Node* prev;     // Pointer to the previous node
};

// Function prototypes
void display(struct Node* head);
struct Node* insertAtBeginning(struct Node* head, int data);
struct Node* insertAtEnd(struct Node* head, int data);
struct Node* insertAtPosition(struct Node* head, int data, int position);
struct Node* deleteAtBeginning(struct Node* head);
struct Node* deleteAtEnd(struct Node* head);
struct Node* deleteAtPosition(struct Node* head, int position);

int main() {
    int data, choice, position;
    struct Node* head = NULL;
    char ch;

    do {
        printf("Enter the data you want to enter in the list: ");
        scanf("%d", &data);
        head = insertAtEnd(head, data);

        printf("Do you wish to continue (Y/N)? ");
        scanf(" %c", &ch); // Consume the newline character
    } while (ch == 'Y' || ch == 'y');

    printf("List before modification:\n");
    display(head);

    do {
        printf("\nChoose operation:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete at the beginning\n");
        printf("5. Delete at the end\n");
        printf("6. Delete at a specific position\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            case 4:
                head = deleteAtBeginning(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            default:
                printf("Invalid choice!\n");
        }

        printf("List after modification:\n");
        display(head);

        printf("Do you wish to perform another operation (Y/N)? ");
        scanf(" %c", &ch);
    } while (ch == 'Y' || ch == 'y');

    // Free allocated memory for all nodes
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

// Function to display the doubly linked list
void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning of the doubly linked list
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;
    if (head != NULL) {
        head->prev = newNode;
    }
    return newNode;
}

// Function to insert a node at the end of the doubly linked list
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
    return head;
}

// Function to insert a node at a specific position in the doubly linked list
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 0) {
        fprintf(stderr, "Invalid position!\n");
        return head;
    }

    if (position == 0) {
        return insertAtBeginning(head, data);
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;

    struct Node* current = head;
    int count = 0;
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        fprintf(stderr, "Invalid position!\n");
        return head;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    return head;
}

// Function to delete a node at the beginning of the doubly linked list
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        fprintf(stderr, "List is empty!\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node at the end of the doubly linked list
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        fprintf(stderr, "List is empty!\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->prev->next = NULL;
    free(current);
    return head;
}

// Function to delete a node at a specific position in the doubly linked list
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL || position < 0) {
        fprintf(stderr, "List is empty or invalid position!\n");
        return head;
    }

    if (position == 0) {
        return deleteAtBeginning(head);
    }

    struct Node* current = head;
    int count = 0;
    while (current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        fprintf(stderr, "Invalid position!\n");
        return head;
    }

    current->prev->next = current->next;
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }
    free(current);
    return head;
}

