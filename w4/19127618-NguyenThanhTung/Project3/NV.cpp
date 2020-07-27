#include "Header.h"
NV::NV():Nguoi()
{
	phong_ban = "Null";
	he_so_luong = 0;
	phu_cap = 0;
}
NV::NV(string n, int d, int m, int y, string a, string pb, double hsl, double pc) :Nguoi(n, d, m, y, a)
{
	phong_ban = pb;
	he_so_luong = hsl;
	phu_cap = pc;
}
ostream& operator<<(ostream& os, NV& nv)
{
	os << (Nguoi)nv << endl;
	cout << "Phong ban:  ";
	os << nv.phong_ban << endl;
	cout << "He so luong:  ";
	os << nv.he_so_luong << endl;
	cout << "Phu cap:  ";
	os << nv.phu_cap << endl;
	return os;
}
istream& operator>>(istream& is, NV& nv)
{
	int d, m, y;
	cin.ignore();
	cout << "\nNhap ten:  ";
	getline(is, nv.name);
	cout << "Nhap ngay sinh:  ";
	is >> d;
	cout << "Nhap thang sinh:  ";
	is >> m;
	cout << "Nhap nam sinh:  ";
	is >> y;
	nv.date = inputDate(d, m, y);
	cout << "Nhap dia chi:  ";
	cin.ignore();
	getline(is, nv.address);
	cout << "Nhap phong ban:  ";
	getline(is, nv.phong_ban);
	cout << "Nhap he so luong:  ";
	is >> nv.he_so_luong;
	cout << "Nhap phu cap:  ";
	is >> nv.phu_cap;
	return is;
}