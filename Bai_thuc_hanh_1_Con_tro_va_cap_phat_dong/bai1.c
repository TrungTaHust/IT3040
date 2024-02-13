#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int x, y, z;
	int* ptr;

	printf("Enter three integers: ");
	scanf("%d %d %d", &x, &y, &z);

	printf("\nThe three integers are:\n");

	ptr = &x;
	printf("x = %d at address: %p\n", *ptr, ptr);

	ptr = &y;
	printf("y = %d at address: %p\n", *ptr, ptr);

	ptr = &z;
	printf("z = %d at address: %p\n", *ptr, ptr);

	return 0;
}