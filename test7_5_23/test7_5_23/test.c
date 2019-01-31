//模仿qsort的功能实现一个通用的冒泡排序。

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
struct S
{
	char name[20];
	int age;
};

int cmp_s_name(const void*e1, const void*e2)
{
	return strcmp(((struct S*)e1)->name, ((struct S*)e2)->name);
}
int cmp_s_age(const void*e1, const void*e2)
{
	return ((struct S*)e1)->age - ((struct S*)e2)->age;
}

void _swap(char*buff1, char*buff2, int width)
{
	assert(buff1);
	assert(buff2);
	while (width--)
	{
		char tmp = *buff1;
		*buff1 = *buff2;
		*buff2 = tmp;
		buff1++;
		buff2++;
	}
}
void bubble_sort(void* base, int sz, int width, int(*cmp)(const void*e1, const void*e2))
{
	int i = 0;
	int j = 0;
	assert(base);
	assert(cmp);
	for (i = 0; i < sz - 1; i++)
	{
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base+j*width, (char*)base+(j+1)*width) > 0)
			{
				_swap((char*)base + j * width, (char*)base + (j + 1)*width, width);
			}
		}
	}
}
int main()
{
	struct S arr[] = { { "zhangsan", 35 },{ "lisi", 21 },{ "wangwu", 15 } };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_s_name);
	system("pause");
	return 0;
}