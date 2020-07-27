#include "Header.h"
NhanVien::NhanVien(void)
{
	hoTen = "";
	diaChi = "";
}
NhanVien::NhanVien(const string& ht, const string& dc)
{
	hoTen = ht;
	diaChi = dc;
}
NhanVien::~NhanVien(void)
{
}
ostream& operator<<(ostream& os, const NhanVien& nv)
{
	os << nv.hoTen << " (" << nv.diaChi << ")";
	return os;
}