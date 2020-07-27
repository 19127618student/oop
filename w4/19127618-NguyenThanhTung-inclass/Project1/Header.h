#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
using namespace std;
class NhanVien
{
private:
	string hoTen, diaChi;
public:
	NhanVien(void);
	NhanVien(const string& ht, const string& dc);
	~NhanVien(void);
	friend ostream& operator<<(ostream& os, const NhanVien& nv);
};
class NhanVienKyThuat :
	public NhanVien
{
private:
	string chungChiNganh;
public:
	NhanVienKyThuat(void);
	NhanVienKyThuat(const string& ht, const string& dc, const string& cc);
	~NhanVienKyThuat(void);
	friend ostream& operator<<(ostream& os, const NhanVienKyThuat& nvkt);
};

#endif