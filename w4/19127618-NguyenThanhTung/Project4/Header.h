#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
using namespace std;
#define pi 3.1415926535

class HinhHocPhang
{
public:
	HinhHocPhang(){};
	~HinhHocPhang(){};
	
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
	~HinhChuNhat();
	double DienTich()
	{
		return (dai * rong);
	}
	double ChuVi()
	{
		return ((dai + rong) * 2);
	}
};

class HinhTamGiac :public HinhHocPhang
{
private:
	double a, b, c;
public:
	HinhTamGiac() :HinhHocPhang() {};
	HinhTamGiac(double aa,double bb,double cc):HinhHocPhang()
	{
		a = abs(aa); b = abs(bb); c = abs(cc);
	}
	double DienTich() override
	{
		double p = ChuVi() / 2;
		double s = sqrt(p * (p - a) * (p - b) * (p - c));
		return s;
	}
	double ChuVi() override
	{
		return (a+b+c);
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
		return (pi * BanKinh * BanKinh);
	}
	double ChuVi() override
	{
		return (pi * 2 * BanKinh);
	}
};

class HinhThangVuong :public HinhHocPhang
{
private:
	double DL, DB, CC;
public:
	HinhThangVuong() : HinhHocPhang() {};
	HinhThangVuong(double dl,double db, double cc)
	{
		DL = dl; DB = db; CC = cc;
	}
	double DienTich() override
	{
		return ((DL + DB) / 2) * CC;
	}
	double ChuVi() override
	{
		double canhben = sqrt(CC * CC + (DL - DB) * (DL - DB));
		return canhben + CC + DL + DB;
	}
};

class QuanLyHinhHocPhang
{
private:
	vector<HinhHocPhang *> QLHHP;
public:
	QuanLyHinhHocPhang();
	~QuanLyHinhHocPhang();
	void AddHinh(HinhHocPhang* aHHP);
	double TongDienTich();
	double TongChuVi();
};
#endif