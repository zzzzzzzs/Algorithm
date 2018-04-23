#include<stdio.h>
int main(int argc, char **args)
{
	if (argc < 2)
		return 0;
	FILE *p = fopen(args[1], "r");
	if (p)
	{
		char c = getc(p);
		while (c != EOF)
		{
			printf("%c", c);
			c = getc(p);
		}
		fclose(p);
	}
	else
	{
		printf("fail\n");
	}
	return 0;
}