#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

int* a;
int n, tmp;

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

    // Sort array using std::sort and pointers
    std::sort(a, a + n);

    printf("The sorted array is: \n");
    for (int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");

    delete[] a;  // Deallocate memory

    return 0;
}


