//��ϰʹ��qsort����

//void qsort(void *base, size_t num, size_t width, int(__cdecl *compare);
//��һ������ base ����Ҫ�����Ŀ��������������Ҳ�������ɿ�ʼ����ĵ�ַ����Ϊ����д&s[i]�����ı��ʽ��
//�ڶ������� num �� ���������Ŀ������Ԫ�ظ���
//���������� width �ǵ���Ԫ�صĴ�С������Ŀ��������ÿһ��Ԫ�س��ȣ����Ƽ�ʹ��sizeof(s[0]�������ı��ʽ
//���ĸ����� compare �����úܶ��˾��÷ǳ�����ıȽϺ���
//int compare(const void *elem1, const void *elem2));
//����ֵ������int���������������ͱ��붼��const void *��

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