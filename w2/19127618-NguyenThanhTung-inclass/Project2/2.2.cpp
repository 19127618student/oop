#include "Header.h"

int main()
{
	SoPhuc sp1(3, 5);
	SoPhuc sp2 = sp1.operator+(10);
	SoPhuc sp3 = sp1 + 10;
	SoPhuc sp4 = 10 + sp1;
	cout << sp2 << endl << sp3 << endl << sp4 << endl;
}