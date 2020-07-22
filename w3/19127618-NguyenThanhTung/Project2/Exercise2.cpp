#include "Header.h"

int main()
{
	SoNguyenLon snl1;
	SoNguyenLon snl2(123456);
	SoNguyenLon snl3(5, 9);
	SoNguyenLon snl4(7, 30);

	cout << snl1 << endl << snl2 << endl << snl3 << endl << snl4 << endl;
	return 0;
}