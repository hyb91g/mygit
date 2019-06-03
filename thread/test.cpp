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
	//1����
	//for (size_t i = 0; i < num; i++)
	//{
	//	m.lock();
	//	n++;
	//	m.unlock();
	//}
	//2��ԭ�ӿ�
	for (size_t i = 0; i < num; i++)
	{
		n++;  //ԭ�ӵ�
	}
}

int main()
{
	//thread t(fun);
	//t.join();
	//cout << "Main thread!" << endl;

	//// ʹ��lambda���ʽ��Ϊ�̺߳��������߳�
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

	////�̰߳�ȫ��ԭ����
	////1������    ȱ�㣺Ӱ��Ч�ʣ����в�������������
	////2��ԭ�ӿ�
	//thread t1(Add, 1000000);
	//thread t2(Add, 1000000);
	//t1.join();
	//t2.join();
	//cout << "n = " << n << endl;
	
	//ͨ��lambda���ʽ�����߳�
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

