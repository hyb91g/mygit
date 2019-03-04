//����ģʽ
//�ŵ㣺 ��һ��ʹ��ʵ������ʱ����������
//ȱ�㣺 ����

#include <iostream>
#include <mutex>
#include <thread>
using namespace std;

class Singleton
{
public:
	static Singleton* GetInstance()  //��ȡʵ��
	{
		if (_spInstance == nullptr)  //˫���(Double-Check),��֤Ч�ʺ��̰߳�ȫ
									 //�ڶ����Ժ���̲߳��ü���������Ч��
		{
			_smtx.lock();            //�����̣߳���һ���߳̽��������еĵڶ����߳̽�����

			if (_spInstance == nullptr)
			{
				_spInstance = new Singleton;
			}

			_smtx.unlock();
		}

		return _spInstance;
	}

	// ʵ��һ����Ƕ����������     
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

	~Singleton()     //��CGarbo�������
	{
		cout << "~Singleton()" << endl;
	}

	//������
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

	static Singleton* _spInstance;  //��������ָ��
	static mutex _smtx;             //������

	
};

Singleton* Singleton::_spInstance = nullptr;
mutex Singleton::_smtx;

Singleton::CGarbo Singleton::_scg;

//���Զ��߳�
void func()
{
	//Singleton::GetInstance();                 //�����������ᶪ����һ���̵߳ķ���ֵ
	cout << Singleton::GetInstance() << endl;   //����һ��
}

int main()
{
	//���̣߳������̲߳���ȥ��func����
	thread t1(func); 
	thread t2(func);

	//�̵߳ȴ�
	t1.join();  
	t2.join();

	cout << Singleton::GetInstance() << endl;
	cout << Singleton::GetInstance() << endl;


	return 0;
}