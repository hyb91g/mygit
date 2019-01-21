//strncpy
#include<stdio.h>
#include<stdlib.h> 
#include<assert.h>
char* my_strncpy(char* dest, const char* src, size_t count)
{
	assert(dest != NULL);
	assert(src != NULL);
	char*ret = dest;
	while (count--)
	{
		if (*src != '\0')
		{
			*dest++ = *src++;
		}
		else
		{
			*dest++ = '\0';
		}
	}	
	return ret;
}
int main()
{
	char arr[20] = { 0 };
	my_strncpy(arr, "hello", 8);
	printf("%s\n", arr);
	system("pause");
	return 0;
}