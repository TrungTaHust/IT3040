#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void allocateMatrix(int*** matrix, int n) {
    *matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        (*matrix)[i] = (int*)malloc(n * sizeof(int));
    }
}

void inputMatrix(int** matrix, int n) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int** matrix, int n) {
    printf("Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void sumMatrix(int** matrix1, int** matrix2, int** result, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void productMatrix(int** matrix1, int** matrix2, int** result, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void freeMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int n;
    printf("Enter the size of the square matrices (n): ");
    scanf("%d", &n);

    int** matrix1, ** matrix2, ** sumResult, ** productResult;

    allocateMatrix(&matrix1, n);
    allocateMatrix(&matrix2, n);
    allocateMatrix(&sumResult, n);
    allocateMatrix(&productResult, n);

    printf("Enter the elements for the first matrix:\n");
    inputMatrix(matrix1, n);

    printf("Enter the elements for the second matrix:\n");
    inputMatrix(matrix2, n);

    printf("Matrix 1:\n");
    printMatrix(matrix1, n);

    printf("Matrix 2:\n");
    printMatrix(matrix2, n);

    sumMatrix(matrix1, matrix2, sumResult, n);
    printf("Sum of the matrices:\n");
    printMatrix(sumResult, n);

    productMatrix(matrix1, matrix2, productResult, n);
    printf("Product of the matrices:\n");
    printMatrix(productResult, n);

    // Free allocated memory
    freeMatrix(matrix1, n);
    freeMatrix(matrix2, n);
    freeMatrix(sumResult, n);
    freeMatrix(productResult, n);

    return 0;
}



