#include "Header.h"
Date inputDate(int d, int m, int y)
{
	Date D;
	D.day = d;
	D.month = m;
	D.year = y;
	return D;
}
void outputDate(Date d)
{
	cout << d.day << "/" << d.month << "/" << d.year;
}
Nguoi::Nguoi()
{
	name = "Null";
	date = inputDate(1, 1, 1);
	address = "Null";
}
Nguoi::Nguoi(string n, int d, int m, int y, string a)
{
	name = n;
	date = inputDate(d, m, y);
	address = a;
}
ostream& operator<<(ostream& os,const Nguoi& n)
{
	cout << "Ten:  ";
	os << n.name<<endl;
	cout << "Ngay sinh:  ";
	outputDate(n.date);
	cout << "\nDia chi:  ";
	os << n.address;
	return os;
}
void inputData(NV*& a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhan vien thu " << i + 1 << endl;
		cin >> a[i];
		cout << "\nNhan vien thu " << i + 1 << " da duoc them!\n\n";
		system("pause");
		system("cls");
	}
}
void outputData(NV* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "\nNhan vien thu " << i + 1 << endl << endl;
		cout << a[i] << endl << endl;
	}
}