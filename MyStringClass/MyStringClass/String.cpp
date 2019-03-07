#include "String.h"

using namespace hyb;
const size_t String::npos = -1;

ostream& hyb::operator<<(ostream &_cout, hyb::String &str)
{
	_cout << str._str;
	return cout;
}


String::String(const char* str)
{
	// 构造string类对象时，如果传递nullptr指针，认为程序非法，此处断言下     
	if (str == nullptr)
	{
		assert(false);
		return;
	}
	_size = strlen(str);
	_capacity = _size;
	_str = new char[strlen(str) + 1];
	strcpy(_str, str);
}


String::String(const String& s)
	:_str(new char[s._capacity + 1])
	, _size(s._size)
	, _capacity(s._capacity)
{
	strcpy(_str, s._str);
}


//现代版
String& hyb::String::operator=(hyb::String s)
{
	this->Swap(s);
	return *this;
}

//传统版
//String& hyb::String::operator=(const hyb::String& s)
//{
//	if (this != &s)
//	{
//		char *pStr = new char[s._capacity + 1];
//		strcpy(pStr, s._str);
//		delete[] _str;
//		_str = pStr;
//		_size = s._size;
//		_capacity = s._capacity;
//	}
//	return *this;
//}


String::~String()
{
	delete[] _str;
	_str = nullptr;
	_size = _capacity = 0;

}


String::iterator String::Begin()
{
	return _str;
}


String::iterator String::End()
{
	return _str + _size;
}


void String::PushBack(char ch)
{
	//if (_size == _capacity)
	//{
	//	if (_capacity == 0)
	//	{
	//		_capacity = 1;
	//	}
	//	Reserve(_capacity * 2);
	//}
	//_str[_size++] = ch;
	//_str[_size] = '\0';

	Insert(_size, ch);
}


void String::Reserve(size_t newCapacity)
{
	if (_capacity < newCapacity)
	{
		char *pStr = new char[newCapacity + 1];
		strcpy(pStr, _str);
		delete[] _str;
		_str = pStr;
		_capacity = newCapacity;
	}
}

void String::Resize(size_t n, char ch)
{
	if (_size > n)
	{
		_size = n;
		_str[_size] = '\0';
	}
	else
	{
		if (n > _capacity)
		{
			Reserve(n);
		}
		for (size_t i = _size; i < _capacity; i++)
		{
			_str[i] = ch;
		}
		_size = n;
		_str[_size] = '\0';

		for (size_t i = 0; i < _size; i++)
		{
			if (_str[i] == '\0')
			{
				_str[i] = ' ';
			}
		}
	}
	

}

void String::Append(const char* str)
{
	//int len = strlen(str);
	//if (_size + len > _capacity)
	//{
	//	Reserve(_size + len);
	//}
	//strcpy(_str + _size, str);
	//_size += len;

	Insert(_size, str);
}


String& String::operator+=(char ch)
{
	PushBack(ch);
	return *this;
}


String& String::operator+=(const char* str)
{
	Append(str);
	return *this;
}

size_t String::Find(char ch, size_t pos)
{
	for (size_t i = pos; i < _size; i++)
	{
		if (_str[i] == ch)
		{
			return i;
		}
	}
	return npos;
}

size_t String::RFind(char ch, size_t pos)
{
	if (pos == npos || pos > _size)
	{
		pos = _size - 1;
	}

	for (size_t i = pos; i >= 0; i--)
	{
		if (_str[i] == ch)
		{
			return i;
		}
	}
	return npos;
}

size_t String::Find(const char* str, size_t pos) const
{
	char* ret = strstr(_str + pos, str);
	if(ret == NULL)
		return npos;
	return ret - _str;
}

void String::Insert(size_t pos, char ch)
{
	assert(pos <= _size);

	if (_size == _capacity)
	{
		Reserve(_capacity == 0 ? 2 : (2 * _capacity));
	}
	int end = _size;
	while (end >= (int)pos)
	{
		_str[end + 1] = _str[end];  //要移动'\0'
		end--;
	}
	_str[pos] = ch;
	_size++;
}

void String::Insert(size_t pos, const char* str)
{
	assert(pos <= _size);
	size_t len = strlen(str);
	if (_size+len > _capacity)
	{
		Reserve(len + _capacity);
	}

	int end = _size;
	while (end >= (int)pos)
	{
		_str[end + len] = _str[end];
		end--;
	}
	while(*str)
	{
		_str[pos++] = *(str++);
	}
	_size += len;
}

void String::Erase(size_t pos, size_t len)
{
	assert(pos <= _size);
	if (len == npos || pos + len >= _size)
	{
		_str[pos] = '\0';
		_size = pos;
	}

	else
	{
		size_t cur = pos + len;
		while (cur <= _size)
		{
			_str[pos++] = _str[cur++];
		}
		_size -= len;
	}
}

// 测试
void TestString1()
{
	hyb::String s1("hello bit!!!");
	hyb::String s2(s1);

	cout << s1 << endl;
	cout << s2 << endl;


}

void TestString2()
{
	hyb::String s;
	s.PushBack('h');
	s.PushBack('e');
	s.PushBack('l');
	cout << s << endl;
	s.Append("lo");
	cout << s << endl;

	s += " ";
	s += "bit";
	cout << s << endl;
}

void TestString3()
{
	hyb::String TestString("1111122222333334444455555");
	cout << TestString << "\n  size: " << TestString.Size() << endl;
	TestString.Resize(5);
	cout << TestString << "\n  size: " << TestString.Size() << endl;
	TestString.Resize(10);
	cout << TestString << "\n  size: " << TestString.Size() << endl;
	TestString.Resize(15, '6');
	cout << TestString << "\n  size: " << TestString.Size() << endl;
}

void TestString4()
{
	hyb::String s("abcde");
	cout << s.Find('c', 6) << endl;
	cout << s.Find('a', 1) << endl;
	cout << s.Find('c') << endl;
	cout << s.RFind('c', 1) << endl;
	cout << s.Find("bcd") << endl;
	cout << s.Find("bcd", 30) << endl;
}


void TestString5()
{
	String s;
	s.Insert(0, 'a');
	s.Insert(0, 'b');
	s.Insert(0, 'c');
	s.Insert(3, "def");
	cout << s << endl;
	s.Erase(1, 2);
	cout << s << endl;

}

int main()
{
	//TestString1();
	//TestString2();
	TestString3();
	//TestString4();
	//TestString5();

	return 0;
}