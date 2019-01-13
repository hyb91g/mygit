//实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//void swap_arr(char arr[], int sz, int k)
//{
//	int arr1[4] = { 0 };
//	int i = 0;
//	int j = 0;
//	int a = 0;
//	for (i = 0; i < k; i++)
//	{
//		arr1[i] = arr[i];
//	}
//	for (i = k; i < sz - 1; i++)
//	{
//		if (j <= sz - k - 2)
//		{
//			arr[j] = arr[i];
//		}
//		j++;
//	}
//	for (i = sz - k - 1; i < sz - 1; i++)
//	{
//		
//		arr[i] = arr1[a];
//		a++;
//	}
//}
//int main()
//{
//	char arr[] = "ABCD";
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	printf("左旋字符数：");
//	scanf_s("%d", &k);
//	swap_arr(arr, sz, k);
//	printf("%s", arr);
//	system("pause");
//	return 0;
//}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
void reverse(char *left, char *right)
{
	int tmp = 0;
	while (left < right)
	{
		tmp = *left;
		*left = *right;
		*right = tmp;
		*left++;
		*right--;
	}

}
void left_move(char *str, int k)
{
	int len = strlen(str);
	reverse(str, str + k - 1);
	reverse(str + k, str+len-1);
	reverse(str, str + len - 1);


	//char tmp = 0;
	//int len = strlen(str);
	//
	//while (k--)
	//{
	//	char *cur = str;
	//	tmp = *cur;
	//	while (*(cur + 1) != '\0')
	//	{
	//		*cur = *(cur + 1);
	//		*cur++;
	//	}
	//	*cur = tmp;
	//}
}
int main()
{
	char arr[] = "abcdef";
	int k = 0;
	scanf_s("%d", &k);
	left_move(arr, k);
	printf("%s\n", arr);
	system("pause");
	return 0;
}