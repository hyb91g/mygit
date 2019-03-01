//请设计一个类，该类只能在堆上创建对象

#include<iostream>
using namespace std;

class HeapType {
public:
	static HeapType * CreateObject() {
		return new HeapType;
	}
	HeapType(const HeapType& ht) = delete;
private:
	HeapType(){}

	////只声明，不实现。因为本身可能会很麻烦，而自己却不需要
	////声明成私有
	//HeapType(const HeapType& ht);
};
int main()
{
	HeapType* p1 = HeapType::CreateObject();
	//HeapType obj(*p1);
	return 0;
}