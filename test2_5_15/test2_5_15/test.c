//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水。编程实现。

#include<stdio.h>
#include<stdlib.h>

int Sum(int a)
{
	static int count = 0;

	if (a * 2 + count < 2)
	{

		return 0;
	}
	if ((a % 2) == 0)
	{
		return a + Sum(a / 2);
	}
	if ((a % 2) == 1 && count == 0)
	{
		count = 1;
		return a + Sum(a / 2);
	}
	if ((a % 2) == 1 && count == 1)
	{
		count = 0;
		return a + Sum(a / 2 + 1);
	}
}
int main()
{
	int a = 20;
	int ret = Sum(a);
	printf("%d\n", ret);
	system("pause");
	return 0;
}