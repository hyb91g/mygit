// µœ÷strcpy


//int mian()
//{
//	char a[20] = "abcde";
//	const char b[] = "sdsdfd";
//	printf("%s\n", strcpy(a, b));
//	system("pause");
//	return 0;
//}


#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

char* my_strcpy(char*dest, const char* src)
{
	char* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}

int main()
{
	char arr[20] = { 0 };
	my_strcpy(arr, "hello");
	printf("%s\n", arr);
	system("pause");
	return 0;
}