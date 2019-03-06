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

//迭代器（interator/reverse_iterator/const_iterator） (不常用)
void test_string2()
{
	string num("1234");
	//迭代器给出了一个统一的方式去访问容器，屏蔽掉了底层复杂的结构细节
	string::iterator it = num.begin();   //iterator（迭代器），it:迭代器的对象。
										 //begin是指向第一个数据位置的迭代器
										 //end是指向最后一个数据下一个位置的迭代器
	int value = 0;
	while (it != num.end())
	{
		value *= 10;
		value += *it - '0';
		it++;
	}
	cout << value << endl;
}

//for + 下标  （常用）
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

//C++11 语法糖式for
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
	s1.insert(s1.begin(), 'x');  //头插
	s1.insert(0, "bit-");
	s1.erase(0, 3);      //头删3个
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
	if (pos == string::npos)  //npos静态变量
	{
		cout << "文件没有后缀" << endl;
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

	//字符转换为数字
	//以下为新的访问方式
	//test_string2();   //迭代器（interator/reverse_iterator/const_iterator） (不常用)
	//test_string3();   //for + 下标  （常用）
	//test_string4();   //C++11 语法糖式for

	//test_string5();
	//test_string6();
	//test_string7();
	test_string8();


	return 0;
}