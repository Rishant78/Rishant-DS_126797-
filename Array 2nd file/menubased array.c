#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void IAB(int *a, int *num, int *n, int element); // Insert at beginning
void IAL(int *a, int *num, int *n, int element, int position); // Insert at location
void IAE(int *a, int *num, int *n, int element); // Insert at end
void IAA(int *a, int *num, int *n, int element, int afterElement); // Insert after an element
void IABE(int *a, int *num, int *n, int element, int beforeElement); // Insert before an element
void DB(int *a, int *num, int *n, int position); // Delete from a specific position
void DE(int *a, int *num, int *n); // Delete from end
void DA(int *a, int *num, int *n, int afterElement); // Delete after an element
void DBE(int *a, int *num, int *n, int beforeElement); // Delete before an element

int main() {
    char l;
    
    // Prompt user to create an array
    printf("Would you like to create an array:? Y or N ");
    scanf(" %c", &l);
    
    if (l == 'Y' || l == 'y') {
        int n, i, num, ch, g;
        int *a;
        
        // Initializing array size and memory allocation
        printf("\nEnter the size of array: ");
        scanf("%d", &n);
        a = (int *)malloc(n * sizeof(int));
        
        // Checking for memory allocation failure
        if (a == NULL) {
            fprintf(stderr, "Memory allocation Failed");
            return EXIT_FAILURE;
        }
        
        num = 0; // Initialize num to zero
        printf("\nEnter the number of elements you want to enter in the array: ");
        scanf("%d", &num);
        
        printf("\nEnter the elements:\n");
        for (i = 0; i < num; i++) {
            scanf("%d", &a[i]);
        }
        
        char t;
        printf("\nWould you like to display the array result (Y or N): ");
        scanf(" %c", &t);
        
        if (t == 'y' || t == 'Y') {
            printf("\nArray elements:\n");  //traversing of an array
            for (i = 0; i < num; i++) {
                printf("%d\n", a[i]);
            }
        }
        do {
            printf("\nMenu:\n");  //cases that the user can choose
            printf("1) Insert at beginning\n");
            printf("2) Insert at particular location\n");
            printf("3) Insert at the end\n");
            printf("4) Insert after an element\n");
            printf("5) Insert before an element\n");
            printf("6) Delete from beginning\n");
            printf("7) Delete from particular location\n");
            printf("8) Delete from end\n");
            printf("9) Delete after an element\n");
            printf("10) Delete before an element\n");
            printf("Enter your choice: ");
            scanf("%d", &ch);
            
            switch(ch) {
                case 1: {
                    int element;
                    printf("\nEnter the element you want to insert at the beginning: ");
                    scanf("%d", &element);
                    // Call insert at beginning function
                    IAB(a, &num, &n, element);
                    printf("\nArray after inserting element at the beginning:\n");
                    // Display array after insertion
                    for (i = 0; i < num; i++) {
                        printf("%d\n", a[i]);
                    }
                    break;
                }
                case 2: {
                    int element, position;
                    printf("\nEnter the element you want to insert: ");
                    scanf("%d", &element);
                    printf("Enter the position you want to insert at: ");
                    scanf("%d", &position);
                    // Call insert at location function
                    IAL(a, &num, &n, element, position);
                    printf("\nArray after inserting element at position %d:\n", position);
                    // Display array after insertion
                    for (i = 0; i < num; i++) {
                        printf("%d\n", a[i]);
                    }
                    break;
                }
                case 3: {
                    int element;
                    printf("\nEnter the element you want to insert at the end: ");
                    scanf("%d", &element);
                    // Call insert at end function
                    IAE(a, &num, &n, element);
                    printf("\nArray after inserting element at the end:\n");
                    // Display array after insertion
                    for (i = 0; i < num; i++) {
                        printf("%d\n", a[i]);
                    }
                    break;
                }
                case 4: {
                    int element, afterElement;
                    printf("\nEnter the element you want to insert: ");
                    scanf("%d", &element);
                    printf("Enter the element after which you want to insert: ");
                    scanf("%d", &afterElement);
                    // Call insert after an element function
                    IAA(a, &num, &n, element, afterElement);
                    printf("\nArray after inserting element after %d:\n", afterElement);
                    // Display array after insertion
                    for (i = 0; i < num; i++) {
                        printf("%d\n", a[i]);
                    }
                    break;
                }
                case 5: {
                    int element, beforeElement;
                    printf("\nEnter the element you want to insert: ");
                    scanf("%d", &element);
                    printf("Enter the element before which you want to insert: ");
                    scanf("%d", &beforeElement);
                    // Call insert before an element function
                    IABE(a, &num, &n, element, beforeElement);
                    printf("\nArray after inserting element before %d:\n", beforeElement);
                    // Display array after insertion
                    for (i = 0; i < num; i++) {
                        printf("%d\n", a[i]);
                    }
                    break;
                }
                case 6: {
                    // Call delete from beginning function
                    DE(a, &num, &n);
                    printf("\nArray after deleting element from the beginning:\n");
                    // Display array after deletion
                    for (i = 0; i < num; i++) {
                        printf("%d\n", a[i]);
                    }
                    break;
                }
                case 7: {
                    int position;
                    printf("\nEnter the position from which you want to delete: ");
                    scanf("%d", &position);
                    // Call delete from specific location function
                    DB(a, &num, &n, position);
                    printf("\nArray after deleting element from position %d:\n", position);
                    // Display array after deletion
                    for (i = 0; i < num; i++) {
                        printf("%d\n", a[i]);
                    }
                    break;
                }
                case 8: {
                    // Call delete from end function
                    DE(a, &num, &n);
                    printf("\nArray after deleting element from the end:\n");
                    // Display array after deletion
                    for (i = 0; i < num; i++) {
                        printf("%d\n", a[i]);
                    }
                    break;
                }
                case 9: {
                    int afterElement;
                    printf("\nEnter the element after which you want to delete: ");
                    scanf("%d", &afterElement);
                    // Call delete after an element function
                    DA(a, &num, &n, afterElement);
                    printf("\nArray after deleting element after %d:\n", afterElement);
                    // Display array after deletion
                    for (i = 0; i < num; i++) {
                        printf("%d\n", a[i]);
                    }
                    break;
                }
                case 10: {
                    int beforeElement;
                    printf("\nEnter the element before which you want to delete: ");
                    scanf("%d", &beforeElement);
                    // Call delete before an element function
                    DBE(a, &num, &n, beforeElement);
                    printf("\nArray after deleting element before %d:\n", beforeElement);
                    // Display array after deletion
                    for (i = 0; i < num; i++) {
                        printf("%d\n", a[i]);
                    }
                    break;
                }
                default:
                    printf("Wrong choice!!! please re-enter your choice:\n");
                    break;
            }
            printf("\nWould you like to perform the operation again:(Y or N)");
            scanf(" %c", &g);
        } while (g == 'Y' || g == 'y');   //here do while loop is used to perform the operation again if the user presses y
        free(a);
    }
    else {
        printf("\nNo array has been created!!!!\n");
        printf("Thank you for using our program.\n");
    }
    return 0;
}

