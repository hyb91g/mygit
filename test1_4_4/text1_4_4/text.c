//写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	// 返回 1的位数 
//}
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int a)
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
	
		
	return count ;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf_s("%d", &a);
	b = count_one_bits(a);
	printf("%d\n",b);
	system("pause");
	return 0;
}