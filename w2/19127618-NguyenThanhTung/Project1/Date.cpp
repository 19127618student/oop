#include "Date.h"
#include "Header.h"
Date::Date()
{
	day = month = year = 1;
}
Date::Date(int d)
{
	Date temp;
	temp = convertToDate(d);
	day = temp.day;
	month = temp.month;
	year = temp.year;
}
Date::Date(int d, int m, int y)
{
	if (d == 0 || m == 0 || y == 0) {
		cout << "Error !\nData must be different from 0\nData will be returned to default as 1...";
		day = month = year = 1;
	}
	if (d < 0) d = -d;
	if (m < 0) m = -m;
	if (y < 0) y = -y;
	
	if(m>12)
	{
		y += m / 12;
		m = m - (m / 12) * 12;
	}
	if (d > 31) {
		Date temp;
		temp = convertToDate(convertToDay(d, m, y));
		d = temp.day;
		m = temp.month;
		y = temp.year;
	}
	
		day = d;
		month = m;
		year = y;
}
long long Date::convertToDay(int d, int m, int y)
{
	int D = 0;
	int leap = 0; leap = howManyLeapYear(m,y);
	D = leap + d + (y - 1) * 365 + (m - 1) * 30 + supplement[m - 1];
	return D;
}
Date Date::convertToDate(const int& D)
{
	int Day = D;
	Day -= howManyLeapDay(D);
	Date date;
	date.year = Day / 365 + 1;
	date.month = (Day - (date.year - 1) * 365) / 30 + 1;

	int realLeapYear = howManyLeapYear(date.month, date.year);
	date.day =D - ((date.year - 1) * 365) - ((date.month - 1) * 30) - realLeapYear - date.supplement[date.month - 1];
	return date;
}
ostream& operator<<(ostream& os, const Date& d)
{
	os << d.day << "/" << d.month << "/" << d.year;
	return os;
}
Date Date::operator+(const Date& a)
{
	long long Day = convertToDay(a.day+1, a.month, a.year);
	Day += convertToDay(day+1, month, year);
	Date temp = convertToDate(Day);
	if (temp.day == 5) temp.day = 2;
	temp.month++; temp.year++;
	return temp;
}
Date Date::operator+(const int& a)
{
	long long Day = a;
	Day += convertToDay(day, month, year);
	Date temp = convertToDate(Day);
	temp.month++; temp.year++;
	return temp;
}
Date operator+(const int&a, const Date&b)
{
	long long Day = a;
	Day += ConvertToDay(b.day, b.month, b.year);
	Date temp; sp support = ConvertToDate(Day);
	temp.day = support.day;
	temp.month = support.month;
	temp.year = support.year;
	return temp;
}
Date Date::operator-(const Date& a)
{
	long long Day = 1;
	Day += convertToDay(day, month - 1, year - 2);
	Day -= convertToDay(a.day, a.month-1, a.year-1);
	Date temp;
	if (Day > 0)
		temp = convertToDate(Day);
	else temp = convertToDate(1);
	return temp;
}
Date operator-(const int& a, const Date& b)
{
	long long Day = 1; Day += a;
	Day -= ConvertToDay(b.day, b.month+1, b.year+1);
	Date temp; sp support = ConvertToDate(Day+1);
	temp.day = support.day;
	temp.month = support.month;
	temp.year = support.year;
	return temp;
}