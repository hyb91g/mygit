//���Ͼ���
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);

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
		printf("�ҵ��ˣ��±��ǣ�%d  %d\n",ret.i,ret.j);
	}
	else 
	{
		printf("û�ҵ�\n");
	}

	system("pause");
	return 0;
}