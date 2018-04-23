#include <stdio.h>
typedef struct
{
	int a;
	int b;
} Student;

typedef struct
{
	int a;
	int b;
} Man;
int main()
{
	Student Stu;
	Man     man;
	Stu.a = 1;
	Stu.b = 2;
	man.a = 3;
	man.b = 4;
	printf("a = %d, b = %d\n", Stu.a, Stu.b);
	printf("c = %d, d = %d\n", man.a, man.b);
	return 0;
}