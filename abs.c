#include <stdio.h>

int abs_1(int p)
{
    return p>0?p:-p;
}

int abs_2(int i)
{
    if (i<0)
        return ~(--i);
    return i;
}

int abs_3(int i)
{
    return ((i >> 31) ^ i) - (i >> 31);
}

float abs_f1(float p)
{
	return p>0?p:-p;
}

/*
float abs_f2(float i)
{
	if(i<0)
		return ~(--i);
	return i;
}

float abs_f3(float i)
{
	return ((i >> 31) ^ i) - (i >> 31);
}
*/

int main()
{
	int 	a;
	int 	b;
	float 	c;
	float 	d;
	a = -1;
	c = 1.5;
	b = abs_1(a);
	d = abs_f1(c);
	printf("b = %d\n", b);
	printf("d = %f\n", d);
	return 0;
}