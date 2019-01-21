//实现strcmp

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int my_strcmp(const char*str1, const char*str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	
	while(*str1 == *str2)
	{
		if(*str1 == "\0")
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
int main()
{
	char *p = "abcdef";
	char *q = "abcawafg";
	int ret = my_strcmp(p, q);
	if (ret > 0)
		printf("p大\n");
	else if (ret < 0)
		printf("q大\n");
	else
		printf("一样大\n");

	system("pause");
	return 0;
}