//ÊµÏÖstrchr

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char* my_strchr(const char* str, int c)
{
	assert(str != NULL);
	//char* ret = (char*)str;
	while (*str && *str != (char)c)
	{
		str++;
	}
	if (*str == (char)c)
	{
		return (char*)str;
	}
	return NULL;
}

int main()
{
	char arr[] = "abcdef";
	char* ret = my_strchr(arr, 'f');
	printf("%s\n", ret);
	system("pause");
	return 0;
}