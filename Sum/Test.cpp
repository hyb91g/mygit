//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
#include<iostream>
using namespace std;

class Sum {
public:
	Sum() {
		sum += i;
		i++;
	}
	static int i;
	static int sum;
};

int Sum::i = 1;
int Sum::sum = 0;

int main()
{
	Sum a[5];
	cout << Sum::sum << endl;
	return 0;
}