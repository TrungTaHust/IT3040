#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int countEven(int* arr, int size) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    // Example 
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int evenCount = countEven(arr, size);

    printf("Number of even elements in the array: %d\n", evenCount);

    return 0;
}
