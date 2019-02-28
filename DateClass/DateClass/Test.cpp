#include"Test.h"

const static int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int Date::GetMonthDay(int year, int month)
{
	if ((month == 2)
		&& (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return 29;
	else
		return monthDay[month];
}

Date::Date(int year, int month, int day)
	:_year(year)
	,_month(month)
	,_day(day)
{
	//if ((month > 0 && month < 13)
	//	&& (day > 0 && day <= GetMonthDay(year, month)))
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//}
	//else
	//	cout << "Date Invalid" << endl;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}
	return false;
}
bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}

bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

Date Date::operator+(int day)
{
	Date ret(*this);
	ret += day;
	return ret;
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month > 12)
		{
			_month = 1;
			_year++;
		}
	}
	return *this;
}
Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;
	return ret;
}
Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day <= 0)
	{
		_month--;
		if (_month == 0)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);
	}
	return *this;
}
int Date::operator-(const Date& d)
{
	int count = 0;
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (max < min)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	while (max > min)
	{
		count++;
		++min;
	}
	return count*flag;
}

// ++d => d.operator++(&d)
Date& Date::operator++()
{
	*this += 1;
	return *this;
}

// d++ => d.operator(&d, 0);
Date Date::operator++(int)
{
	Date ret(*this);
	*this += 1;
	return ret;
}

// --d 
Date& Date::operator--() 
{
	*this -= 1;
	return *this;
}

// d--
Date Date::operator--(int)
{
	Date ret(*this);
	*this -= 1;
	return ret;
}

void Date::Print()
{
	cout << this->_year << "-" << this->_month << "-" << this->_day << endl;
}

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

int main()
{
	Date d1(2056, 3, 2);
	Date d2(2015, 8, 27);
	cout << d1 - d2 << endl;

	Date d3 = d1 - 63;
	d3.Print();
	d3 -= 137;
	d3.Print();

	cout << d3;

	return 0;
}