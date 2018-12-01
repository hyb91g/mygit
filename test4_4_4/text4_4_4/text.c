//编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7

#include<stdio.h>
#include<stdlib.h>

int count_one_bits(int a)
{

	int count = 0;
	while (a > 0)
	{
		if (a % 2 == 1)
		{
			count++;
			a = a / 2;
		}
		if (a % 2 == 0)
		{
			a = a / 2;
		}
	}


	return count;
}

int main()
{
	int a = 0;
	int b = 0;
	int i = 0;
	int j = 0;
	scanf_s("%d %d", &i,&j);

	a = i ^ j;
	
	b = count_one_bits(a);
	printf("%d\n", b);
	system("pause");
	return 0;
}

