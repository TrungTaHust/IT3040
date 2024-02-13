#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Hàm đảo ngược mảng dùng chỉ số
void reversearray(int arr[], int size) {
    int l = 0, r = size - 1, tmp;

    while (l < r) {
        // Hoán đổi giá trị giữa phần tử ở chỉ số l và r
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;

        // Di chuyển về phía trong của mảng
        l++;
        r--;
    }
}

// Hàm đảo ngược mảng dùng con trỏ
void ptr_reversearray(int* arr, int size) {
    int* l = arr;
    int* r = arr + size - 1;
    int tmp;

    while (l < r) {
        // Hoán đổi giá trị giữa phần tử tại con trỏ l và r
        tmp = *l;
        *l = *r;
        *r = tmp;

        // Di chuyển con trỏ về phía trong của mảng
        l++;
        r--;
    }
}

int main() {
    // Example 
    int arr[] = { 9, -1, 4, 5, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Gọi hàm đảo ngược mảng dùng chỉ số
    reversearray(arr, size);

    printf("\nReversed array (using index): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    // Khôi phục lại mảng ban đầu
    reversearray(arr, size);

    // Gọi hàm đảo ngược mảng dùng con trỏ
    ptr_reversearray(arr, size);

    printf("\nReversed array (using pointer): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

