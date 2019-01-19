//编写一个函数reverse_string(char * string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。

#include<stdio.h>
#include<stdlib.h>

int my_strlen(char*str)
{
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}
void reverse_str(char*left, char*right)
{
	char tmp = 0;
	tmp = *left;
	*left = *right;
	*right = tmp;
	left++;
	right--;
	if (left < right)
	{
		reverse_str(left, right);
	}
}
void reverse(char* str)
{
	char*left = str;
	char*right = str + my_strlen(str) - 1;
	reverse_str(left, right);
}
int main()
{
	char arr[] = "abcdefg";
	reverse(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}