// Function to insert element at the beginning
void IAB(int *a, int *num, int *n, int element) {
    int i;
    if (*num == *n) { // Check if array is full
        char k;
        printf("Array is full. Would you like to redefine the size of array? (Y or N): ");
        scanf(" %c", &k);
        if (k == 'Y' || k == 'y') { // Prompt user to redefine array size
            printf("Enter the new size of array: ");
            scanf("%d", n);
            a = realloc(a, *n * sizeof(int)); // Reallocate memory
            if (a == NULL) { // Check if reallocation failed
                fprintf(stderr, "Memory reallocation failed");
                exit(EXIT_FAILURE);
            }
        }
    }
    if (*num < *n) { // Check if there's space in the array
        for (i = *num - 1; i >= 0; i--) {
            a[i + 1] = a[i]; // Shift elements to make space for new element
        }
        a[0] = element; // Insert element at the beginning
        (*num)++; // Increment the number of elements
    }
}

// Function to insert element at a specific position
void IAL(int *a, int *num, int *n, int element, int position) {
    int i;
    if (*num == *n) { // Check if array is full
        char k;
        printf("Array is full. Would you like to redefine the size of array? (Y or N): ");
        scanf(" %c", &k);
        if (k == 'Y' || k == 'y') { // Prompt user to redefine array size
            printf("Enter the new size of array: ");
            scanf("%d", n);
            a = realloc(a, *n * sizeof(int)); // Reallocate memory
            if (a == NULL) { // Check if reallocation failed
                fprintf(stderr, "Memory reallocation failed");
                exit(EXIT_FAILURE);
            }
        }
    }
    if (*num < *n) { // Check if there's space in the array
        for (i = *num - 1; i >= position - 1; i--) {
            a[i + 1] = a[i]; // Shift elements to make space for new element
        }
        a[position - 1] = element; // Insert element at the specified position
        (*num)++; // Increment the number of elements
    }
}

// Function to insert element at the end
void IAE(int *a, int *num, int *n, int element) {
    if (*num == *n) { // Check if array is full
        char k;
        printf("Array is full. Would you like to redefine the size of array? (Y or N): ");
        scanf(" %c", &k);
        if (k == 'Y' || k == 'y') { // Prompt user to redefine array size
            printf("Enter the new size of array: ");
            scanf("%d", n);
            a = realloc(a, *n * sizeof(int)); // Reallocate memory
            if (a == NULL) { // Check if reallocation failed
                fprintf(stderr, "Memory reallocation failed");
                exit(EXIT_FAILURE);
            }
        }
    }
    a[*num] = element; // Insert element at the end
    (*num)++; // Increment the number of elements
}

