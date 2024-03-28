#include<stdio.h>
#include<stdlib.h>

// Define a structure for a linked list node
struct s {
    int a;
    struct s* next; // Pointer to the next node
};

// Function prototypes
int lntr(struct s* head); // Function to traverse and display the linked list
struct s* IAB(struct s* head, int a); // Function to insert a node at the beginning
struct s* IAP(struct s* head, int a, int index); // Function to insert a node at a particular location
struct s* IAE(struct s* head, int a); // Function to insert a node at the end
struct s* DAB(struct s* head); // Function to delete a node from the beginning
struct s* DAP(struct s* head, int index); // Function to delete a node from a particular location
struct s* DAE(struct s* head); // Function to delete a node from the end

int main() {
    int ch, y, k, t, u, m;
    struct s* head = NULL; // Initialize the head of the linked list to NULL
    char c;

    do {
        // Input data into the linked list until user decides to stop
        do {
            // Dynamically allocate memory for a new node
            struct s* n1 = (struct s*)malloc(sizeof(struct s));
            if (n1 == NULL) {
                fprintf(stderr, "Memory Allocation failed:"); // Error handling for memory allocation failure
                return EXIT_FAILURE;
            }

            printf("Enter the data You want to enter in the Link list:");
            if (scanf("%d", &n1->a) != 1) { // Input data into the new node
                fprintf(stderr, "Invalid Input:"); // Error handling for invalid input
                free(n1);
                return EXIT_FAILURE;
            }
            n1->next = NULL; // Set the next pointer of the new node to NULL

            // Insert the new node at the end of the linked list
            if (head == NULL) {
                head = n1;
            } else {
                struct s* current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = n1;
            }

            printf("Do you wish to continue Y or N??");
            scanf(" %c", &c); // consume the newline character
        } while (c == 'Y' || c == 'y');

        // Display the original linked list
        printf("Would you Like to Display list without Modifying Y or N:");
        scanf(" %c", &y);
        if (y == 'Y' || y == 'y') {
            printf("The List that you Entered without modifying:\n");
            lntr(head); // Call the function to traverse and display the linked list
            printf("\n");
        }

        // Modify the linked list based on user input
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
                scanf(" %d", &ch); // Added space before %d for robust input reading

                switch (ch) {
                    case 1:
                        lntr(head);
                        int a;
                        printf("Enter the data you want to enter in the list:");
                        scanf("%d", &a);
                        head = IAB(head, a); // Call function to insert a node at the beginning
                        lntr(head);
                        break;
                    case 2:
                        lntr(head);
                        int b, ind;
                        printf("Enter the data you want to enter in the list:");
                        scanf("%d", &b);
                        printf("Enter the Location you want add the node:");
                        scanf("%d", &ind);
                        head = IAP(head, b, ind); // Call function to insert a node at a particular location
                        lntr(head);
                        break;
                    case 3:
                        lntr(head);
                        int c;
                        printf("Enter the data you want to enter in the list:");
                        scanf("%d", &c);
                        head = IAE(head, c); // Call function to insert a node at the end
                        lntr(head);
                        break;
                    case 4:
                        lntr(head);
                        printf("The List after Deleting the 1st node:");
                        head = DAB(head); // Call function to delete a node from the beginning
                        lntr(head);
                        break;
                    case 5:
                        lntr(head);
                        printf("The List after Deletion of node by your choice:");
                        int lnd;
                        printf("Enter the location you want to delete the Node:");
                        scanf("%d", &lnd);
                        head = DAP(head, lnd); // Call function to delete a node from a particular location
                        lntr(head);
                        break;
                    case 6:
                        lntr(head);
                        printf("The List after Deletion of node at the END:");
                        head = DAE(head); // Call function to delete a node from the end
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

// Function to insert a node at the beginning of the linked list
struct s* IAB(struct s* head, int a) {
    struct s* newnode = (struct s*)malloc(sizeof(struct s));
    if (newnode == NULL) {
        fprintf(stderr, "Memory Allocation Failed:");
        exit(EXIT_FAILURE);
    }
    newnode->a = a;
    newnode->next = head;
    return newnode;
}

// Function to insert a node at a particular location in the linked list
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

    if (index == 0) {
        newnode->next = head;
        return newnode;
    }

    struct s* current = head;
    int i = 0;
    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }

    if (current == NULL) {
        fprintf(stderr, "Index out of bound");
        exit(EXIT_FAILURE);
    }

    newnode->next = current->next;
    current->next = newnode;
    return head;
}

// Function to insert a node at the end of the linked list
struct s* IAE(struct s* head, int a) {
    struct s* newn = (struct s*)malloc(sizeof(struct s));
    if (newn == NULL) {
        fprintf(stderr, "Memory allocation failed:\n");
        exit(EXIT_FAILURE);
    }

    newn->a = a;
    newn->next = NULL;

    if (head == NULL) {
        return newn;
    }

    struct s* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newn;
    return head;
}

// Function to delete a node from the beginning of the linked list
struct s* DAB(struct s* head) {
    if (head == NULL) {
        fprintf(stderr, "Linked list is empty:");
        exit(EXIT_FAILURE);
    }
    struct s* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from a particular location in the linked list
struct s* DAP(struct s* head, int index) {
    if (head == NULL) {
        fprintf(stderr, "Linked list is empty. Nothing to delete.\n");
        return NULL;
    }

    if (index < 0) {
        fprintf(stderr, "Invalid index\n");
        return head;
    }

    if (index == 0) {
        struct s* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct s* current = head;
    int i = 0;
    while (current != NULL && i < index - 1) {
        current = current->next;
        i++;
    }

    if (current == NULL || current->next == NULL) {
        fprintf(stderr, "Index out of bounds\n");
        return head;
    }

    struct s* temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

// Function to delete a node from the end of the linked list
struct s* DAE(struct s* head) {
    if (head == NULL || head->next == NULL) {
        // If the list is empty or has only one node, nothing to delete
        free(head);
        return NULL;
    }

    struct s* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;

    return head;
}

// Function to traverse and display the linked list
int lntr(struct s* current) {
    while (current != NULL) {
        printf("%d->", current->a);
        current = current->next;
    }
    printf("NULL\n");
    return 0;
}

