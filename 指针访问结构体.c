#include<stdio.h>
struct student
{
	char name[20];
	int age;
	int sex;
};
int main()
{
	struct student st = {0};
	struct student *p;
	p = &st;
	p->age = 10;
	printf("%d\n", st.age);
	return 0;
}