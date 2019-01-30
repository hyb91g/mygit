//练习使用qsort函数

//void qsort(void *base, size_t num, size_t width, int(__cdecl *compare);
//第一个参数 base 是需要排序的目标数组名（或者也可以理解成开始排序的地址，因为可以写&s[i]这样的表达式）
//第二个参数 num 是 参与排序的目标数组元素个数
//第三个参数 width 是单个元素的大小（或者目标数组中每一个元素长度），推荐使用sizeof(s[0]）这样的表达式
//第四个参数 compare 就是让很多人觉得非常困惑的比较函数
//int compare(const void *elem1, const void *elem2));
//返回值必须是int，两个参数的类型必须都是const void *。

//#include<stdio.h>
//#include<stdlib.h>
//
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int *)e1 - *(int *)e2;
//}
//int main()
//{
//	int arr[10] = { 2,4,6,8,0,1,3,5,7,9 };
//  int sz = sizeof(arr) / sizeof(arr[0]);
//	qsort(arr, sz, sizeof(arr[0]), cmp_int);
//	system("pause");
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
int main()
{
	struct S arr[] = { {"zhangsan", 35},{"lisi", 21},{"wangwu", 15} };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_s_age);
	system("pause");
	return 0;
}