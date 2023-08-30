/*matric multiplication*/
#include <stdio.h>

#define MAX_SIZE 10

void multiplyMatrices(int matrix1[][MAX_SIZE], int rows1, int cols1,
                      int matrix2[][MAX_SIZE], int rows2, int cols2,
                      int result[][MAX_SIZE]);
void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols);

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter the elements of matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        printf("row %d: ", i + 1);
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    printf("Enter the elements of matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        printf("row %d: ", i + 1);
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
        printf("\n");
    }

    multiplyMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2, result);

    printf("Resultant matrix after multiplication:\n");
    displayMatrix(result, rows1, cols2);

    return 0;
}

/**
 * multiplymatrices: takes two matrices as arguement, multiplies them
 *                   stores the result in the third argument.
*/
void multiplyMatrices(int matrix1[][MAX_SIZE], int rows1, int cols1,
                      int matrix2[][MAX_SIZE], int rows2, int cols2,
                      int result[][MAX_SIZE]) {
    if (cols1 != rows2) {
        printf("Matrix dimensions are not compatible for multiplication.\n");
        return;
    }

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

/**
 * displayMatrix: prints the matrix passed to it to the 
 *                stdout stream
*/
void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}