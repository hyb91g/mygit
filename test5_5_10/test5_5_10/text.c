//递归和非递归分别实现strlen

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//非递归：
//int my_strlen(char*str)
//{
//	assert(str != NULL);
//	int count = 0;
//	while (*str)
//	{
//		count++;
//		str++;
//	}
//	return count;
//}
//递归：
int my_strlen(char*str)
{
	assert(str != NULL);
	int count = 1;
	if (*str)
	{
		return count + my_strlen(str + 1);
	}
	else
		return 0;
}
int main()
{
	char arr[] = "abcdefg";
	int ret = my_strlen(arr);
	printf("%d\n", ret);
	system("pause");
	return 0;
}