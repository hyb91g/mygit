//��һ���ַ����������Ϊ:"student a am i", ���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int my_strlen(const char* str)
{
	assert(str != NULL);
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}
void reverse_str(char*left, char*right)
{
	assert(left != NULL); 
	assert(right != NULL);
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void reverse(char *str)
{
	assert(str != NULL);
	char*cur = str;
	char*left = str;
	char*right = str + my_strlen(str) - 1;
	reverse_str(left, right);
	while (*cur)
	{
		char *start = cur;
		while ((*cur != ' ') && (*cur != '\0'))
		{
			cur++;
		}
		reverse_str(start, cur - 1);
		if(*cur == ' ')
			cur++ ;
	}

}
int main()
{
	char arr[] = "student a am i";
	reverse(arr);
	printf("%s\n", arr);
	system("pause");
	return 0;
}