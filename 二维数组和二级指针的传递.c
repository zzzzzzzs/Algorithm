#include <stdio.h>
#include <stdlib.h>

void tmp1(int aa[])
{
    for(int i = 0; i < 6; i++)
    	aa[i] = i;
}

void tmp2(int (*bb)[2])
{
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 2; j++)
			bb[i][j] = i + 10;
}

int main()
{
	int i, j;
    int aa[3][2] = { 0 };
    int bb[3][2] = { 0 };
    tmp1(*aa);
    tmp2(bb);
    for(i = 0; i <3; i++)
    	for( j = 0; j < 2; j++)
    		printf("aa[%d][%d] = %d\n", i, j, aa[i][j]);
   	printf("----------------------------------\n");
    for(i = 0; i < 3; i++)
    	for(j = 0; j < 2; j++)
    		printf("bb[%d][%d] = %d\n", i, j, bb[i][j]);
    system("pause");
    return 0;
}
