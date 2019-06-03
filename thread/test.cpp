#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
using namespace std;

void fun()
{
	cout << "new thread!" << endl;
}

void foo()
{
	this_thread::sleep_for(chrono::seconds(1));
}

mutex m;
//unsigned long n = 0;
atomic_long n{ 0 };
void Add(size_t num)
{
	//1、锁
	//for (size_t i = 0; i < num; i++)
	//{
	//	m.lock();
	//	n++;
	//	m.unlock();
	//}
	//2、原子库
	for (size_t i = 0; i < num; i++)
	{
		n++;  //原子的
	}
}

int main()
{
	//thread t(fun);
	//t.join();
	//cout << "Main thread!" << endl;

	//// 使用lambda表达式作为线程函数创建线程
	//int n1 = 500;
	//int n2 = 600;
	//thread t1([&](int addnum) {n1 += addnum; n2 += addnum; }, 500);
	//t1.join();
	//cout << n1 << " " << n2 << endl;

	//thread t1(foo);
	//cout << "before join, joinable = " << t.joinable() << endl;
	//t1.join();
	//cout << "after join, joinable = " << t.joinable() << endl;
	//thread t2(foo);
	//cout << "before detach, joinable = " << t.joinable() << endl;
	//t2.detach();
	//cout << "after detach, joinable = " << t.joinable() << endl;

	////线程安全：原子性
	////1、加锁    缺点：影响效率，稍有不当容易死锁。
	////2、原子库
	//thread t1(Add, 1000000);
	//thread t2(Add, 1000000);
	//t1.join();
	//t2.join();
	//cout << "n = " << n << endl;
	
	//通过lambda表达式创建线程
	vector<thread> vthread;
	for (int i = 0; i < 5; i++)
	{
		vthread.push_back(thread([]() {cout << "new thread!" << endl; }));
	}
	for (auto& e : vthread)
	{
		e.join();
	}

	return 0;
}

