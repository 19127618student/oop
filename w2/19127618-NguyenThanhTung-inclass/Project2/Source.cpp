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
SoPhuc operator+(const int& n, const SoPhuc& sp)
{
	SoPhuc rt;
	rt.thuc = n + sp.thuc;
	rt.ao = sp.ao;
	return rt;
}
ostream& operator<<(ostream& os, const SoPhuc& sp)
{
	os << sp.thuc << " + " << sp.ao << "*i";
	return os;
}