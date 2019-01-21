//实现strstr

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

char* my_strstr(const char*str, const char*substr)
{
	assert(str != NULL);
	assert(substr != NULL);
	const char *s1;
	const char *s2;
	const char *cur = str;
	if (*substr == '\0')
	{
		return (char *)str;
	}
	while (*cur)
	{
		s1 = cur;
		s2 = substr;
		while (*s1 && *s2 && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char *)cur;
		}
		if (*s1 == '\0')
		{
			return NULL;
		}
		cur++;
	}
	return NULL;
}

int main()
{
	const char *p = "abcdefghig";
	const char *q = "cdef";

	char *ret = my_strstr(p, q);
	if (ret == NULL)
	{
		printf("不存在\n");
	}
	else
	{
		printf("%s\n", ret);
	}
	system("pause");
	return 0;
}