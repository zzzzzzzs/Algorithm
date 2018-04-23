#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	char a[] = "C:/Users/lenovo/Desktop/1.c";
	FILE *p = fopen(a, "r");
	if (p)
	{
		char c = getc(p);
		while (c != EOF)
		{
			printf("%c", c);
			c = getc(p);
		}
		printf("\n");
		fclose(p);
	}
	else
		printf("fail\n");
}