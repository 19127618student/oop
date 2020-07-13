#ifndef _DATE_H_
#define _DATE_H_
#include "Header.h"
class Date
{
private:
	int day, month, year;

	int d_o_m[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int supplement[12] = { 0,1,-1,0,0,1,1,2,3,3,4,4 };
public:
	Date();
	Date(int d);
	Date(int d, int m, int y);
	
	long long convertToDay(int d,int m,int y);
	Date convertToDate(const int&);

	Date operator+(const int&);
	Date operator+(const Date&);
	Date operator-(const Date&);
	bool operator>(const Date& a);

	friend Date operator+(const int&, const Date&);
	friend Date operator-(const int&, const Date&);
	friend ostream& operator<<(ostream&, const Date&);
	
};

int ConvertToDay(int day, int month, int year);
sp ConvertToDate(const int& D);
#endif