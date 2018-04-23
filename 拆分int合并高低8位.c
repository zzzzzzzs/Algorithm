
#include <stdio.h>

int main()
{	
	int 	a  = 10000;
	int		b;
	char 	tmp_buf[2]; 
	//将int型数拆分成高8位和低8位
	tmp_buf[0] = (a >> 8) & 0xff;
	tmp_buf[1] =  a & 0xff;
	printf("tmp_buf[0] = %d\n", tmp_buf[0]);
	printf("tmp_buf[1] = %d\n", tmp_buf[1]);

	//将高8位和低8位合并成int型
	b = tmp_buf[0] << 8 | tmp_buf[1];
	printf("b = %d\n", b);
	return 0;
}