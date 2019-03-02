//请设计一个类，该类只能在栈上创建对象

#include<iostream>
using namespace std;

class StackType
{
public:
	static StackType CreateObject()
	{
		//return StackType();  匿名构造：生命周期为这一行

		StackType obj;
		return obj;
	}
	void Print()
	{
		cout << "StackType CreateObject" << endl;
	}
private:
	StackType()
	{}
};

int main()
{
	StackType::CreateObject().Print();
	StackType obj = StackType::CreateObject();
	obj.Print();
	//StackType obj2 = new StackType;
	return 0;
}