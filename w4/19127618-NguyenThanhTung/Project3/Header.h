#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <string>
using namespace std;

struct Date
{
	int day, month, year;
};
Date inputDate(int d, int m,int y);
void outputDate(Date d);

class Nguoi
{
protected:
	string name;
	Date date;
	string address;
public:
	Nguoi();
	Nguoi(string, int, int, int, string);
	friend ostream& operator<<(ostream& os,const Nguoi& n);
};

class NV:public Nguoi
{
private:
	string phong_ban;
	double he_so_luong;
	double phu_cap;
public:
	NV();
	NV(string n, int d, int m, int y, string a, string pb, double hsl, double pc);
	friend ostream& operator<<(ostream& os, NV&nv);
	friend istream& operator>>(istream& is, NV& nv);
};
void inputData(NV*& a, int n);
void outputData(NV* a, int n);
#endif