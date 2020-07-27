#include "Header.h"

int main()
{
	HinhHocPhang* hhp = new HinhHocPhang();
	HinhChuNhat* hcn = new HinhChuNhat(34, 56.8);
	HinhTron* ht = new HinhTron(73.9);
	cout << hhp->TinhDienTich() << "\t" << hcn->TinhDienTich()
		<< "\t" << ht->TinhDienTich();
	cout << endl;
	//vì HinhChuNhat là một loại HinhHocPhang nên có thể gán
	delete hhp;
	hhp = hcn;
	cout << hhp->TinhDienTich() << endl;
	cout << endl << endl;
	delete hcn;
	delete ht;
	return 0;
}