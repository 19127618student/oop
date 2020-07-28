#include "Header.h"

Ps2::Ps2():Ps1()
{
	sign = 1;
}
Ps2::Ps2(char s, int t) : Ps1(t)
{
	if (s == '-') sign = 0;
	else sign = 1;
}
Ps2::Ps2(char s, int t, int m):Ps1(t,m)
{
	if (s == '-') sign = 0;
	else sign = 1;
}
ostream& operator<<(ostream& os,const Ps2&ps)
{
	if (ps.sign == 0) os << "-"; else os << "+";
	os << (Ps1)ps;
	return os;
}
istream& operator>>(istream& is, Ps2& ps)
{
	char s, t;
	is >> s;
	if (s == '-') ps.sign = 0;
	else ps.sign = 1;
	is >> ps.tu;
	is >> t;
	is >> ps.mau;
	if (ps.sign == 0 && ps.mau < 0) ps.sign = 1;
	else if (ps.sign == 0 && ps.mau > 0) ps.sign = 0;
	else if (ps.sign == 1 && ps.mau < 0) ps.sign = 0;
	else if (ps.sign == 1 && ps.mau > 0) ps.sign = 1;
	ps.mau = abs(ps.mau);
	return is;
}
Ps2 Ps2::operator-(const Ps2& ps)
{
	Ps2 psKQ;
	Ps2 ps1 = *this; Ps2 ps2 = ps;
	ps1.tu = (ps1.sign == 1) ? ps1.tu : -ps1.tu;
	ps2.tu = (ps2.sign == 1) ? ps2.tu : -ps2.tu;
	
	psKQ.tu = ps1.tu * ps2.mau - ps2.tu * ps1.mau;
	psKQ.mau = ps2.mau * ps1.mau;
	
	psKQ.sign = (psKQ.tu >= 0) ? 1 : 0;
	psKQ.tu = abs(psKQ.tu);
	psKQ.Simplify(psKQ);
	return psKQ;
}
Ps2 Ps2::operator*(const Ps2&ps)
{
	Ps2 psKQ;
	Ps2 ps1 = *this; Ps2 ps2 = ps;
	ps1.tu = (ps1.sign == 1) ? ps1.tu : -ps1.tu;
	ps2.tu = (ps2.sign == 1) ? ps2.tu : -ps2.tu;
	
	psKQ.tu = ps1.tu * ps2.tu;
	psKQ.mau = ps1.mau * ps2.mau;
	
	psKQ.sign = (psKQ.tu >= 0) ? 1 : 0;
	psKQ.tu = abs(psKQ.tu);
	psKQ.Simplify(psKQ);
	return psKQ;
}
Ps2 Ps2::operator/(const Ps2&ps)
{
	Ps2 psKQ;
	Ps2 ps1 = *this; Ps2 ps2 = ps;
	ps1.tu = (ps1.sign == 1) ? ps1.tu : -ps1.tu;
	ps2.tu = (ps2.sign ==1) ? ps2.tu : -ps2.tu;
	
	psKQ.tu = ps1.tu * ps2.mau;
	psKQ.mau = ps1.mau * ps2.tu;
	
	if (psKQ.tu >= 0 && psKQ.mau >= 0)
	{
		psKQ = psKQ;
		psKQ.sign = 1;
	}
	else if (psKQ.tu < 0 && psKQ.mau < 0) {
		psKQ.tu = abs(psKQ.tu);
		psKQ.mau = abs(psKQ.mau);
		psKQ.sign = 1;
	}
	else
	{
		psKQ.tu = abs(psKQ.tu);
		psKQ.mau = abs(psKQ.mau);
		psKQ.sign = 0;
	}
	psKQ.Simplify(psKQ);
	return psKQ;
}

