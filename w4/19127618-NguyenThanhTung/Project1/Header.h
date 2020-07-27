#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <cmath>
using namespace std;

int Ucln(int a, int b);

class Ps1
{
protected:
	int tu, mau;
public:
	Ps1();
	Ps1(int);
	Ps1(int, int);
	
	void Simplify(Ps1& ps);
	Ps1 operator+(const Ps1&);
	friend ostream& operator<<(ostream& os,const Ps1&ps);
	friend istream& operator>>(istream& is, Ps1&ps);
};

class Ps2: public Ps1
{
protected:
	bool sign;
public:
	Ps2();
	Ps2(char, int);
	Ps2(char, int, int);

	Ps2 operator-(const Ps2&);
	Ps2 operator*(const Ps2&);
	Ps2 operator/(const Ps2&);
	bool operator==(const Ps2&);
	bool operator!=(const Ps2&);
	bool operator>(const Ps2&);
	bool operator>=(const Ps2&);
	bool operator<(const Ps2&);
	bool operator<=(const Ps2&);

	Ps2 operator++();
	friend Ps2 operator++(Ps2&, int);
	Ps2 operator--();
	friend Ps2 operator--(Ps2&,int);
	friend ostream& operator<<(ostream& os,const Ps2&ps);
	friend istream& operator>>(istream& is, Ps2&ps);
};

#endif