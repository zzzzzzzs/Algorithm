// 消抖滤波法
//需要大于12次才有效果
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //用到了time函数 

int Filter_Value;
int Value;

#define FILTER_N 12
char i = 0;
int Filter(int number) 
{
	int new_value;
	new_value = number;
	if(Value != new_value) 
	{
		i++;
		if(i > FILTER_N) 
		{
		  i = 0;
		  Value = new_value;
		}
	}
	else
		i = 0;
	return Value;
}

int main()
{  
	Value = 10;
	int j, number;
	srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样
	for(j = 0; j < 15; j++)
	{
		number = rand() % 101;
		printf("%d\n", number);
		number = Filter(number);
		printf("%d\n", number);	
	}
   	return 0;
}



