#include "Date.h"
#include "Header.h"
bool isLeapYear(int year)
{
	if (year == 0)return 0;
	if (year % 400 == 0) return 1;
	if (year % 100 != 0 && year % 4 == 0) return 1;
	return 0;
}
int howManyLeapYear(int month, int year)
{
	int leap = 0;
	for(int i=0;i<year;i++)
	{
		if (isLeapYear(i) == 1)leap++;
	}
	if(isLeapYear(year) == 1)
	{
		if (month >= 3) leap++;
	}
	return leap;
}
int howManyLeapDay(int day)
{
	double base = 4.12883494 * 365;
	int leapDay = (day / base) + 1;
	return leapDay;
}

int ConvertToDay(int day, int month, int year)
{
	int supplement[12] = { 0,1,-1,0,0,1,1,2,3,3,4,4 };
	int D = 0;
	int leap = 0; leap = howManyLeapYear(month, year);
	D = leap + day + (year - 1) * 365 + (month - 1) * 30 + supplement[month - 1] + 1;
	return D;
}
sp ConvertToDate(const int& D)
{
	int supplement[12] = { 0,1,-1,0,0,1,1,2,3,3,4,4 };
	int y = 1; int m = 1; int d = 1;
	int day = D;
	day -= howManyLeapDay(D);
	y += day / 365;
	m += (day - (y - 1) * 365) / 30;
	int leap = howManyLeapYear(m, y);
	d += D - ((y - 1) * 365) - ((m - 1) * 30) - supplement[m - 1] - leap;
	sp temp;
	temp.day = d;
	temp.month = m;
	temp.year = y;
	return temp;
}
bool Date::operator>(const Date& a)
{
	int x = ConvertToDay(day, month, year);
	int y = ConvertToDay(a.day, a.month, a.year);
	if (x > y)
	{
		return 1;
	}
	else return 0;
}