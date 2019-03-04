//懒汉模式
//优点： 第一次使用实例对象时，创建对象
//缺点： 复杂

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()  //获取实例
	{
		if (_spInstance == nullptr)  //双检查(Double-Check),保证效率和线程安全
									 //第二个以后的线程不用检查锁，提高效率
		{
			_smtx.lock();            //（多线程）第一个线程进来，并行的第二个线程进不来

			if (_spInstance == nullptr)
			{
				_spInstance = new Singleton;
			}

			_smtx.unlock();
		}

		return _spInstance;
	}

	// 实现一个内嵌垃圾回收类     
	class CGarbo
	{
	public:
		~CGarbo() {
			if (_spInstance)
			{
				cout << "1" << endl;
				delete _spInstance;
			}
		}
	};
	static CGarbo _scg;
private:
	Singleton()
	{
		cout << "Singleton()" << endl;
	}

	~Singleton()     //调CGarbo类的析构
	{
		cout << "~Singleton()" << endl;
	}

	//防拷贝
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton* _spInstance;  //单例对象指针
	static mutex _smtx;             //互斥锁

	
};

Singleton* Singleton::_spInstance = nullptr;
mutex Singleton::_smtx;

Singleton::CGarbo Singleton::_scg;

//测试多线程
void func()
{
	//Singleton::GetInstance();                 //若不加锁，会丢掉第一个线程的返回值
	cout << Singleton::GetInstance() << endl;   //测试一下
}

int main()
{
	//多线程，两个线程并行去调func函数
	thread t1(func); 
	thread t2(func);

	//线程等待
	t1.join();  
	t2.join();

	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;


	return 0;
}