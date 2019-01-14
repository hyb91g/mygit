//不使用（a + b） / 2这种方式，求两个数的平均值。

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 10;
	int b = 20;
	int average = (a&b) + ((a^b) >> 1);
	//int average = a + ((b-a)>>1);
	printf("%d\n", average);

	system("pause");
	return 0;
}