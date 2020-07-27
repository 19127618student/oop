#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
using namespace std;
#define PI 3.14159
class HinhHocPhang
{
public:
	HinhHocPhang(void);
	~HinhHocPhang(void);
	virtual float TinhDienTich();
};
class HinhChuNhat :
	public HinhHocPhang
{
private:
	float chieuDai, chieuRong;
public:
	HinhChuNhat(void);
	HinhChuNhat(const float& cd, const float& cr);
	~HinhChuNhat(void);
	float TinhDienTich();
};

class HinhTron :
	public HinhHocPhang
{
private:
	float banKinh;
public:
	HinhTron(void);
	HinhTron(const float& bk);
	~HinhTron(void);
	float TinhDienTich();
};
#endif