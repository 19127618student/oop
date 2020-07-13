#include "Header.h"
void main()
{
	SoPhuc sp1(3, 5);
	SoPhuc sp2 = sp1.operator+(10);
	SoPhuc sp3 = sp1 + 10;
	cout << sp2 << endl << sp3 << endl;
}