bool Ps2::operator==(const Ps2&ps)
{
	Ps2 ps1 = *this;
	Ps2 ps2 = ps;
	ps1.tu *= ps.mau;
	ps1.mau *= ps.mau;
	ps2.tu *= this->mau;
	ps2.mau *= this->mau;

	if (ps1.tu == ps2.tu && ps1.sign == ps2.sign) return true;
	else return false;
}
bool Ps2::operator!=(const Ps2& ps)
{
	if (*this == ps) return false;
	else return true;
}
bool Ps2::operator<(const Ps2&ps)
{
	Ps2 ps1 = *this;
	Ps2 ps2 = ps;
	if (ps1.sign == 1 && ps2.sign == 0) return 0;
	else if (ps1.sign == 0 && ps2.sign == 1) return 1;
	ps1.tu *= ps.mau;
	ps1.mau *= ps.mau;
	ps2.tu *= this->mau;
	ps2.mau *= this->mau;
	if (ps1.tu < ps2.tu && ps1.sign == 1 && ps2.sign == 1) return true;
	if (ps1.tu > ps2.tu && ps1.sign == 0 && ps2.sign == 0) return true;
	return false;
}
bool Ps2::operator<=(const Ps2& ps)
{
	Ps2 ps1 = *this;
	Ps2 ps2 = ps;
	if (ps1.sign == 1 && ps2.sign == 0) return 0;
	else if (ps1.sign == 0 && ps2.sign == 1) return 1;
	ps1.tu *= ps.mau;
	ps1.mau *= ps.mau;
	ps2.tu *= this->mau;
	ps2.mau *= this->mau;
	if (ps1.tu <= ps2.tu && ps1.sign == 1 && ps2.sign == 1) return true;
	else return false;
}
bool Ps2::operator>(const Ps2& ps)
{
	Ps2 ps1 = *this;
	Ps2 ps2 = ps;
	if (ps1.sign == 1 && ps2.sign == 0) return 1;
	else if (ps1.sign == 0 && ps2.sign == 1) return 0;
	ps1.tu *= ps.mau;
	ps1.mau *= ps.mau;
	ps2.tu *= this->mau;
	ps2.mau *= this->mau;
	if (ps1.tu > ps2.tu && ps1.sign == 1 && ps2.sign == 1) return true;
	if (ps1.tu < ps2.tu && ps1.sign == 0 && ps2.sign == 0) return true;
	return false;
}
bool Ps2::operator>=(const Ps2& ps)
{
	Ps2 ps1 = *this;
	Ps2 ps2 = ps;
	if (ps1.sign == 1 && ps2.sign == 0) return 1;
	else if (ps1.sign == 0 && ps2.sign == 1) return 0;
	ps1.tu *= ps.mau;
	ps1.mau *= ps.mau;
	ps2.tu *= this->mau;
	ps2.mau *= this->mau;
	if (ps1.tu >= ps2.tu && ps1.sign == 1 && ps2.sign == 1) return true;
	else return false;
}
Ps2 Ps2::operator++()
{
	Ps2 ps = *this;
	ps.tu = (ps.sign == 1) ? ps.tu : -ps.tu;
	ps.tu += ps.mau;
	
	ps.sign = (ps.tu >= 0) ? 1 : 0;
	ps.tu = abs(ps.tu);
	ps.Simplify(ps);
	
	return ps;
}
Ps2 operator++(Ps2&ps, int x)
{
	ps.tu = (ps.sign == 1) ? ps.tu : -ps.tu;
	x = ps.mau;
	ps.tu += x;
	ps.sign = (ps.tu >= 0) ? 1 : 0;
	ps.tu = abs(ps.tu);
	ps.Simplify(ps);
	return ps;
}
Ps2 Ps2::operator--()
{
	Ps2 ps = *this;
	Ps2 t('+', 1);
	ps = ps - t;
	return ps;
}
Ps2 operator--(Ps2& ps, int x)
{
	x = ps.mau;
	Ps2 t('+', 1);
	ps = ps - t;
	return ps;
}
