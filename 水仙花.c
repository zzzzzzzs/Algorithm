#include <stdio.h>
int main()
{
	int i = 100;
	int a, b, c, n;
	while(i < 1000)
	{ 
		a = i / 100;
		b = i / 10 % 10;
		c = i % 10;
		n = a*a*a + b*b*b + c*c*c;
		if(i == n)
		{
			printf("%d\n", i);
		}
		i++;
	}
	return 0;
}