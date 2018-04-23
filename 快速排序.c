#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

void quicksort(int *buf, int left, int right)
{
	int l, r, k, tmp;
	if (left > right)
		return;
	l = left;
	r = right;
	while (l != r)
	{
		while (buf[r] >= buf[left] && l < r)
			r--;
		while (buf[l] <= buf[left] && l < r)
			l++;
		if (l < r)
		{
			tmp = buf[l];
			buf[l] = buf[r];
			buf[r] = tmp;
		}
	}
	k = buf[left];
	buf[left] = buf[l];
	buf[l] = k;
	quicksort(buf, left, l - 1);
	quicksort(buf, l + 1, right);
}
int main()  
{
	int i, n;
	int a[1024] = { 0 };
	printf("Please enter the number to compare: ");
	scanf("%d", &n);
	printf("Please enter %d integers:\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	quicksort(a, 0, n - 1);
	printf("-----------------------------\n");
	printf("After an integer:\n");
	for (i = 0; i < n; i++)
	{
		printf("%d\n", a[i]);
	}
	system("pause");
	return 0;
}