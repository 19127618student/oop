#include "Header.h"

int main()
{
	if(1)
	{
		int a1[] = { 10, 2, 13, 24 };
		string s1[] = { "Kim Tan", "Bi Rain", "Le Roi", "Tran Trang" };
	
		Hocsinh hs1("nguyen van a", 20, 9.5);
		Hocsinh hs2("nguyen van b", 21, 9.0);
		Hocsinh hs3("nguyen van c", 22, 8.5);
		Hocsinh hs4("nguyen van d", 23, 7.5);
		Hocsinh hs[] = { hs1,hs2,hs3,hs4 };
	
		int n1 = 4;
		Mang<int> mi(a1,n1);
		Mang<string> ms(s1,n1);
		Mang<Hocsinh> mhs(hs,n1);
		cout << "\nNhap them hs: ";
		mhs.nhap();
		cout << "\nNhap them int: ";
		mi.nhap();
		cout << "\nNhap them string: ";
		ms.nhap();
		mhs.ghifile("hocsinh");
		mhs.Sort();
		ms.Sort();
		mi.Sort();
		cout << endl;
		ms.xuat();
		mi.xuat();
		mhs.xuat();
		int kq = ms.timkiem(string("Teo"));
		if (kq >= 0)
			cout << "Tim thay Teo o vi tri " << kq << endl;
		else
			cout << "Khong tim thay Teo" << endl;
	}
	
	
	if(0) // doc file
	{
		Mang<Hocsinh> mhs;
		mhs.docfile("hocsinh");
		mhs.xuat();
		
	}
	return 0;
}