#include <stdio.h>

// Function to swap two elements in an array
void swap(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

// Function to arrange binary digits
void arrangeBinary(char binary[], int size) {
    int left = 0, right = size - 1;

    while (left < right) {
        // Move left pointer to the first occurrence of '1'
        while (binary[left] == '0' && left < right) {
            left++;
        }

        // Move right pointer to the first occurrence of '0' from the end
        while (binary[right] == '1' && left < right) {
            right--;
        }

        // Swap the elements at left and right indices
        if (left < right) {
            swap(&binary[left], &binary[right]);
            left++;
            right--;
        }
    }
}

int main() {
    char binary[] = "11010100";
    int size = sizeof(binary) - 1; // Exclude null terminator

    printf("Original binary sequence: %s\n", binary);

    // Arrange binary digits
    arrangeBinary(binary, size);

    printf("Arranged binary sequence: %s\n", binary);

    return 0;
}

