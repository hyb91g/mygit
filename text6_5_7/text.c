//使用宏实现两个数中求较大值。

#include<stdio.h>
#include<stdlib.h>

#define MAX(m, n) ((m)>(n)?(m):(n))
int main()
{
	int a = 10;
	int b = 5;
	int max = MAX(a, b);
	printf("%d\n", max);
	system("pause");
	return 0;
}