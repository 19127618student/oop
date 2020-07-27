#include "Header.h"
HinhTron::HinhTron(void)
{
}
HinhTron::HinhTron(const float& bk)
{
	banKinh = (bk == 0) ? 1 : abs(bk);
}
HinhTron::~HinhTron(void)
{
}
float HinhTron::TinhDienTich()
{
	return PI * banKinh * banKinh;
}