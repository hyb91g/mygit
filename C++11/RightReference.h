#pragma once
#include <iostream>
#include <string.h>
using namespace std;

class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
			str = "";
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}

	String(String&& s)
		: _str(s._str)
	{
		s._str = nullptr;
	}

	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}

	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pTemp = new char[strlen(s._str) + 1];
			strcpy(pTemp, s._str);
			delete[] _str;
			_str = pTemp;
		}

		return *this;
	}

	~String()
	{
		if (_str)
			delete[] _str;
	}



private:
	char* _str;
};