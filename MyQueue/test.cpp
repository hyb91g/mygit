#include "Queue.h"

int main()
{
	Queue<int> q;    
	q.Push(1);   
	q.Push(2);    
	q.Push(3);    
	q.Push(4);   
	cout << q.Size() << endl;   
	cout << q.Front() << endl; 
	cout << q.Back() << endl;
	q.Pop(); 
	q.Pop();  
	cout << q.Size() << endl; cout << q.Front() << endl;  
	cout << q.Back() << endl;
}