//strncat

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char* my_strncat(char* dest, const char* src, size_t count)
{
	assert(dest);
	assert(src);
	char* ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (count--)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return ret;
}
int main()
{
	char arr1[20] = "abcdefg\0dsad";
	const char arr2[5] = "hijk";
	my_strncat(arr1, arr2, 3);
	printf("%s\n", arr1);
	system("pause");
	return 0;
}