#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Hàm tính giá trị ax^2 + bx + c
int get_value(int x, int a = 2, int b = 1, int c = 0) {
    return a * x * x + b * x + c;
}

int main() {
    int x;
    printf("Nhap vao mot so nguyen x (x < 100): ");
    scanf("%d", &x);

    // Nhập 3 số nguyên a, b, c từ bàn phím
    int a, b, c;
    printf("Nhap vao 3 so nguyen a, b, c: ");
    scanf("%d%d%d", &a, &b, &c);

    printf("a=2, b=1, c=0: %d\n", get_value(x));
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));

    return 0;
}


