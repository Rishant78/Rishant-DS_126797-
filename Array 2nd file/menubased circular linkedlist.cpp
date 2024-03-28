#include<stdio.h>
#include<stdlib.h>

// Node structure for the circular linked list
struct s {
    int a;
    struct s* next;
};

// Function prototypes
int lntr(struct s* head);  // Function to traverse the list
struct s* IAB(struct s* head, int a);  // Insertion at the beginning
struct s* IAP(struct s* head, int a, int index); // Insertion at a particular location
struct s* IAE(struct s* head, int a); // Insertion at the end
struct s* DAB(struct s* head); // Deletion at the beginning
struct s* DAP(struct s* head, int index); // Deletion at a particular location
struct s* DAE(struct s* head); // Deletion at the end

// Main function
int main() {
    int ch, y, k, t, u, m;
    struct s* head = NULL; // Initialize head pointer to NULL
    char c;

    do {
        do {
            struct s* n1 = (struct s*)malloc(sizeof(struct s)); // Allocate memory for a new node
            if (n1 == NULL) {
                fprintf(stderr, "Memory Allocation failed:"); // Error handling for memory allocation failure
                return EXIT_FAILURE;
            }
            printf("Enter the data You want to enter in the Link list:");
            if (scanf("%d", &n1->a) != 1) { // Input data for the new node
                fprintf(stderr, "Invalid Input:"); // Error handling for invalid input
                free(n1); // Free allocated memory
                return EXIT_FAILURE;
            }
            n1->next = NULL;    // Initialize next pointer of new node to NULL

            if (head == NULL) {
                head = n1; // If list is empty, set head to new node
                n1->next = head; // Point the next of new node to itself for circularity
            } else {
                struct s* current = head;
                while (current->next != head) { // Traverse till end of the circular list
                    current = current->next;
                }
                current->next = n1; // Connect the last node to the new node
                n1->next = head; // Make the new node point back to head for circularity
            }
            printf("Do you wish to continue Y or N??");
            scanf(" %c", &c); // Consume the newline character
        } while (c == 'Y' || c == 'y');

        printf("Would you Like to Display list without Modifying Y or N:");
        scanf(" %c", &y);
        if (y == 'Y' || y == 'y') {
            printf("The List that you Entered without modifying:\n");
            lntr(head);
            printf("\n");
        }

        printf("Do you wish to Modify Your list:");
        scanf(" %c", &k);

        if (k == 'Y' || k == 'y') {
            do {
                printf("1) Insert at beginning of list:\n");
                printf("2) Insert at particular location in list:\n");
                printf("3) Insert at the end of the list:\n");
                printf("4) Deletion at beginning of list:\n");
                printf("5) Deletion at particular location in list:\n");
                printf("6) Deletion at end of list:\n");
                printf("Enter Your choice:");
                scanf(" %d", &ch);

                switch (ch) {
                    case 1:
                        lntr(head);
                        int a;
                        printf("Enter the data you want to enter in the list:");
                        scanf("%d", &a);
                        head = IAB(head, a);
                        lntr(head);
                        break;
                    case 2:
                        lntr(head);
                        int b, ind;
                        printf("Enter the data you want to enter in the list:");
                        scanf("%d", &b);
                        printf("Enter the Location you want add the node:");
                        scanf("%d", &ind);
                        head = IAP(head, b, ind);
                        lntr(head);
                        break;
                    case 3:
                        lntr(head);
                        int c;
                        printf("Enter the data you want to enter in the list:");
                        scanf("%d", &c);
                        head = IAE(head, c);
                        lntr(head);
                        break;
                    case 4:
                        lntr(head);
                        printf("The List after Deleting the 1st node:");
                        head = DAB(head);
                        lntr(head);
                        break;
                    case 5:
                        lntr(head);
                        printf("The List after Deletion of node by your choice:");
                        int lnd;
                        printf("Enter the location you want to delete the Node:");
                        scanf("%d", &lnd);
                        head = DAP(head, lnd);
                        lntr(head);
                        break;
                    case 6:
                        lntr(head);
                        printf("The List after Deletion of node at the END:");
                        head = DAE(head);
                        lntr(head);
                        break;
                    default:
                        printf("Error! Wrong Choice(please choose between 1-6)");
                }
                printf("Would you like to choose again:");
                scanf(" %c", &t);
            } while (t == 'y' || t == 'Y');
        }

        // Free allocated memory for all nodes
        struct s* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
        printf("Would you like to Take new data from beginning:");
        scanf(" %c", &u);
    } while (u == 'y' || u == 'Y');

    return 0;
}

