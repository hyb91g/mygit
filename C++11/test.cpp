#include "initializer_list.h"
#include "RightReference.h"

void* S(int i){
	return malloc(i);
}

String GetString(const char* pStr)
{
	String strTemp(pStr);
	return strTemp;
}
/*tring&& GetString(const char* pStr)
{
	String strTemp(pStr);
	return strTemp;
}*/

void Fun(int &x) { cout << "lvalue ref" << endl; }
void Fun(int &&x) { cout << "rvalue ref" << endl; }
void Fun(const int &x) { cout << "const lvalue ref" << endl; }
void Fun(const int &&x) { cout << "const rvalue ref" << endl; }
template<typename T>
void PerfectForward(T &&t)
{ 
	Fun(forward<T>(t));
}

int main()
{
	////列表初始化
	//Vector<int> v1{ 1,2,3,4,5 };
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << v1[i] << " ";
	//}
	//cout << endl;

	//Vector<int> v2 = { 6,7,8,9,10 };
	//for (auto e : v2)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	////decltype类型推演
	//int a = 1, b = 2;
	//decltype(a + b) c;
	//cout << typeid(c).name() << endl;
	////对于函数
	//cout << typeid(decltype(S)).name() << endl;   //不带参：推倒函数的类型
	//cout << typeid(decltype(S(1))).name() << endl;//带参：推倒函数返回值类型（不会执行函数，只是推演）

	////右值引用
	//String s1("hello");
	//String&& s2 = GetString("world");
	//String s3(move(s1)); //s1是左值，右值引用不能引用左值，move将一个左值强制转换成右值引用
	//                     //但这是move()误用的一个非常典型的例子，move更多的是用在声明周期即将结束的对象上

	//完美转发
	PerfectForward(10); // rvalue ref
	int a;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref
	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref
	return 0;
}