#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <assert.h>
#include <string.h>
using namespace std;

namespace hyb
{
	class String
	{
		friend ostream& operator<<(ostream &cout, String &str);
	public:
		// 迭代器
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator Begin();
		iterator End();

		// 在类里面实现，默认是inline
		String(const char* str = "");
		String(const String& s);
		~String();

		// s1 = s2
		//String& operator=(const bit::String& s);
		String& operator=(String s);

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		const char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		size_t Size() const
		{
			return _size;
		}

		size_t Capacity() const
		{
			return _capacity;
		}

		void Swap(String& s)
		{
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}

		const char* c_str()
		{
			return _str;
		}

		void Reserve(size_t n);
		void Resize(size_t n, char ch = '\0');

		void PushBack(char ch);
		void Append(const char* str);
		String& operator+=(char ch);
		String& operator+=(const char* str);
		size_t Find(char ch, size_t pos = 0);
		size_t RFind(char ch, size_t pos = npos);
		size_t Find(const char* str, size_t pos = 0) const;
		void Insert(size_t pos, char ch);
		void Insert(size_t pos, const char* str);
		void Erase(size_t pos, size_t len = npos);
	private:
		char* _str;
		size_t _size;
		size_t _capacity;

		static const size_t npos;
	};
};