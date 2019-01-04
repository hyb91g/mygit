//判断一个字符串是否为另外一个字符串旋转之后的字符串。
//例如：给定s1 ＝ AABCD和s2 = BCDAA，返回1，给定s1 = abcd和s2 = ACBD，返回0.
//AABCD左旋一个字符得到ABCDA
//AABCD左旋两个字符得到BCDAA
//AABCD右旋一个字符得到DAABC

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
		printf("不是\n");
	}
	else
	{
		printf("是\n");
	}
	system("pause");
	return 0;
}