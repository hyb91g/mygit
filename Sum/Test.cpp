//��1+2+3+...+n��Ҫ����ʹ�ó˳�����for��while��if��else��switch��case�ȹؼ��ּ������ж���䣨A?B:C����
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