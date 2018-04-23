#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T>
void quicksort(T *buf, T left, T right)
{
	T l, r, k, tmp;
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
	cout<<"Please enter the number to compare: ";
	cin>>n;
	cout<<"Please enter "<< n <<" integers: "<<endl;
	for (i = 0; i < n; i++)
	{
		cin>>a[i];
	}
	quicksort(a, 0, n - 1);
	cout<<"-----------------------------"<<endl;
	cout<<"After an integer:"<<endl;
	for (i = 0; i < n; i++)
	{
		cout<<a[i]<<endl;
	}
	system("pause");
	return 0;
}