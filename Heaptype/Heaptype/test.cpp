//�����һ���࣬����ֻ���ڶ��ϴ�������

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

	////ֻ��������ʵ�֡���Ϊ������ܻ���鷳�����Լ�ȴ����Ҫ
	////������˽��
	//HeapType(const HeapType& ht);
};
int main()
{
	HeapType* p1 = HeapType::CreateObject();
	//HeapType obj(*p1);
	return 0;
}