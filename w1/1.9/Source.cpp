#include "Header.h"
//ex8
char* ex8(char* pc) { return pc; }
//ex9
float* ex9(int* pi)
{
	float a = (float)*pi;
	float* b = &a;
	return b;
}
//ex10
void ex10(int* pi)
{
	if (*pi % 2 == 0) cout << "even";
	else cout << "odd";
}
//ex11
void printCatfish()
{
	cout << "Catfish";
}
void printchrisname()
{
	cout << "chrisname";
}
void printdevonrevenge()
{
	cout << "devonrevenge";
}
void ex11()
{
	while (true)
	{
		system("cls");
		cout << "Press 1: function printCatfish";
		cout << "\nPress 2: function printchrisname";
		cout << "\nPress 3: function printdevonrevenge";
		cout << "\nPress 0: exit\n";
		cout << "\nEnter option: ";
		int n;
		cin >> n;
		cout << endl;
		if (n >= 0 && n < 4) {
			if (n == 1) printCatfish();
			else if (n == 2) printchrisname();
			else if (n == 3)printdevonrevenge();
			else if (n == 0)break;
		}
		else
		{
			cout << "The input value is not valid !!!";
		}
		cout << endl << endl;
		system("pause");
	}
}