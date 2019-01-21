// µœ÷memmove

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void* my_memmove(void* dest, const void* src, size_t count)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	if (src < dest)
	{
		while (count--)
		{
			*((char*)dest + count) = *((char*)src + count);
		}
	}
	else
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	return ret;
}

void Printf(int arr[], int sz)
{

	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d  ", arr[i]);
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	my_memmove(arr + 3, arr + 5, 16);
	Printf(arr, sz);
	system("pause");
	return 0;
}