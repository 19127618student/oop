#include "Header.h"
CongTy::~CongTy()
{
	if (!QLNV.empty())
	{
		for (auto i = QLNV.begin(); i != QLNV.end(); i++)
		{
			if (*i)
				delete* i;
		}
	}
}
void CongTy::ThemNhanVien(NhanVien* Nv)
{
	QLNV.push_back(Nv);
}
void CongTy::DanhSachNV(ostream& os)
{
	if (!QLNV.empty())
	{
		for (auto i = QLNV.begin(); i != QLNV.end(); i++)
		{
			if (*i)
			{
				os << *(*i);
				os << endl;
			}
		}
	}
}
void CongTy::DanhSachNVXuatSac(ostream& os)
{
	if (!QLNV.empty())
	{
		int j = 0;
		for (auto i = QLNV.begin(); i != QLNV.end(); i++)
		{
			if (*i)
			{
				if (QLNV.at(j)->isNVXS())
				{
					os << *(*i);
					os << endl;
				}
			}
			j++;
		}
	}
}