//计算1 / 1 - 1 / 2 + 1 / 3 - 1 / 4 + 1 / 5 …… + 1 / 99 - 1 / 100 的值。

#include<stdio.h>
#include<stdlib.h>
int main()
{
	float i = 0.0, j = 0.0, k = 0.0;
	for (i = 1; i < 100; i += 2)
		j = j + 1 / i;
	for (i = 2; i <= 100; i += 2)
		k = k + 1 / i;
	printf("值为%f\n", j - k);
	system("pause");
	return 0;
}