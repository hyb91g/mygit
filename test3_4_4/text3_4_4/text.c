//输出一个整数的每一位。

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	printf("输入一个数:");
	scanf_s("%d", &i);
	while (i)
	{
		if (i < 0)
		{
			i = -i;
		}
		printf("%d\n", i % 10);
		i /= 10;
	}

	system("pause");
	return 0;
}