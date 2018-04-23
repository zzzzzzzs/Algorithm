#include<stdio.h>
int main()
{
	char a[2][5] = { {10, 2, 15, 16, 81}, {30, 15, 84, 76, 49} };
	char *p = (char *)a;
	int i, j;
	for (i = 0; i < 10; i++)
	{
		for (j = 1; j < 10 - i; j++)
		{
			if (p[j] < p[j - 1])
			{
				char tmp = p[j];
				p[j] = p[j - 1];
				p[j - 1] = tmp;
			}
		}
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 5; j++)
		{
			printf("%d\n", a[i][j]);
		}
	}
	return 0;
}