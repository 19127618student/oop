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

	cout << endl;
	cout << "\nCompare by distance to center (0,0)\n\n";
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