// Function to insert element after a specific element
void IAA(int *a, int *num, int *n, int element, int afterElement) {
    int i, index = -1;
    for (i = 0; i < *num; i++) {
        if (a[i] == afterElement) { // Find the position of the element after which to insert
            index = i;
            break;
        }
    }
    if (index == -1) { // Element not found in the array
        printf("Element %d not found in the array.\n", afterElement);
        return;
    }
    if (*num == *n) { // Check if array is full
        char k;
        printf("Array is full. Would you like to redefine the size of array? (Y or N): ");
        scanf(" %c", &k);
        if (k == 'Y' || k == 'y') { // Prompt user to redefine array size
            printf("Enter the new size of array: ");
            scanf("%d", n);
            a = realloc(a, *n * sizeof(int)); // Reallocate memory
            if (a == NULL) { // Check if reallocation failed
                fprintf(stderr, "Memory reallocation failed");
                exit(EXIT_FAILURE);
            }
        }
    }
    if (*num < *n) { // Check if there's space in the array
        for (i = *num - 1; i > index; i--) {
            a[i + 1] = a[i]; // Shift elements to make space for new element
        }
        a[index + 1] = element; // Insert element after the specified element
        (*num)++; // Increment the number of elements
    }
}

// Function to insert element before a specific element
void IABE(int *a, int *num, int *n, int element, int beforeElement) {
    int i, index = -1;
    for (i = 0; i < *num; i++) {
        if (a[i] == beforeElement) { // Find the position of the element before which to insert
            index = i;
            break;
        }
    }
    if (index == -1) { // Element not found in the array
        printf("Element %d not found in the array.\n", beforeElement);
        return;
    }
    if (*num == *n) { // Check if array is full
        char k;
        printf("Array is full. Would you like to redefine the size of array? (Y or N): ");
        scanf(" %c", &k);
        if (k == 'Y' || k == 'y') { // Prompt user to redefine array size
            printf("Enter the new size of array: ");
            scanf("%d", n);
            a = realloc(a, *n * sizeof(int)); // Reallocate memory
            if (a == NULL) { // Check if reallocation failed
                fprintf(stderr, "Memory reallocation failed");
                exit(EXIT_FAILURE);
            }
        }
    }
    if (*num < *n) { // Check if there's space in the array
        for (i = *num - 1; i >= index; i--) {
            a[i + 1] = a[i]; // Shift elements to make space for new element
        }
        a[index] = element; // Insert element before the specified element
        (*num)++; // Increment the number of elements
    }
}

// Function to delete element from a specific position
void DB(int *a, int *num, int *n, int position) {
    if (*num == 0) { // Check if array is empty
        printf("Array is empty. Deletion not possible.\n");
        return;
    }
    if (position < 0 || position >= *num) { // Check if position is valid
        printf("Invalid position. Deletion not possible.\n");
        return;
    }
    int i;
    for (i = position; i < *num - 1; i++) {
        a[i] = a[i + 1]; // Shift elements to fill the gap
    }
    (*num)--; // Decrement the number of elements
}

// Function to delete element from the end
void DE(int *a, int *num, int *n) {
    if (*num == 0) { // Check if array is empty
        printf("Array is empty. Deletion not possible.\n");
        return;
    }
    (*num)--; // Decrement the number of elements
}

// Function to delete element after a specific element
void DA(int *a, int *num, int *n, int afterElement) {
    int i, index = -1;
    for (i = 0; i < *num; i++) {
        if (a[i] == afterElement) { // Find the position of the element after which to delete
            index = i;
            break;
        }
    }
    if (index == -1 || index == *num - 1) { // Element not found in the array or it is the last element
        printf("Element %d not found in the array or it is the last element. Deletion not possible.\n", afterElement);
        return;
    }
    for (i = index + 1; i < *num; i++) {
        a[i - 1] = a[i]; // Shift elements to fill the gap
    }
    (*num)--; // Decrement the number of elements
}

// Function to delete element before a specific element
void DBE(int *a, int *num, int *n, int beforeElement) {
    int i, index = -1;
    for (i = 0; i < *num; i++) {
        if (a[i] == beforeElement) { // Find the position of the element before which to delete
            index = i;
            break;
        }
    }
    if (index == -1 || index == 0) { // Element not found in the array or it is the first element
        printf("Element %d not found in the array or it is the first element. Deletion not possible.\n", beforeElement);
        return;
    }
    for (i = index - 1; i < *num - 1; i++) {
        a[i] = a[i + 1]; // Shift elements to fill the gap
    }
    (*num)--; // Decrement the number of elements
}

