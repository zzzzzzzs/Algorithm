//从大到小排列
#include <stdio.h>
#pragma warning(disable:4996)
void bubble(int *a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
			{
				int tmp = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tmp;
			}
		}
	}
}
int main()
{
	int a[1024] = { 0 };
	int i, n;
	printf("请输入需要比较的个数:");
	scanf("%d", &n);
	printf("请输入%d个整数:\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	bubble(a, n);
	printf("-----------------------\n");
	printf("整理后为:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\n", a[i]);
	}
	system("pause");
	return 0;
}
