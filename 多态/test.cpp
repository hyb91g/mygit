#include <iostream>
using namespace std;

////多态的定义
//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "买票全价" << endl;
//	}
//};
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "半价买票" << endl;
//	}
//};
//
//void Func(Person& people)    //调用函数的对象必须是指针或者引用.若不用指针或引用，则传一个对象给基类类型（切片），父类将自己的虚表改为子类的虚表，不合理。
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



////虚函数重写的例外：协变。返回值不同，但必须是基类指针和派生类指针或者基类引用和派生类引用
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



////析构函数的重写
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
//// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多态，才能保证p1和p2指向的对象正确的调用析构函数。 
//int main() {   
//	Person* p1 = new Person;  
//	Person* p2 = new Student;
//	
//	delete p1;  //这里希望通过对象调析构 ，所以用虚函数
//	delete p2;
//	
//	return 0; 
//}
//基类的析构函数不是虚函数时，两个析构函数没有构成多态.
//在析构的时候，是根据类型析构，而不是根据对象析构，忽略了派生类的部分，会造成内存泄漏。
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
//	//结果为：
//	//      ~Person()
//	//      ~Person()  
//	//只对基类不部分进行了析构，而并没有对派生类部分进行析构
//
//	return 0;
//}


//抽象类
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


////单继承中的虚函数表
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
////打印虚表（监视窗口看不到func3和4）
//typedef void(*VFUNC)();
//void PrintVTable(VFUNC table[])
//{
//	printf("虚表指针：%p\n", table);
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
//	printf("虚表指针：%p\n", table);
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