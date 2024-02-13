#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int x, y, z;
    int* ptr;

    scanf("%d %d %d", &x, &y, &z);
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);

    ptr = &x;
    *ptr += 100;

    ptr = &y;
    *ptr += 100;

    ptr = &z;
    *ptr += 100;

    printf("Once again, here are the values of x, y, and z (added 100 each):\n");
    printf("%d %d %d\n", x, y, z);

    return 0;
}
