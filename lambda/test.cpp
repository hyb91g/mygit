//lambda���ʽ��д��ʽ�� [capture - list](parameters) mutable -> return-type{ statement };

#include <iostream>
#include <algorithm>
using namespace std;

struct Goods {
	const char * name;
	int price;
};

class Rate
{
private:
	double _rate;
public:
	Rate(double rate)
		:_rate(rate)
	{}

	double operator()(int year, double money)
	{
		return year * money*_rate;
	}
};

int main()
{
	Goods list[] = { {"ƻ��", 5}, {"��",2}, {"�㽶", 8}, {"����", 3}, {"������", 10} };
	sort(list, list + sizeof(list) / sizeof(list[0]),[](const Goods& g1, const Goods& g2)
														{
															return g1.price <= g2.price;
														});

	//lambda���ʽʵ���Ͽ������Ϊ�����������ú����޷�ֱ�ӵ��ã������Ҫֱ�ӵ��ã��ɽ���auto���丳ֵ��һ��������
	//[var]����ʾֵ���ݷ�ʽ��׽����var
	//[=]����ʾֵ���ݷ�ʽ�������и��������еı���(����this)
	//[&var]����ʾ���ô��ݲ�׽����var
	//[&]����ʾ���ô��ݲ�׽���и��������еı���(����this)
	//[this]����ʾֵ���ݷ�ʽ��׽��ǰ��thisָ��


	// ��򵥵�lambda���ʽ, ��lambda���ʽû���κ�����
	[] {};

	// ʡ�Բ����б�ͷ���ֵ���ͣ�����ֵ�����ɱ������Ƶ�Ϊint
	int a = 1, b = 2;
	[=] {
		return a + 3;
	};
	// ʡ���˷���ֵ���ͣ��޷���ֵ����
	auto fun1 = [&](int c) {
		a = b + c;
	};
	fun1(10);
	cout << a << " " << b << endl; //12 2
	// �����ֶ������Ƶ�lambda����
	auto fun2 = [=, &b](int d)mutable->int {return b = a - d; };
	cout << fun2(3) << endl;

	// ���Ʋ�׽x
	int x = 10;
	auto add_x = [x](int e)mutable {x *= 2; return x + e; };
	cout << add_x(5) << endl;

	// lambda���ʽ֮�䲻���໥��ֵ����ʹ������������ͬ
	auto f1 = [] {cout << "hello world" << endl; };
	auto f2 = [] {cout << "hello world" << endl; };
	//f1 = f2; // ����ʧ��--->��ʾ�Ҳ���operator=()

	// ����ʹ��һ��lambda���ʽ��������һ���µĸ���
	auto f3(f1);
	f3();
	// ���Խ�lambda���ʽ��ֵ����ͬ���͵ĺ���ָ��
	void(*PF)();
	PF = f2;
	PF();

	//����������lambda���ʽ
	//���������ֳ�Ϊ�º������������뺯��һ��ʹ�õĶ��󣬾���������������operator()������������
	//��������
	double rate = 0.49;
	Rate r(rate);
	cout << r(1, 21.35) << endl;
	//�º���
	auto r1 = [rate](const int year, const double money)->double {return year * money*rate; };
	cout << r1(1, 21.35) << endl;
	//��ʵ���������һ��lambda���ʽ�����������Զ�����һ���࣬�ڸ�����������operator()��
	
	return 0;
}