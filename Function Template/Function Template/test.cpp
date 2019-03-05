#include <iostream>
using namespace std;
template<class T> 
T Add(const T& left, const T& right) 
{ 
	return left + right; 
}

int main()
{
	int a1 = 10, a2 = 20; 
	double d1 = 10.1, d2 = 20.0;  
	cout << Add(a1, a2) << endl;
	cout << Add(d1, d2) << endl;

	//Add(a1, d1);   该语句不能通过编译

	// 此时有两种处理方式：1. 用户自己来强制转化 2. 使用显式实例化   
	cout << Add(a1, (int)d1) << endl;
	cout << Add<double>(a1, d1) << endl;

	return 0;
}


//template<typename T>
//void Swap(T &a, T &b)
//{
//	T c = a;
//	a = b;
//	b = c;
//}
//int main()
//{
//	int a = 5, b = 7;
//	Swap(a, b);
//	cout << a << " " << b << endl;
//	return 0;
//}