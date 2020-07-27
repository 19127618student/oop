#include "Header.h"
int Ucln(int a, int b) {
	if (b == 0)
		return a;
	else
		return Ucln(b, a % b);
}
void Ps1::Simplify(Ps1&ps)
{
	int uc = Ucln(ps.tu, ps.mau);
	ps.tu /= uc;
	ps.mau /= uc;
}
Ps1::Ps1()
{
	tu = 0;
	mau = 1;
}
Ps1::Ps1(int t)
{
	tu = t;
	mau = 1;
}
Ps1::Ps1(int t, int m)
{
	tu = t;
	mau = (m == 0) ? 1 : m;
}
ostream& operator<<(ostream& os, const Ps1& ps)
{
	Ps1 temp = ps;
	temp.Simplify(temp);
	
	if (temp.mau == 1) os << temp.tu;
	else { os << temp.tu << "/" << temp.mau; }
	return os;
}
istream& operator>>(istream& is, Ps1& ps)
{
	char sign;
	is >> ps.tu;
	is >> sign;
	is >> ps.mau;
	ps.Simplify(ps);
	return is;
}
Ps1 Ps1::operator+(const Ps1&ps)
{
	Ps1 psKQ;
	psKQ.tu = this->tu*ps.mau + ps.tu*this->mau;
	psKQ.mau = ps.mau * this->mau;
	psKQ.Simplify(psKQ);
	return psKQ;
}
