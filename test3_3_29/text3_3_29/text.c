//求Sn = a + aa + aaa + aaaa + aaaaa的前5项之和，其中a是一个数字，例如：2 + 22 + 222 + 2222 + 22222


#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int i = 0;
	int sum = 0;
	int a;
	scanf_s("%d", &a);
	int b = 0;
	for (i = 0; i < 5; i++)
	{
		b += a * pow(10, i);
		sum += b;
	}
	printf("%d\n", sum);
	system("pause");
	return 0;
}