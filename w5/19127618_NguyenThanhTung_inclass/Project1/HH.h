#ifndef _HH_H_
#define _HHH_H_
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
#define pi 3.1415926535

class HinhHocPhang
{
public:
	HinhHocPhang() {};
	~HinhHocPhang() {};

	virtual double DienTich() = 0;
	virtual double ChuVi() = 0;
};
class HinhChuNhat :public HinhHocPhang
{
private:
	double dai;
	double rong;
public:
	HinhChuNhat() : HinhHocPhang()
	{
		dai = 0; rong = 0;
	}
	HinhChuNhat(double d, double r) :HinhHocPhang()
	{
		dai = d; rong = r;
	}
	~HinhChuNhat(){}
	double DienTich()
	{
		cout << "a = " << dai << ", b = " << rong << "  ";
		cout << "Dien tich hinh chu nhat ";
		return (dai * rong);
	}
	double ChuVi()
	{
		cout << "a = " << dai << ", b = " << rong << "  ";
		cout << "Chu vi hinh chu nhat ";
		return ((dai + rong) * 2);
	}
};
class HinhVuong :public HinhHocPhang
{
private:
	double canh;
public:
	HinhVuong() : HinhHocPhang()
	{
		canh = 0;
	}
	HinhVuong(double c) :HinhHocPhang()
	{
		canh = c;
	}
	~HinhVuong(){}
	double DienTich()
	{
		cout << "a = " << canh << "  ";
		cout << "Dien tich hinh vuong ";
		return (canh*canh);
	}
	double ChuVi()
	{
		cout << "a = " << canh << "  ";
		cout << "Chu vi hinh vuong ";
		return ((canh+canh) * 2);
	}
};
class HinhTamGiac :public HinhHocPhang
{
private:
	double a, b, c;
public:
	HinhTamGiac() :HinhHocPhang() {};
	HinhTamGiac(double aa, double bb, double cc) :HinhHocPhang()
	{
		a = abs(aa); b = abs(bb); c = abs(cc);
	}
	double DienTich() override
	{
		double p = ChuVi() / 2;
		double s = sqrt(p * (p - a) * (p - b) * (p - c));
		cout << "Dien tich hinh tam giac ";
		return s;
	}
	double ChuVi() override
	{
		cout << "a = " << a << " ,b = " << b << " ,c = " << c << "  ";
		cout << "Chu vi hinh tam giac ";
		return (a + b + c);
	}
};
class HinhTron :public HinhHocPhang
{
private:
	double BanKinh;
public:
	HinhTron() :HinhHocPhang() {};
	HinhTron(double bk) :HinhHocPhang()
	{
		BanKinh = bk;
	}
	double DienTich() override
	{
		cout << "r = " << BanKinh << "  ";
		cout << "Dien tich hinh tron ";
		return (pi * BanKinh * BanKinh);
	}
	double ChuVi() override
	{
		cout << "r = " << BanKinh << "  ";
		cout << "Chu vi hinh tron ";
		return (pi * 2 * BanKinh);
	}
};
class QuanLyHinhHocPhang
{
private:
	vector<HinhHocPhang*> QLHHP;
public:
	QuanLyHinhHocPhang();
	~QuanLyHinhHocPhang();
	void AddHinh(HinhHocPhang* aHHP);
	void printDienTich();
	void printChuVi();
};


class HinhHoc3D
{	
public:
	HinhHoc3D() {};
	~HinhHoc3D() {};

	virtual double DienTichXQ() = 0;
	virtual double TheTich() = 0;
	void print()
	{
		cout << "\nChu vi HT: ";
		cout << TheTich();
		cout << endl;
		cout << "Dien tich HT: ";
		cout << DienTichXQ();
		cout << endl << endl;
	}
};

class HinhCau: public HinhHoc3D
{
protected:
	double BanKinh;
public:
	HinhCau() :HinhHoc3D() {};
	HinhCau(double bk) :HinhHoc3D()
	{
		BanKinh = bk;
	}
	double DienTichXQ() override
	{
		cout << "Dien tich xung quanh mat cau ban kinh = " << BanKinh << "  ";
		return (pi * BanKinh * BanKinh * 4);
	}
	double TheTich() override
	{
		cout << "The tich hinh cau ban kinh " << BanKinh << "  ";
		return ((4/3)*pi*BanKinh*BanKinh*BanKinh);
	}
};

class HinhLP:public HinhHoc3D
{
protected:
	double canh;
public:
	HinhLP() {};
	HinhLP(double c)
	{
		canh = c;
	}
	double DienTichXQ() override
	{
		cout << "Dien tich xung quanh hinh lap phuong canh = " << canh << " ";
		return (canh * canh) * 6;
	}
	double TheTich() override
	{
		cout << "The tich hinh lap phuong canh = " << canh << " ";
		return (canh * canh * canh);
	}
};
class QuanLyHinhHoc3D
{
private:
	vector<HinhHoc3D*> QLHH3D;
public:
	QuanLyHinhHoc3D();
	~QuanLyHinhHoc3D();
	void AddHinh(HinhHoc3D* aHH3d);
	void printDienTichXQ();
	void printTheTich();
};
#endif