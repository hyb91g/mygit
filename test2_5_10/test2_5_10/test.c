//编写一个函数实现n^k，使用递归实现

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int Pow(int n, int k)
{
	if (k != 0)
	{
		return n * Pow(n, --k);
	}
	else
		return 1;
}
int main()
{
	int n = 0;
	int k = 0;
	int ret = 0;
	scanf_s("%d %d", &n, &k);
	ret = Pow(n, k);
	printf("%d\n", ret);
	system("pause");
	return 0;
}