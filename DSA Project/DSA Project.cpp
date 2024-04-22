#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Person struct
struct Person {
    char name[20];
    int id;
    char gender[30];
    int salary;
    int age;
    char dob[11]; // Date of Birth (YYYY-MM-DD)
};

// Define Node struct containing a pointer to Person
struct Node {
    struct Person *data;
    struct Node *next;
};

// Function prototypes
void inputPeople(struct Node **head);
void printDetails(struct Node *head);
void printSalaryRange(struct Node *head);
void searchById(struct Node *head);
void printByGender(struct Node *head);
void deletePerson(struct Node **head);
char continueProgram();
int generateUniqueID();

int main() {
    struct Node *head = NULL;
    char choice;

    do {
        int option;
        printf("\nEnter your choice (1-5):\n");
        printf("1. Input people\n");
        printf("2. Print details\n");
        printf("3. Print people with salary between 90k and 150k\n");
        printf("4. Search person by ID\n");
        printf("5. Print people by gender\n");
        printf("6. Delete person by ID, name, and demise date\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                inputPeople(&head);
                break;
            case 2:
                printDetails(head);
                break;
            case 3:
                printSalaryRange(head);
                break;
            case 4:
                searchById(head);
                break;
            case 5:
                printByGender(head);
                break;
            case 6:
                deletePerson(&head);
                break;
            default:
                printf("Invalid choice!\n");
        }

        choice = continueProgram();
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

void inputPeople(struct Node **head) {
    int numPeople;
    printf("Enter the number of people to be recorded: ");
    scanf("%d", &numPeople);

    for (int i = 0; i < numPeople; i++) {
        struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        // Allocate memory for the Person struct inside the Node
        newNode->data = (struct Person*)malloc(sizeof(struct Person));
        if (newNode->data == NULL) {
            printf("Memory allocation failed.\n");
            free(newNode); // Free the allocated Node memory before exiting
            exit(1);
        }

        printf("Enter Name, Gender, Date of Birth (YYYY-MM-DD), Age for person %d: ", i + 1);
        scanf("%s %s %s %d", newNode->data->name, newNode->data->gender, newNode->data->dob, &newNode->data->age);
        
        char employmentChoice;
        printf("Is the person employed? (y/n): ");
        scanf(" %c", &employmentChoice);
        
        if (employmentChoice == 'y' || employmentChoice == 'Y') {
            printf("Enter Salary for person %d: ", i + 1);
            scanf("%d", &newNode->data->salary);
        } else {
            newNode->data->salary = -1; // Placeholder for indicating no salary
        }
        
        newNode->data->id = generateUniqueID();
        newNode->next = *head;
        *head = newNode;
    }

    printf("Input successful.\n");
}

void printDetails(struct Node *head) {
    printf("\nDetails of people:\n");
    struct Node *current = head;
    while (current != NULL) {
        if (current->data->age > 0 && current->data->age <= 15) {
            printf("%d\t%s\t%s\tNo Salary\t%d\t%s\n", current->data->id, current->data->name, current->data->gender, current->data->age, current->data->dob);
        } else {
            printf("%d\t%s\t%s\t%d\t%d\t%s\n", current->data->id, current->data->name, current->data->gender, current->data->salary, current->data->age, current->data->dob);
        }
        current = current->next;
    }
}

void printSalaryRange(struct Node *head) {
    printf("\nPeople with salary between 90k and 150k:\n");
    struct Node *current = head;
    while (current != NULL) {
        if (current->data->salary > 90000 && current->data->salary < 150000) {
            printf("%d\t%s\t%s\t%d\t%d\t%s\n", current->data->id, current->data->name, current->data->gender, current->data->salary, current->data->age, current->data->dob);
        }
        current = current->next;
    }
}

void searchById(struct Node *head) {
    int key;
    printf("\nEnter the ID to search: ");
    scanf("%d", &key);
    struct Node *current = head;
    printf("\nSearch result:\n");
    while (current != NULL) {
        if (current->data->id == key) {
            if (current->data->age > 0 && current->data->age <= 15) {
                printf("%d\t%s\t%s\tNo Salary\t%d\t%s\n", current->data->id, current->data->name, current->data->gender, current->data->age, current->data->dob);
            } else {
                printf("%d\t%s\t%s\t%d\t%d\t%s\n", current->data->id, current->data->name, current->data->gender, current->data->salary, current->data->age, current->data->dob);
            }
            return;
        }
        current = current->next;
    }
    printf("Person with ID %d not found.\n", key);
}

void printByGender(struct Node *head) {
    char gen[20];
    printf("\nEnter the gender you want to print: ");
    scanf("%s", gen);
    printf("\nPeople with gender %s:\n", gen);
    struct Node *current = head;
    while (current != NULL) {
        if (strcmp(current->data->gender, gen) == 0) {
            if (current->data->age > 0 && current->data->age <= 15) {
                printf("%d\t%s\t%s\tNo Salary\t%d\t%s\n", current->data->id, current->data->name, current->data->gender, current->data->age, current->data->dob);
            } else {
                printf("%d\t%s\t%s\t%d\t%d\t%s\n", current->data->id, current->data->name, current->data->gender, current->data->salary, current->data->age, current->data->dob);
            }
        }
        current = current->next;
    }
}

void deletePerson(struct Node **head) {
    int id;
    char name[20];
    char demiseDate[11];

    printf("Enter ID of the person to delete: ");
    scanf("%d", &id);
    printf("Enter name of the person to delete: ");
    scanf("%s", name);
    printf("Enter demise date of the person to delete (YYYY-MM-DD): ");
    scanf("%s", demiseDate);

    struct Node *current = *head;
    struct Node *prev = NULL;

    while (current != NULL) {
        if (current->data->id == id && strcmp(current->data->name, name) == 0 && strcmp(current->data->dob, demiseDate) == 0) {
            printf("\nData of the person to be deleted:\n");
            printf("ID: %d\nName: %s\nGender: %s\nSalary: %d\nAge: %d\nDOB: %s\n", current->data->id, current->data->name, current->data->gender, current->data->salary, current->data->age, current->data->dob);
            printf("This person is recorded so all his data will be removed.\n");

            if (prev == NULL) { // If the node to be deleted is the head
                *head = current->next;
            } else {
                prev->next = current->next;
            }

            free(current->data); // Free the allocated Person memory
            free(current); // Free the allocated Node memory
            printf("Data of the person has been successfully deleted.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("Person with provided ID, name, and demise date not found.\n");
}

char continueProgram() {
    char choice;
    printf("\nDo you wish to continue? (y/n): ");
    scanf(" %c", &choice);
    return choice;
}

int generateUniqueID() {
    static int lastID = 1000;
    lastID++;
    return lastID;
}

