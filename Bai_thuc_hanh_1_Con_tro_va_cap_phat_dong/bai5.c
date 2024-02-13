#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

double* maximum(double* a, int size) {
    if (size <= 0) {
        return NULL;  // Mảng rỗng, trả về NULL
    }

    double* max = a;

    for (int i = 1; i < size; i++) {
        if (a[i] > *max) {
            max = &a[i];
        }
    }

    return max;
}

int main() {
    // Example 
    double arr[] = { 3.5, 1.2, 7.8, 4.0, 2.5 };
    int size = sizeof(arr) / sizeof(arr[0]);

    double* maxPtr = maximum(arr, size);

    if (maxPtr != NULL) {
        printf("Maximum value in the array: %.2f\n", *maxPtr);
    }
    else {
        printf("The array is empty.\n");
    }

    return 0;
}
