#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

int* a;
int n, tmp;

void bubbleSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                // swap
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}

int main() {
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory
    a = new int[n];

    // Input array elements using pointers
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);

    printf("The input array is: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");

    // Sort array using pointers
    bubbleSort(a, n);

    printf("The sorted array is: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");

    delete[] a;  // Deallocate memory

    return 0;
}


