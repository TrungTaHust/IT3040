#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int a[7] = { 13, -355, 235, 47, 67, 943, 1222 };

    printf("Address of first five elements in memory.\n");
    for (int i = 0; i < 5; i++) {
        printf("a[%d]: %p\n", i, (void*)&a[i]);
    }

    return 0;
}
