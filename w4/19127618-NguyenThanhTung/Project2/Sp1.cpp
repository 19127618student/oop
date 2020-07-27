#include "Header.h"
SP1::SP1()
{
	Real = 0;
	Imaginary = 0;
}
SP1::SP1(double Re)
{
	Real = Re;
	Imaginary = 0;
}
SP1::SP1(double Re, double Im)
{
	Real = Re;
	Imaginary = Im;
}
void SP1::displaySP()
{
	cout << Real << " + " << Imaginary << " i";
}
