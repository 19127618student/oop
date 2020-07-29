#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <vector>
using namespace std;

class NhanVien
{
protected:
	string HoTen;
	string DiaChi;
public:
	NhanVien()
	{
		HoTen = "Null";
	};
	NhanVien(string ht, string dc)
	{
		HoTen = ht; DiaChi = dc;
	};
	virtual void print(ostream& out)const {};
	friend ostream& operator<<(ostream& os, const NhanVien& nv)
	{
		nv.print(os);
		return os;
	};
	virtual bool isNVXS() const = 0;
};
class CongTy
{
protected:
	vector<NhanVien*> QLNV;
	vector<NhanVien*> NVXS;
public:
	CongTy()
	{
		QLNV.resize(0);
	}
	~CongTy();
	void ThemNhanVien(NhanVien* Nv);
	void DanhSachNV(ostream& os);
	void DanhSachNVXuatSac(ostream& os);
};
class NhanVienThuKy: public NhanVien
{
protected:
	string ChungChi;
	int SL;
public:
	NhanVienThuKy():NhanVien()
	{
		ChungChi = "Null";
		SL = 0;
	}
	NhanVienThuKy(string ht,string dc, string cc,int sl):NhanVien(ht,dc)
	{
		ChungChi = cc;
		SL = sl;
	}
	void print(ostream& out) const override
	{
		out << HoTen << " <" << DiaChi << "> [HN: "<< ChungChi << "], bao cao hoan thanh: "<< SL;
	}
	bool isNVXS() const
	{
		if (SL > 11) return 1;
		else return 0;
	}
};
class NhanVienKyThuat: public NhanVien
{
protected:
	string ChungChi;
	int SL;
public:
	NhanVienKyThuat() :NhanVien()
	{
		ChungChi = "Null";
		SL = 0;
	}
	NhanVienKyThuat(string ht, string dc, string cc, int sl) :NhanVien(ht, dc)
	{
		ChungChi = cc;
		SL = sl;
	}
    void print(ostream& out) const override
	{
		out << HoTen << " <" << DiaChi << "> [Nganh: " << ChungChi << "], sang tao: " << SL;
	}
	bool isNVXS() const
	{
		if (SL > 5) return 1;
		else return 0;
	}
};
#endif