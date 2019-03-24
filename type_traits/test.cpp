#include <iostream>
#include <string>

//������������
struct TrueType {
	static bool Get()
	{
		return true;
	}
};
//�����Զ�������
struct FalseType {
	static bool Get()
	{
		return false;
	}
};

//����ģ��
template<class T> 
struct TypeTraits 
{ 
	typedef FalseType IsPODType;
};
//����������ģ��������·�ʽ��ʵ����
template<> 
struct TypeTraits<char>
{ 
	typedef TrueType IsPODType;
};
template<> 
struct TypeTraits<short> 
{ 
	typedef TrueType IsPODType;
};
template<> 
struct TypeTraits<int> 
{ 
	typedef TrueType IsPODType; 
};
template<> 
struct TypeTraits<long> 
{ 
	typedef TrueType IsPODType; 
};


//bool IsPODType(const char* strType)
//{
//	const char *arrType[] = { "char", "short", "int", "long", "long long", "float", "double", "long double" };
//
//	for (auto e : arrType)
//	{
//		if (strcmp(e, strType) == 0)
//			return true;
//	}
//	return false;
//}

template<class T>
void Copy(T* dst, const T* src, size_t size)
{
	if(TypeTraits<T>::IsPODType::Get())
		memcpy(dst, src, sizeof(T)*size);
	else
	{
		for (size_t i = 0; i < size; ++i)
		{
			dst[i] = src[i];
		}
	}
}

int main()
{
	int a1[] = { 1,2,3,4,5,6,7,8,9,0 };   
	int a2[10];   
	Copy(a2, a1, 10);

	std::string strarr1[3] = { "11", "22", "33" };   
	std::string strarr2[3];   
	Copy(strarr2, strarr1, 3);
	return 0;
}