#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
using namespace std;

int convertToSec(int h, int m, int s);
bool isTrueTime(int h, int m, int s);

class  ThoiGian
{
private:
	int gio, phut, giay;
public:
	ThoiGian convertToHour(int s);
	friend ThoiGian convertToHour2(int s);
	void initTime(){ gio = phut = giay = 0; }
	ThoiGian()
	{
		initTime();
	}
	ThoiGian(int giay);
	ThoiGian(int phut, int giay);
	ThoiGian(int gio, int phut, int giay);
	
	ThoiGian operator+(const ThoiGian&);
	ThoiGian operator-(const ThoiGian&);
	bool operator<=(const ThoiGian&);
	
	friend ostream& operator<<(ostream& os, ThoiGian t);
	friend ThoiGian operator+(const int&,const ThoiGian&);
	friend ThoiGian operator-(const int&, const ThoiGian&);
	friend bool operator<=(const int&, const ThoiGian&);
};


#endif