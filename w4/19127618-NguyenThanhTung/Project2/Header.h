#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <cmath>
using namespace std;

class SP1
{
protected:
	double Real, Imaginary;
public:
	SP1();
	SP1(double Re);
	SP1(double Re, double Im);
	void displaySP();
	double distance(const SP1& sp);
};

class SP2:public SP1
{
public:
	SP2():SP1(){};
	SP2(double Re):SP1(Re){};
	SP2(double Re, double Im):SP1(Re,Im){};

	SP2 operator+(const SP2&);
	SP2 operator-(const SP2&);
	SP2 operator*(const SP2&);
	SP2 operator/(const SP2&);
	bool operator==(const SP2&);
	bool operator!=(const SP2&);
	bool operator>(const SP2&);
	bool operator>=(const SP2&);
	bool operator<(const SP2&);
	bool operator<=(const SP2&);

	SP2 operator++();
	friend SP2 operator++(SP2&, int);
	SP2 operator--();
	friend SP2 operator--(SP2&, int);
	
	friend ostream& operator<<(ostream& os,const SP2& sp);
	friend istream& operator>>(istream& is, SP2& sp);
};
#endif