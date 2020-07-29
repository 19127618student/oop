#include "Header.h"
QuanLyHinhHocPhang::QuanLyHinhHocPhang()
{
	QLHHP.resize(0);
}
QuanLyHinhHocPhang::~QuanLyHinhHocPhang()

{
	if (!QLHHP.empty())
	{
		for (auto i = QLHHP.begin(); i != QLHHP.end(); i++)
		{
			if (*i)
				delete (*i);
		}
	}
}
void QuanLyHinhHocPhang::AddHinh(HinhHocPhang* aHHP)
{
	QLHHP.push_back(aHHP);
}
double QuanLyHinhHocPhang::TongDienTich()
{
	double TDT = 0;
	if (!QLHHP.empty())
	{
		for (auto i = QLHHP.begin(); i != QLHHP.end(); i++)
		{
			if (*i) {
				TDT += (*i)->DienTich();
			}
		}
	}
	return TDT;
}
double QuanLyHinhHocPhang::TongChuVi()
{
	double TCV = 0;
	if (!QLHHP.empty())
	{
		for (auto i = QLHHP.begin(); i != QLHHP.end(); i++)
		{
			if (*i) {
				TCV += (*i)->ChuVi();
			}
		}
	}
	return TCV;
}