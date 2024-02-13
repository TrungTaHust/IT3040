#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) {
    float hypotenuse = sqrt(x * x + y * y);
    return hypotenuse;
}

int main() {
    float x, y;
    printf("Nhap vao hai canh goc vuong x va y: ");
    scanf("%f%f", &x, &y);

    if (x <= 0 || y <= 0) {
        printf("Vui long nhap gia tri duong cho hai canh goc vuong.\n");
        return 1;
    }

    float z = get_hypotenuse(x, y);
    printf("Do dai canh huyen cua tam giac la: %.2f\n", z);

    return 0;
}
