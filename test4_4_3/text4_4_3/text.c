//编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。
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
			printf("输入错误\n");
		}
	}
	system("pause");
	return 0;
}