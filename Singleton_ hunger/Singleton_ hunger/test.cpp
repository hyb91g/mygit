//����ģʽ
//�ŵ㣺 ��
//ȱ�㣺 ���ܻᵼ��������

#include <iostream>
using namespace std;

class Singleton
{
public:
	//static Singleton& GetInstance()  //��ȡʵ��
	//{
	//	return _sInstance;
	//}
	static Singleton* GetInstance()  //��ȡʵ��
	{
		return &_sInstance;
	}
private:
	Singleton() 
	{}
	
	//������
	Singleton(const Singleton& )
	{}
	Singleton& operator=(const Singleton&)
	{}

	static Singleton _sInstance;
};

Singleton Singleton::_sInstance;


int main()
{
	//Singleton a;
	//Singleton copy(*Singleton::GetInstance());
	return 0;
}