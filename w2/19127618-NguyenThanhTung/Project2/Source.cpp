#include "Header.h"
int convertToSec(int h, int m, int s)
{
	if (h < 0)h = -h;
	if (m < 0)m = -m;
	if (s < 0)s = -s;
	s += m * 60 + h * 60 * 60;
	return s;
}
ThoiGian ThoiGian::convertToHour(int s)
{
	ThoiGian t;
	this->phut = s / 60;
	this->gio = this->phut / 60;
	this->phut -= this->gio * 60;
	this->giay = s - this->phut * 60 - this->gio * 60 * 60;
	t.gio = this->gio; t.phut = this->phut; t.giay = this->giay;
	return t;
}
ThoiGian convertToHour2(int s)
{
	ThoiGian t;
	t.phut = s / 60;
	t.gio = t.phut / 60;
	t.phut -= t.gio * 60;
	t.giay = s - t.phut * 60 - t.gio * 60 * 60;
	return t;
}
bool isTrueTime(int h, int m, int s)
{
	if (h >= 0 && h)
	{
		if (m >= 0 && m < 61)
		{
			if (s >= 0 && h < 61) return 1;
			else return 0;
		}
		else return 0;
	}
	else return 0;
}
ostream& operator<<(ostream& os, ThoiGian t)
{
	if (t.gio != 0)
	{
		if(t.gio/10>=1)
			os << t.gio;
		else
		{
			os << "0" << t.gio;
		}
	}
	else os << "00";
	os << ":";
	if (t.phut != 0) 
	{
		if (t.phut / 10 >= 1)
			os << t.phut;
		else
		{
			os << "0" << t.phut;
		}
	}
	else os << "00";
	os << ":";
	if (t.giay != 0)
	{
		if (t.giay / 10 >= 1)
			os << t.giay;
		else
		{
			os << "0" << t.giay;
		}
	}
	else os << "00";
	return os;
}


ThoiGian::ThoiGian(int giay)
{
	convertToHour(giay);
}
ThoiGian::ThoiGian(int phut, int giay)
{
	int temp = 0;
	temp = convertToSec(0, phut, giay);
	convertToHour(temp);
}
ThoiGian::ThoiGian(int gio, int phut, int giay)
{
	int temp = 0;
	temp = convertToSec(gio, phut, giay);
	convertToHour(temp);
}
ThoiGian ThoiGian::operator+(const ThoiGian&a)
{
	int temp1 = convertToSec(this->gio, this->phut, this->giay);
	int temp2 = convertToSec(a.gio,a.phut,a.giay);
	int temp = temp1 + temp2;
	ThoiGian sum;
	sum = convertToHour2(temp);
	return sum;
}
ThoiGian operator+(const int&x,const ThoiGian &a)
{
	int temp = convertToSec(a.gio, a.phut, a.giay);
	temp += x;
	ThoiGian sum;
	sum = convertToHour2(temp);
	return sum;
}
ThoiGian ThoiGian::operator-(const ThoiGian& a)
{
	int temp1 = convertToSec(this->gio, this->phut, this->giay);
	int temp2 = convertToSec(a.gio, a.phut, a.giay);
	int temp = temp1 - temp2;
	ThoiGian part;
	part = convertToHour2(temp);
	return part;
}
ThoiGian operator-(const int& x, const ThoiGian& a)
{
	int temp1 = x;
	int temp2 = convertToSec(a.gio, a.phut, a.giay);
	int temp;
	if (temp1 >= temp2)
		temp = temp1 - temp2;
	else temp = 0;
	ThoiGian part;
	part = convertToHour2(temp);
	return part;
}
bool ThoiGian::operator<=(const ThoiGian& a)
{
	int temp1 = convertToSec(this->gio, this->phut, this->giay);
	int temp2 = convertToSec(a.gio, a.phut, a.giay);
	if (temp1 <= temp2)return 1;
	else return 0;
}
bool operator<=(const int&x, const ThoiGian&a)
{
	int temp = convertToSec(a.gio, a.phut, a.giay);
	if (x <= temp)return 1;
	else return 0;
}