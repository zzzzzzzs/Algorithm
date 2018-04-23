#include <stdio.h>
#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b
int main()
{
  int a;
  a = MIN(10, 9);
  printf("%d\n", a);
  return 0;
}