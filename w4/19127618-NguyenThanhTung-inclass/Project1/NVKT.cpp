#include "Header.h"
NhanVienKyThuat::NhanVienKyThuat(void)
	: NhanVien()
{
	chungChiNganh = "";
}
NhanVienKyThuat::NhanVienKyThuat(const string& ht, const string& dc, const string&
	cc)
	: NhanVien(ht, dc)
{
	chungChiNganh = cc;
}
NhanVienKyThuat::~NhanVienKyThuat(void)
{
}
ostream& operator<<(ostream& os, const NhanVienKyThuat& nvkt)
{
	//làm sao để xuất thông tin private ở trong class NhanVien?
	//vì quan hệ IS-A nên hoàn toàn có thể coi NhanVienKyThuat
	//là một loại NhanVien
	os << (NhanVien)nvkt;
	os << " [" << nvkt.chungChiNganh << "]";
	return os;
}