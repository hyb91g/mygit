//�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 �� AABCD��s2 = BCDAA������1������s1 = abcd��s2 = ACBD������0.
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//AABCD����һ���ַ��õ�DAABC

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int is_left_move(char *arr, const char *p)
{
	if (strlen(arr) != strlen(p))
	{
		return 0;
	}
	strncat(arr, arr, strlen(arr));
	if (strstr(arr, p) != NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	char arr[20] = "abcdef";
	char *p = "cdefab";
	int ret = is_left_move(arr, p);
	if (ret == 0)
	{
		printf("����\n");
	}
	else
	{
		printf("��\n");
	}
	system("pause");
	return 0;
}