#include <stdio.h>

#define MAX_SIZE 10

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int rows, cols, i, j;
    int asymmetric = 0;

    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check if the matrix is asymmetric
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (matrix[i][j] != matrix[j][i]) {
                asymmetric = 1;
                break;
            }
        }
        if (asymmetric == 1) {
            break;
        }
    }

    if (asymmetric == 1) {
        printf("The matrix is asymmetric.\n");
    } else {
        printf("The matrix is symmetric.\n");
    }

    return 0;
}

