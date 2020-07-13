#include "Header.h"

SoPhuc::SoPhuc()
{
	thuc = ao = 0;
}
SoPhuc::SoPhuc(int t, int a)
{
	thuc = t;
	ao = a;
}
SoPhuc SoPhuc::operator+(const int& n)
{
	SoPhuc rt = *this;
	rt.thuc += n;
	return rt;
}
ostream& operator<<(ostream& os, const SoPhuc& sp)
{
	os << sp.thuc << " + " << sp.ao << "*i";
	return os;
}
SoPhuc& operator+(int a, SoPhuc b)
{
	SoPhuc rt;
	rt.thuc = b.thuc + a;
	rt.ao = b.ao;
	return rt;
}