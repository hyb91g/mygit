#include <iostream>
#include <string>
using namespace std;

void test_string1()
{
	string s1;
	string s2("hello");
	string s3(s2);
	string s4 = "world";  // explicit

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

//��������interator/reverse_iterator/const_iterator�� (������)
void test_string2()
{
	string num("1234");
	//������������һ��ͳһ�ķ�ʽȥ�������������ε��˵ײ㸴�ӵĽṹϸ��
	string::iterator it = num.begin();   //iterator������������it:�������Ķ���
										 //begin��ָ���һ������λ�õĵ�����
										 //end��ָ�����һ��������һ��λ�õĵ�����
	int value = 0;
	while (it != num.end())
	{
		value *= 10;
		value += *it - '0';
		it++;
	}
	cout << value << endl;
}

//for + �±�  �����ã�
void test_string3()
{
	string num("1234");
	string::iterator it = num.begin();   
	int i = 0;
	for (; i < num.size(); i++)
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}

//C++11 �﷨��ʽfor
void test_string4()
{
	string num("1234");
	int value = 0;
	for (auto e : num)
	{
		value *= 10;
		value += (e - '0');
	}
	cout << value << endl;
}

void test_string5()
{
	string s("hello");
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl << endl;

	s.reserve(50);
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl << endl;

	s.resize(80, '1');
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.capacity() << endl << endl;

	string s1("hello Bit");
	s1[6] = 'b';
	cout << s1 << endl;
}

void test_string6()
{
	/*string s1("hello");
	s1.push_back(' ');
	s1.append("world");
	cout << s1 << endl;*/

	string s1("hello");
	s1 += ' ';
	s1 += "world";
	string s2("!!!");
	s1 += s2;
	s1.insert(s1.begin(), 'x');  //ͷ��
	s1.insert(0, "bit-");
	s1.erase(0, 3);      //ͷɾ3��
	cout << s1 << endl;
	cout << s1.c_str() << endl;

	string num("111");
	int value = atoi(num.c_str());
	cout << value << endl;
}

void test_string7()
{
	string file("test.cpp");
	size_t pos = file.rfind('.');
	if (pos == string::npos)  //npos��̬����
	{
		cout << "�ļ�û�к�׺" << endl;
	}
	else
	{
		cout << file.substr(pos, file.size() - pos) << endl;
	}

	string url("https://www.cplusplus.com/reference/string/string/erase/");
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "url invalid" << endl;
		return;
	}
	start += 3;
	size_t end = url.find("/", start);
	cout << url.substr(start, end - start) << endl;

	pos = url.find("://");
	url.erase(0, pos + 3);
	cout << url << endl;
}

void test_string8()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	for (int i = 0; i < 100; ++i)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}

	string s1("hello");
	string s2("world");
	cout << s1 + s2 << endl;
	cout << s1 + "world" << endl;
	cout << "hello" + s2 << endl;


}
int main()
{
	//test_string1();

	//�ַ�ת��Ϊ����
	//����Ϊ�µķ��ʷ�ʽ
	//test_string2();   //��������interator/reverse_iterator/const_iterator�� (������)
	//test_string3();   //for + �±�  �����ã�
	//test_string4();   //C++11 �﷨��ʽfor

	//test_string5();
	//test_string6();
	//test_string7();
	test_string8();


	return 0;
}