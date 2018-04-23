#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996);
struct student
{
	char name[20];
	int age;
	int sex;
};
void swap_str(char *a, char *b)
{
	char tmp[20];
	strcpy(tmp, a);
	strcpy(a, b);
	strcpy(b, tmp);
}
void swap_int(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
int main()
{
	struct student st[3] = { {"张三", 21, 1}, {"李四", 20, 1}, {"王五", 22, 1} };
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 1; j < 3 - i; j++)
		{
			if (st[j - 1].age > st[j].age)
			{
				swap_str(st[j - 1].name, st[j].name);
				swap_int(&st[j - 1].age, &st[j].age);
			}
		}
	}
	for (i = 0; i < 3; i++)
	{
		printf("%s, %d\n", st[i].name, st[i].age);
	}
	return 0;
}