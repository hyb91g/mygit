//杨氏矩阵
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);

#include<stdio.h>
#include<stdlib.h>

struct Point
{
	int i;
	int j;
};
struct Point find(int arr[3][3], int row, int col, int key)
{
	int i = 0;
	int j = col - 1;
	struct Point ret = { -1,-1 };
	while ((i < 3) && (j >= 0))
	{
		if (arr[i][j] < key)
		{
			i++;
		}
		else if (arr[i][j] > key)
		{
			j--;
		}
		else
		{
			ret.i = i;
			ret.j = j;
			return ret;
		}
	}
	return ret;
}
int main()
{
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	struct Point ret = find(arr, 3, 3, 7);
	if ((ret.i != -1)&&(ret.j != -1))
	{
		printf("找到了，下标是：%d  %d\n",ret.i,ret.j);
	}
	else 
	{
		printf("没找到\n");
	}

	system("pause");
	return 0;
}