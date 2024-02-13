#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Hàm tính lập phương của số nguyên
int cube(int x) {
    return x * x * x;
}

// Hàm tính lập phương của số thực
double cube(double x) {
    return x * x * x;
}

int main() {
    int n;
    double f;
    printf("Nhap mot so nguyen va mot so thuc: ");
    scanf("%d %lf", &n, &f);

    printf("Int: %d\n", cube(n));
    printf("Double: %.2lf\n", cube(f));

    return 0;
}



