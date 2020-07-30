#include "Header.h"

ostream& operator<<(ostream& os,const SP2& sp)
{
	os << sp.Real << " + " << sp.Imaginary << " i";
	return os;
}
istream& operator>>(istream& is, SP2& sp)
{
	char sign;
	cout << "\tEnter Real: ";
	is >> sp.Real;
	cout << "\tEnter Imaginary:";
	is >> sp.Imaginary;
	return is;
}
SP2 SP2::operator+(const SP2& sp)
{
	SP2 spkq;
	spkq.Real = this->Real + sp.Real;
	spkq.Imaginary = this->Imaginary + sp.Imaginary;
	return spkq;
}
SP2 SP2::operator-(const SP2&sp)
{
	SP2 spkq;
	spkq.Real = this->Real - sp.Real;
	spkq.Imaginary = this->Imaginary - sp.Imaginary;
	return spkq;
}
SP2 SP2::operator*(const SP2&sp)
{
	SP2 spkq;
	spkq.Real = this->Real * sp.Real - this->Imaginary * sp.Imaginary;
	spkq.Imaginary = this->Real * sp.Imaginary + sp.Real * this->Imaginary;
	return spkq;
}
SP2 SP2::operator/(const SP2&sp)
{
	SP2 spkq;
	spkq.Real = ((this->Real * sp.Real) + (this->Imaginary * sp.Imaginary)) / ((sp.Real * sp.Real) + (sp.Imaginary * sp.Imaginary));
	spkq.Imaginary = ((sp.Real * this->Imaginary) - (this->Real * sp.Imaginary)) / ((sp.Real * sp.Real) + (sp.Imaginary * sp.Imaginary));
	return spkq;
}
bool SP2::operator==(const SP2&sp)
{
	if (distance(*this) == distance(sp)) return 1;
	else return 0;
}
bool SP2::operator!=(const SP2&sp)
{
	if (*this == sp)return 0;
	else return 1;
}
bool SP2::operator<(const SP2&sp)
{
	if (distance(*this) < distance(sp))return 1;
	else return 0;
}
bool SP2::operator>(const SP2&sp)
{
	if (distance(*this) > distance(sp))return 1;
	else return 0;
}
bool SP2::operator<=(const SP2&sp)
{
	if (*this > sp) return 0;
	else return 1;
}
bool SP2::operator>=(const SP2&sp)
{
	if (*this < sp)return 0;
	else return 1;
}


SP2 SP2::operator++()
{
	++this->Real;
	return *this;
}
SP2 SP2::operator--()
{
	--this->Real;
	return *this;
}
SP2 operator++(SP2&sp, int)
{
	sp.Real++;
	return sp;
}
SP2 operator--(SP2&sp, int)
{
	sp.Real--;
	return sp;
}