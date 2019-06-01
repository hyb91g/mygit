#include "initializer_list.h"
#include "RightReference.h"

void* S(int i){
	return malloc(i);
}

String GetString(const char* pStr)
{
	String strTemp(pStr);
	return strTemp;
}
/*tring&& GetString(const char* pStr)
{
	String strTemp(pStr);
	return strTemp;
}*/

void Fun(int &x) { cout << "lvalue ref" << endl; }
void Fun(int &&x) { cout << "rvalue ref" << endl; }
void Fun(const int &x) { cout << "const lvalue ref" << endl; }
void Fun(const int &&x) { cout << "const rvalue ref" << endl; }
template<typename T>
void PerfectForward(T &&t)
{ 
	Fun(forward<T>(t));
}

int main()
{
	////�б��ʼ��
	//Vector<int> v1{ 1,2,3,4,5 };
	//for (int i = 0; i < 5; i++)
	//{
	//	cout << v1[i] << " ";
	//}
	//cout << endl;

	//Vector<int> v2 = { 6,7,8,9,10 };
	//for (auto e : v2)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;

	////decltype��������
	//int a = 1, b = 2;
	//decltype(a + b) c;
	//cout << typeid(c).name() << endl;
	////���ں���
	//cout << typeid(decltype(S)).name() << endl;   //�����Σ��Ƶ�����������
	//cout << typeid(decltype(S(1))).name() << endl;//���Σ��Ƶ���������ֵ���ͣ�����ִ�к�����ֻ�����ݣ�

	////��ֵ����
	//String s1("hello");
	//String&& s2 = GetString("world");
	//String s3(move(s1)); //s1����ֵ����ֵ���ò���������ֵ��move��һ����ֵǿ��ת������ֵ����
	//                     //������move()���õ�һ���ǳ����͵����ӣ�move������������������ڼ��������Ķ�����

	//����ת��
	PerfectForward(10); // rvalue ref
	int a;
	PerfectForward(a); // lvalue ref
	PerfectForward(std::move(a)); // rvalue ref
	const int b = 8;
	PerfectForward(b); // const lvalue ref
	PerfectForward(std::move(b)); // const rvalue ref
	return 0;
}