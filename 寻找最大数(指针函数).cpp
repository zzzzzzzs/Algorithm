//寻找最大的数
#include <iostream>
using namespace std;

int *max(int *array, int size)
{
	int *max = array;
	for(int i = 0; i < size; i++)
	{
		if(*max < array[i])
			*max = array[i];
	}
	return max;
}

int main()
{
	int array[] = {0, 23, 3, 1};
	cout << *max(array, sizeof(array) / sizeof(array[0])) << endl;
	return 0;
}