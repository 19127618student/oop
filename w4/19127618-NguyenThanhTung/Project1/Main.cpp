#include "Header.h"

int main()
{
	Ps2 test('+', 9, 11);
	Ps2 test2('-', 17, 1);
	cout << "ps = " << test << endl;
	cout << "ps++ = " << test++ << endl;
	cout << "ps-- = " << test-- << endl;
	cout << "(9/11) - (-17/1) = " << test - test2 << endl;
	cout << "(9/11) * (-17/1) = " << test * test2 << endl;
	cout << "(9/11) / (-17/1) = " << test / test2 << endl;
	Ps1 a, b, c;
	cout << "Enter fraction a ( ex: 1/5): ";
	cin >> a;
	cout << "Enter fraction b ( ex: 1/5): ";
	cin >> b;
	c = a + b;
	cout << "c = " << c << endl;
	cout << "\n!!! The format of required fractions is: the sign of the fraction, the numerator, the ''/'' sign, the denominator !!!\n";
	Ps2 x, y;
	cout << "\nEnter fraction x ( ex: +1/5): ";
	cin >> x;
	cout << "Enter fraction y ( ex: -1/5): ";
	cin >> y;
	cout << endl;
	if (x == y) {
		cout << "x equals y \n";
	}
	else {
		cout << "x differs from y and ";
		if (x > y)cout << "x is greater than y\n";
		else if (x < y) cout << "x is smaller than y\n";
	}
	cout << endl;
	return 0;
}