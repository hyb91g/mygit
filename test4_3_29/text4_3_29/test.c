//编写一个程序，它从标准输入读取C源代码，并验证所有的花括号都正确的成对出现。


#include<stdio.h>
#include<stdlib.h>
int main()
{
	int count = 0;
	int ch;
	while ((ch = getchar()) != EOF)
	{
		if (ch == '{')
			count++;
		if (ch == '}' && count == 0)
		{
			printf("不匹配\n");
			return 0;
		}
		if (ch == '}' && count != 0)
		count--;
	}
	
	if (count == 0)
		printf("匹配\n");
	else
		printf("不匹配\n");
	system("puase");
	return 0;
}