#include "Header.h"

int main()
{
	SP1 a;
	a.displaySP(); cout << endl;
	SP1 b(5);
	b.displaySP(); cout << endl;

	SP2 x;
	SP2 y;
	cout << "\nEnter x: \n";
	cin >> x;
	cout << "Enter y: \n";
	cin >> y;
	cout << "x: " << x << endl;
	cout << "y: " << y << endl<< endl;
	cout << "x + y = " << x + y << endl;
	cout << "x - y = " << x - y << endl;
	cout << "x * y = " << x * y << endl;
	cout << "x / y = " << x / y << endl;
	return 0;
}