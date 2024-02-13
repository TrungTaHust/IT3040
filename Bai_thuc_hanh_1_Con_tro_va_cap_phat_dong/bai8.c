#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void allocate_mem(int*** mt, int m, int n) {
    *mt = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        (*mt)[i] = (int*)malloc(n * sizeof(int));
    }
}

void input(int** mt, int m, int n) {
    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mt[i][j]);
        }
    }
}

void output(int** mt, int m, int n) {
    printf("Matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mt[i][j]);
        }
        printf("\n");
    }
}

int process(int** mt, int m, int n) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mt[i][j] % 2 == 0) {
                sum += mt[i][j];
            }
        }
    }
    return sum;
}

void free_mem(int** mt, int m, int n) {
    for (int i = 0; i < m; i++) {
        free(mt[i]);
    }
    free(mt);
}

int main() {
    int m, n, ** mt;
    printf("Enter m, n = ");
    scanf("%d%d", &m, &n);

    allocate_mem(&mt, m, n);
    input(mt, m, n);
    output(mt, m, n);

    int sumEven = process(mt, m, n);
    printf("The sum of all even elements is %d\n", sumEven);

    free_mem(mt, m, n);
    return 0;
}


