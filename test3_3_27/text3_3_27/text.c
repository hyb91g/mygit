//编写程序数一下 1到 100 的所有整数中出现多少次数字9。

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0, a = 0;
	for(i = 0; i < 100; i++)
	{
		if(i % 10 == 9)
			a += 1;
		if(i / 10 == 9)
			a += 1;
	}
	printf("有%d个9\n",a);
	system("pause");
	return 0;
}