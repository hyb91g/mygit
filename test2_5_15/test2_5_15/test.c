//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Զ�����ˮ�����ʵ�֡�

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