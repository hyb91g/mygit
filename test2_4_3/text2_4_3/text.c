//д����������������������в�����Ҫ�����֣��ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int a;
	int mid = 0;
	printf("����������Ҫ�ҵ�����:");
	scanf_s("%d", &a);
	while (right >= left)
	{
		mid = left + (right - left) / 2;
		if (a > arr[mid])
		{
			left = mid + 1;
		}
		else if (a < arr[mid])
		{
			right = mid - 1;
		}
		else
		{
			printf("�ҵ��ˣ��±���%d\n", mid);
			break;
		}
	}
	if (right < left)
	{
		printf("-1\n");
	}
	system("pause");
	return 0;
}