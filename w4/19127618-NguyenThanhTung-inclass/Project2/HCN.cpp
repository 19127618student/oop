#include "Header.h"
HinhChuNhat::HinhChuNhat(void)
{
}
HinhChuNhat::HinhChuNhat(const float& cd, const float& cr)
{
	chieuDai = (cd == 0) ? 1 : abs(cd);
	chieuRong = (cr == 0) ? 1 : abs(cr);
}
HinhChuNhat::~HinhChuNhat(void)
{
}
float HinhChuNhat::TinhDienTich()
{
	return chieuDai * chieuRong;
}
