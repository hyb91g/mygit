//��д������һ�� 1�� 100 �����������г��ֶ��ٴ�����9��

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
	printf("��%d��9\n",a);
	system("pause");
	return 0;
}