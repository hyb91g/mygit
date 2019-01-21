//ÊµÏÖstrcat

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char* my_strcat(char* dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[20] = "abcdefg";
	const char arr2[5] = "hijk";
	my_strcat(arr1, arr2);
	printf("%s\n", arr1);
	system("pause");
	return 0;
}