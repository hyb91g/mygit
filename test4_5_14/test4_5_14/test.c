//ģ��ʵ��printf���������������Ĺ���
// 
//��������溯���ĵ��á� 
//print("s ccc d.\n","hello",'b','i','t'��100); 
//����ԭ�ͣ� 
//print(char *format, ...) 

#include<stdio.h>
#include<stdlib.h>
#include<stdarg.h>
void print(char *tmp, ...)  
{
	va_list arg;       
	va_start(arg, tmp); 
	while (*tmp != '\0')
	{
		if (*tmp == 'c')
		{
			putchar(va_arg(arg, char));
		}
		else if (*tmp == 's')
		{
			puts(va_arg(arg, char*));
		}
		else if (*tmp == 'd')
		{
			int d = va_arg(arg, int);
			printf("%d\n", d);
		}
		tmp++;
	}
	va_end(arg);     
}
int main()
{
	print("s ccc d.\n", "hello", 'b', 'i', 't', 100);
	system("pause");
	return 0;
}