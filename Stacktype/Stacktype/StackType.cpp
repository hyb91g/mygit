//�����һ���࣬����ֻ����ջ�ϴ�������

#include<iostream>
using namespace std;

class StackType
{
public:
	static StackType CreateObject()
	{
		//return StackType();  �������죺��������Ϊ��һ��

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