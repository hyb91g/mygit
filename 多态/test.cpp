#include <iostream>
using namespace std;

////��̬�Ķ���
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "��Ʊȫ��" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "�����Ʊ" << endl;
//	}
//};
//
//void Func(Person& people)    //���ú����Ķ��������ָ���������.������ָ������ã���һ��������������ͣ���Ƭ�������ཫ�Լ�������Ϊ��������������
//{
//	people.BuyTicket();
//}
//
//void Test()
//{
//	Person p;
//	Func(p);
//	Student s;
//	Func(s);
//}



////�麯����д�����⣺Э�䡣����ֵ��ͬ���������ǻ���ָ���������ָ����߻������ú�����������
//class A{};
//class B : public A{};
//
//class Person
//{
//public:
//	virtual A* f()
//	{
//		return new A;
//	}
//};
//class Student : public Person
//{
//public:
//	virtual B* f()
//	{
//		return new B;
//	}
//};



////������������д
//class Person 
//{ 
//public:   
//	virtual ~Person() 
//	{ 
//		cout << "~Person()" << endl; 
//	}
//};
//
//class Student : public Person 
//{ 
//public:  
//	virtual ~Student()
//	{ 
//		cout << "~Student()" << endl;
//	} 
//};
//
//// ֻ��������Student������������д��Person�����������������delete��������������������ܹ��ɶ�̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ������������� 
//int main() {   
//	Person* p1 = new Person;  
//	Person* p2 = new Student;
//	
//	delete p1;  //����ϣ��ͨ����������� ���������麯��
//	delete p2;
//	
//	return 0; 
//}
//������������������麯��ʱ��������������û�й��ɶ�̬.
//��������ʱ���Ǹ������������������Ǹ��ݶ���������������������Ĳ��֣�������ڴ�й©��
//class Person
//{
//public:
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};
//
//int main() {
//	Person* p1 = new Person;
//	Person* p2 = new Student;
//
//	delete p1;
//	delete p2;
//
//	//���Ϊ��
//	//      ~Person()
//	//      ~Person()  
//	//ֻ�Ի��಻���ֽ���������������û�ж������ಿ�ֽ�������
//
//	return 0;
//}


//������
class A
{
public:
	virtual void Func() = 0;
};
class A1 : public A
{
public:
	virtual void Func()
	{
		cout << "A1" << endl;
	}
};
class A2 : public A
{
public:
	virtual void Func()
	{
		cout << "A2" << endl;
	}
};
int main()
{
	A* a1 = new A1;
	A* a2 = new A2;
	a1->Func();
	a2->Func();
	return 0;
}


////���̳��е��麯����
//class Base {
//public:
//	virtual void func1() { cout << "bfunc1()" << endl; }
//	virtual void func2() { cout << "bfunc2()" << endl; }
//
//private:
//	int i;
//};
//
//class Derive : public Base {
//public:
//	virtual void func1() { cout << "dfunc1()" << endl; }
//	virtual void func3() { cout << "dfunc3()" << endl; }
//	virtual void func4() { cout << "dfunc4()" << endl; }
//private:
//	int j;
//};
//
////��ӡ������Ӵ��ڿ�����func3��4��
//typedef void(*VFUNC)();
//void PrintVTable(VFUNC table[])
//{
//	printf("���ָ�룺%p\n", table);
//	for (size_t i = 0; table[i] != nullptr; i++)
//	{
//		printf("vtable[%d]:%p->", i, table[i]);
//		VFUNC vf = table[i];
//		vf();
//	}
//}

//class Base1 
//{
//public:  
//	virtual void func1() { cout << "Base1::func1" << endl; }  
//	virtual void func2() { cout << "Base1::func2" << endl; } 
//private:  
//	int b1; 
//};
//class Base2 
//{ 
//public:  
//	virtual void func1() { cout << "Base2::func1" << endl; } 
//	virtual void func2() { cout << "Base2::func2" << endl; } 
//private:   
//	int b2; };
//
//class Derive : public Base1, public Base2 
//{ 
//public:   
//	virtual void func1() { cout << "Derive::func1" << endl; }   
//	virtual void func3() { cout << "Derive::func3" << endl; }
//private:  
//	int d1; 
//};
//
//typedef void(*VFPTR)();
//void PrintVTable(VFPTR table[])
//{
//	printf("���ָ�룺%p\n", table);
//	for (size_t i = 0; table[i] != nullptr; i++)
//	{
//		printf("vtable[%d]:%p->", i, table[i]);
//		VFPTR vf = table[i];
//		vf();
//	}
//}
//
//int main()
//{
//	//Base b;
//	//PrintVTable((VFUNC*)*(int*)&b);
//	//Derive d;
//	//PrintVTable((VFUNC*)*(int*)&d);
//
//	Derive d;
//	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);   
//	PrintVTable(vTableb1);
//	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));    
//	PrintVTable(vTableb2);
//
//	return 0;
//}