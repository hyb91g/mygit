#include <iostream>
using namespace std;

class A
{
public:
	int a;
};
class A1 : virtual public A   //����̳�
{
public:
	int a1;
};
class A2 : virtual public A
{
public:
	int a2;
};
class B : public A1, public A2
{
public:
	int b;
};

int main()
{
	//B b;
	// //�������ж������޷���ȷ֪�����ʵ�����һ��
	//b.a = 1;
	// //��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
	//b.A1::a = 1;
	//b.A2::a = 2;

	B b;
	b.A1::a = 1;
	b.A2::a = 2;
	b.a1 = 3;
	b.a2 = 4;
	b.b = 5;

	return 0;
}