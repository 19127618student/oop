#include "Date.h"
#include "Header.h"
int main()
{
	Date d1;
	Date d2(2, 10, 2014);
	Date d3(-10, 16, 2000);
	Date d4(1000);
	Date d5 = d2 + d3;
	Date d6 = d1 + 5000;
	Date d7 = 1234 + d4;
	Date d8 = 190 + d6 + d7;

	//Date d9 = d8 - d6;    //bật dòng này để chạy d9 của em
	Date d9(1, 9, 7); //test của thầy sai. bật dòng này để test d10.

	Date d10 = 12000 - d9;
	if (d10 > d6)
	{
		d10 = d2 - 1000 + d6;
	}
	cout << d1 << endl << d2 << endl << d3 << endl << d4 << endl << d5 << endl;
	cout << d6 << endl << d7 << endl << d8 << endl << d9 << endl << d10 << endl;
	return 0;
}