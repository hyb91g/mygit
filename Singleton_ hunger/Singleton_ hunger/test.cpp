//饿汉模式
//优点： 简单
//缺点： 可能会导致启动慢

#include <iostream>
using namespace std;

class Singleton
{
public:
	//static Singleton& GetInstance()  //获取实例
	//{
	//	return _sInstance;
	//}
	static Singleton* GetInstance()  //获取实例
	{
		return &_sInstance;
	}
private:
	Singleton() 
	{}
	
	//防拷贝
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