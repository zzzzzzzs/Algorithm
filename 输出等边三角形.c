#include <stdio.h>
int main()
{
	int a, b, c;
	int n;
	scanf("%d", &n);
	for(a = 0; a < n; a++)
	{
		for(c = 0; c < n - a; c++)
		{
			printf(" ");
		}
		for(b = 0; b < a * 2 -1; b++)
		{
			printf("*" );
		}
		printf("\n");
	}
}