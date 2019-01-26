//模拟实现printf函数，可完成下面的功能
// 
//能完成下面函数的调用。 
//print("s ccc d.\n","hello",'b','i','t'，100); 
//函数原型： 
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