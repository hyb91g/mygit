//��дһ�����򣬿���һֱ���ռ����ַ��������Сд�ַ��������Ӧ�Ĵ�д�ַ���������յ��Ǵ�д�ַ����������Ӧ��Сд�ַ�����������ֲ������
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
int main()
{
	while (1)
	{
		char ch;
		scanf(" %c", &ch);
		if (ch >= 'a' && ch <= 'z')
		{
			ch = ch - 32;
			printf("%c\n", ch);
		}
		else if (ch >= 'A' && ch <= 'Z')
		{
			ch = ch + 32;
			printf("%c\n", ch);
		}
		else
		{
			printf("�������\n");
		}
	}
	system("pause");
	return 0;
}