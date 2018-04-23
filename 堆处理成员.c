#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
struct man
{
	char *name;
	int age;
	int classid;
};
int main()
{
	struct man *p = NULL;
	int i = 1;
	while (1)
	{
		printf("第%d个人\n", i);
		printf("please input name:");
		char tmp[1024] = { 0 };
		scanf("%s", tmp);
		if (strcmp(tmp, "exit") == 0)
			break;
		p = realloc(p, sizeof(struct man) * i);
		p[i - 1].name = malloc(strlen(tmp) + 1);
		strcpy(p[i - 1].name, tmp);
		printf("please input age:");
		scanf("%d", &p[i - 1].age);
		printf("please input classid:");
		scanf("%d", &p[i - 1].classid);
		i++;
		printf("--------------------------------\n");
	}
	int a;
	for (a = 0; a < i - 1; a++)
	{
		printf("%s, %d, %d\n", p[a].name, p[a].age, p[a].classid);
	}
	for (a = 0; a < i - 1; a++)
	{
		free(p[a].name);
	}
	free(p);
	return 0;
}