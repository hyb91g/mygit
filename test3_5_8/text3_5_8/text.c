//���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩

#include<stdio.h>
#include<stdlib.h>

int find_alone(int arr[], int sz)
{
	int i = 0;
	int ret = 0;
	for (i = 0; i < sz; i++)
	{
		ret ^= arr[i];
	}
	return ret;
}
int main()
{
	int arr[] = { 1,2,3,2,1 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int ret = find_alone(arr, sz);
	printf("%d\n", ret);
	system("pause");
	return 0;
}
	