#include<stdio.h>
#include<Windows.h>
int main()
{
	int x = 0, y = 0;
	
	while(1)
	{
		if(x < 966) x += 10;
		if(x >= 966) x -=10;//{x -= 10; y += 10};
		//if(y > 368) {y} 
		
		SetWindowPos((HWND)0x000A0818, NULL, x, y, 400, 400, 0);
		Sleep(50);	
	}
	return 0;
} 