// Function to insert at the beginning of the circular linked list
struct s* IAB(struct s* head, int a) {
    struct s* newnode = (struct s*)malloc(sizeof(struct s));
    if (newnode == NULL) {
        fprintf(stderr, "Memory Allocation Failed:");
        exit(EXIT_FAILURE);
    }
    newnode->a = a;
    newnode->next = head; // New node points to the head
    return newnode; // Return new node as the new head
}

// Function to insert at a particular location in the circular linked list
struct s* IAP(struct s* head, int a, int index) {
    if (index < 0) {
        fprintf(stderr, "Invalid Index:");
        exit(EXIT_FAILURE);
    }

    struct s* newnode = (struct s*)malloc(sizeof(struct s));
    if (newnode == NULL) {
        fprintf(stderr, "Memory Allocation Failed:");
        exit(EXIT_FAILURE);
    }
    newnode->a = a;

    if (index == 0) { // If index is 0, insert at the beginning
        newnode->next = head;
        return newnode;
    }

    struct s* current = head;
    int i = 0;
    while (current->next != head && i < index - 1) { // Traverse till the desired index
        current = current->next;
        i++;
    }

    newnode->next = current->next; // Insert the new node at the specified index
    current->next = newnode;
    return head; // Return the head of the modified list
}

// Function to insert at the end of the circular linked list
struct s* IAE(struct s* head, int a) {
    struct s* newn = (struct s*)malloc(sizeof(struct s));
    if (newn == NULL) {
        fprintf(stderr, "Memory allocation failed:\n");
        exit(EXIT_FAILURE);
    }

    newn->a = a;
    newn->next = head; // New node points to the head

    if (head == NULL) {
        return newn;
    }

    struct s* current = head;
    while (current->next != head) { // Traverse till the end of the circular list
        current = current->next;
    }
    current->next = newn; // Connect the last node to the new node
    return head; // Return the head of the modified list
}

// Function to delete at the beginning of the circular linked list
struct s* DAB(struct s* head) {
    if (head == NULL) {
        fprintf(stderr, "Linked list is empty:");
        exit(EXIT_FAILURE);
    }
    struct s* temp = head;
    struct s* current = head;
    while (current->next != head) { // Traverse till the end of the circular list
        current = current->next;
    }
    head = head->next; // Move head to the next node
    current->next = head; // Connect the last node to the new head
    free(temp); // Free the old head
    return head; // Return the new head
}

// Function to delete at a particular location in the circular linked list
struct s* DAP(struct s* head, int index) {
    if (head == NULL) {
        fprintf(stderr, "Linked list is empty. Nothing to delete.\n");
        return NULL;
    }

    if (index < 0) {
        fprintf(stderr, "Invalid index\n");
        return head;
    }

    if (index == 0) { // If index is 0, delete the head
        struct s* temp = head;
        struct s* current = head;
        while (current->next != head) { // Traverse till the end of the circular list
            current = current->next;
        }
        head = head->next; // Move head to the next node
        current->next = head; // Connect the last node to the new head
        free(temp); // Free the old head
        return head; // Return the new head
    }

    struct s* current = head;
    int i = 0;
    while (current->next != head && i < index - 1) { // Traverse till the desired index
        current = current->next;
        i++;
    }

    if (current->next == head) {
        fprintf(stderr, "Index out of bounds\n");
        return head;
    }

    struct s* temp = current->next; // Store the node to be deleted
    current->next = temp->next; // Connect the previous node to the next node of the node to be deleted
    free(temp); // Free the node to be deleted
    return head; // Return the head of the modified list
}

// Function to delete at the end of the circular linked list
struct s* DAE(struct s* head) {
    if (head == NULL) {
        fprintf(stderr, "Linked list is empty:");
        exit(EXIT_FAILURE);
    }

    struct s* current = head;
    struct s* prev = NULL;
    while (current->next != head) { // Traverse till the second last node
        prev = current;
        current = current->next;
    }

    if (prev == NULL) { // If only one node is present
        free(current);
        return NULL;
    }

    prev->next = head; // Make the second last node point to the head
    free(current); // Free the last node
    return head; // Return the head of the modified list
}

// Function to traverse and display the circular linked list
int lntr(struct s* current) {
    if (current == NULL) {
        printf("List is empty\n");
        return 0;
    }

    struct s* temp = current;
    do {
        printf("%d->", temp->a);
        temp = temp->next;
    } while (temp != current); // Traverse till we reach the head again
    printf("HEAD\n");
    return 0;
}
