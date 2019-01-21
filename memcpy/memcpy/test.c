// µœ÷memcpy 

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

void* my_memcpy(void* dest, const void* src, size_t count)
{
	void* ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (count--)
	{
		*(char*)dest = *(char*)src;
		dest = (char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}
void Printf(int arr1[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d  ", arr1[i]);
	}
}
int main()
{
	int arr1[10] = { 0 };
	int arr2[] = { 1,2,3,4,5 };
	my_memcpy(arr1, arr2, 20);
	Printf(arr1, 10);
	system("pause");
	return 0;
}