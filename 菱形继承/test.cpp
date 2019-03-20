#include <iostream>
using namespace std;

class A
{
public:
	int a;
};
class A1 : virtual public A   //虚拟继承
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
	// //这样会有二义性无法明确知道访问的是哪一个
	//b.a = 1;
	// //显示指定访问哪个父类的成员可以解决二义性问题，但是数据冗余问题无法解决
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