#include "Header.h"

int main()
{
	Nguoi n1("Nguyen Thanh Tung", 17, 01, 2001, "491 Nguyen Dinh Chieu");
	cout << n1;
	cout << endl;
	
	NV *a;
	int n;
	cout << "\nNhap so nhan vien: ";
	cin >> n;
	a = new NV[n];
	inputData(a,n);
	cout << endl;
	outputData(a, n);
	return 0;
}