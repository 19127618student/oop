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
SoPhuc::SoPhuc(const int& n)
{
	thuc = n;
	ao = 0;
}
SoPhuc SoPhuc::operator+(const SoPhuc& sp)
{
	SoPhuc rt = *this;
	rt.thuc += sp.thuc;
	rt.ao += sp.ao;
	return rt;
}
ostream& operator<<(ostream& os, const SoPhuc& sp)
{
	os << sp.thuc << " + " << sp.ao << "*i";
	return os;
}