//��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��

#include<stdio.h>
#include<stdlib.h>

int main()
{
	int a = 10;
	int b = 20;
	int average = (a&b) + ((a^b) >> 1);
	//int average = a + ((b-a)>>1);
	printf("%d\n", average);

	system("pause");
	return 0;
}