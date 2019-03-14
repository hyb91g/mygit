#include "Stack.h"

void test()
{
	Stack<int> s;  
	s.Push(1);  
	s.Push(2); 
	s.Push(3); 
	s.Push(4);  
	cout << s.Size() << endl; 
	cout << s.Top() << endl;
}

int main()
{
	test();
}