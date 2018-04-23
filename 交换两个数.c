#include <stdio.h>

void swap(int &a, int &b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int main()
{
	int a = 10;
	int b = 12;
	swap(a, b);
	printf("a = %d, b = %d\n", a, b);
}