#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printSubsequences(int* arr, int n) {
    printf("All subsequences of the given array are:\n");

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            // In ra dãy con từ i đến j sử dụng con trỏ
            for (int* ptr = arr + i; ptr <= arr + j; ptr++) {
                printf("%d ", *ptr);
            }
            printf("\n");
        }
    }
}

int main() {
    int arr[] = { 1, 3, 4, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printSubsequences(arr, n);

    return 0;
}


