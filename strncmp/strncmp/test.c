//strncmp

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int my_strncmp(const char* str1, const char* str2, size_t count)
{
	assert(str1);
	assert(str2);
	while (count--)
	{
		if (*str1 == *str2)
		{
			if (*str1 == "\0")
			{
				return 0;
			}
			str1++;
			str2++;
		}
		else
		{
			return *str1 - *str2;
		}
	}
}
int main()
{
	char *p = "abcdef";  
    char *q = "abcawafg";  
    int ret = my_strncmp(p, q, 5);  
    if (ret > 0)  
        printf("p大\n");  
    else if (ret < 0)  
        printf("q大\n");  
    else  
        printf("一样大\n");  
	system("pause");
	return 0;
}