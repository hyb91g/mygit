//lambda表达式书写格式： [capture - list](parameters) mutable -> return-type{ statement };

#include <iostream>
#include <algorithm>
using namespace std;

struct Goods {
	const char * name;
	int price;
};

class Rate
{
private:
	double _rate;
public:
	Rate(double rate)
		:_rate(rate)
	{}

	double operator()(int year, double money)
	{
		return year * money*_rate;
	}
};

int main()
{
	Goods list[] = { {"苹果", 5}, {"梨",2}, {"香蕉", 8}, {"西瓜", 3}, {"火龙果", 10} };
	sort(list, list + sizeof(list) / sizeof(list[0]),[](const Goods& g1, const Goods& g2)
														{
															return g1.price <= g2.price;
														});

	//lambda表达式实际上可以理解为无名函数，该函数无法直接调用，如果想要直接调用，可借助auto将其赋值给一个变量。
	//[var]：表示值传递方式捕捉变量var
	//[=]：表示值传递方式捕获所有父作用域中的变量(包括this)
	//[&var]：表示引用传递捕捉变量var
	//[&]：表示引用传递捕捉所有父作用域中的变量(包括this)
	//[this]：表示值传递方式捕捉当前的this指针


	// 最简单的lambda表达式, 该lambda表达式没有任何意义
	[] {};

	// 省略参数列表和返回值类型，返回值类型由编译器推导为int
	int a = 1, b = 2;
	[=] {
		return a + 3;
	};
	// 省略了返回值类型，无返回值类型
	auto fun1 = [&](int c) {
		a = b + c;
	};
	fun1(10);
	cout << a << " " << b << endl; //12 2
	// 各部分都很完善的lambda函数
	auto fun2 = [=, &b](int d)mutable->int {return b = a - d; };
	cout << fun2(3) << endl;

	// 复制捕捉x
	int x = 10;
	auto add_x = [x](int e)mutable {x *= 2; return x + e; };
	cout << add_x(5) << endl;

	// lambda表达式之间不能相互赋值，即使看起来类型相同
	auto f1 = [] {cout << "hello world" << endl; };
	auto f2 = [] {cout << "hello world" << endl; };
	//f1 = f2; // 编译失败--->提示找不到operator=()

	// 允许使用一个lambda表达式拷贝构造一个新的副本
	auto f3(f1);
	f3();
	// 可以将lambda表达式赋值给相同类型的函数指针
	void(*PF)();
	PF = f2;
	PF();

	//函数对象与lambda表达式
	//函数对象，又称为仿函数，即可以想函数一样使用的对象，就是在类中重载了operator()运算符的类对象。
	//函数对象
	double rate = 0.49;
	Rate r(rate);
	cout << r(1, 21.35) << endl;
	//仿函数
	auto r1 = [rate](const int year, const double money)->double {return year * money*rate; };
	cout << r1(1, 21.35) << endl;
	//其实如果定义了一个lambda表达式，编译器会自动生成一个类，在该类中重载了operator()。
	
	return 0;
}