//.在屏幕上输出以下图案：
//      *
//     ***
//    *****
//   *******
//  *********
// ***********
//*************
// ***********
//  *********
//   *******
//    *****
//     ***
//      *




#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
int main()
{
	int len = 13;
	int i = 0;
	for (i = 0; i <= len / 2; i++)
	{
		int k = 0;
		for (k = 0; k < len / 2 - i; k++)
		{
			printf(" ");
		}
		int j = 0;
		for (j = 0; j < 2 * (i + 1) - 1; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i < len / 2; i++)
	{
		int k = 0;
		for (k = 0; k < i + 1; k++)
		{
			printf(" ");
		}
		int j = 0;
		for (j = 0; j < len - 2 - 2 * i; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
}

//int main()
//{
//	char arr1[] = "************";
//	char arr2[] = "             ";
//	int left = strlen(arr1) / 2 - 1;
//	int right = left + 2;
//	int i = 0;
//	for (i = 1; i <= 7; i++)
//	{
//		char arr1[] = "************";
//		
//		while (left >= 0)
//		{
//			arr1[left] = arr2[left];
//			arr1[right] = arr2[right];
//			left--;
//			right++;
//		}
//		for (int j = 0; j < 12; j++)
//			printf("%c", arr1[j]);
//		printf("\n");
//
//		left = strlen(arr1) / 2 - 1;
//		right = left + 2;
//		left = left - i;
//		right = right + i;	
//	}
//
//	left = 0;
//	right = strlen(arr1) - 1;
//	for (i = 1; i < 7; i++)
//	{
//		char arr1[] = "*************";
//		while (left < i)
//		{
//			arr1[left] = arr2[left];
//			arr1[right] = arr2[right];
//			left++;
//			right--;
//		}
//		for (int j = 0; j < 12; j++)
//			printf("%c", arr1[j]);
//		printf("\n");
//
//		left = 0;
//		right = strlen(arr1) - 1;
//	}
//	system("pause");
//	return 0;
//}
//

