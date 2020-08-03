#include "HH.h"
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
void QuanLyHinhHocPhang::printDienTich()
{
	if (!QLHHP.empty())
	{
		for (auto i = QLHHP.begin(); i != QLHHP.end(); i++)
		{
			if (*i) {
				cout << (*i)->DienTich() << endl;
			}
		}
	}
}
void QuanLyHinhHocPhang::printChuVi()
{
	if (!QLHHP.empty())
	{
		for (auto i = QLHHP.begin(); i != QLHHP.end(); i++)
		{
			if (*i) {
				cout << (*i)->ChuVi() << endl;
			}
		}
	}
}



QuanLyHinhHoc3D::QuanLyHinhHoc3D()
{
	QLHH3D.resize(0);
}
QuanLyHinhHoc3D::~QuanLyHinhHoc3D()

{
	if (!QLHH3D.empty())
	{
		for (auto i = QLHH3D.begin(); i != QLHH3D.end(); i++)
		{
			if (*i)
				delete (*i);
		}
	}
}
void QuanLyHinhHoc3D::AddHinh(HinhHoc3D* aHHP)
{
	QLHH3D.push_back(aHHP);
}
void QuanLyHinhHoc3D::printDienTichXQ()
{
	if (!QLHH3D.empty())
	{
		for (auto i = QLHH3D.begin(); i != QLHH3D.end(); i++)
		{
			if (*i) {
				cout << (*i)->DienTichXQ() << endl;
			}
		}
	}
}
void QuanLyHinhHoc3D::printTheTich()
{
	if (!QLHH3D.empty())
	{
		for (auto i = QLHH3D.begin(); i != QLHH3D.end(); i++)
		{
			if (*i) {
				cout << (*i)->TheTich() << endl;
			}
		}
	}
}