//5.求两个数的最大公约数。

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 0, b = 0;
	printf("输入两个数：");
	scanf_s("%d %d", &a, &b);
	
	int min = 0, max = 0;
	min = a > b ? b : a;
	max = a > b ? a : b;

	int i = 0;
	for (i = min ; i > 0; i--)
	{
		if (min%i == 0 && max%i == 0)
			break;
	}
	printf("最大公约数：%d\n", i);
	system("pause");
	return 0;
}