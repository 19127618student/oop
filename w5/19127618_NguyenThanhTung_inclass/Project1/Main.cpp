#include "HH.h"
void Menu(QuanLyHinhHocPhang &ql, QuanLyHinhHoc3D& ql3d)
{
	while (true) {
		system("cls");
		cout << "Press 1 to add hinh chu nhat" << endl;
		cout << "Press 2 to add hinh tam giac" << endl;
		cout << "Press 3 to add hinh tron" << endl;
		cout << "Press 4 to add hinh vuong" << endl;
		cout << "Press 5 to add hinh cau" << endl;
		cout << "Press 6 to add hinh lap phuong" << endl;
		cout << "Press 0 to display data and exit." << endl << endl;
		
		int op;
		cout << "Enter option: ";
		cin >> op;
		
		if (op == 1)
		{
			double d = 0; double r = 0;
			cout << "dai = "; cin >> d;
			cout << "rong = "; cin >> r;
			ql.AddHinh(new HinhChuNhat(d, r));
		}
		else if (op == 2)
		{
			double x = 0;
			cout << "canh = ";
			cin >> x;
			ql.AddHinh(new HinhTamGiac(x,x,x));
		}
		else if (op == 3)
		{
			double r;
			cout << "Ban kinh = ";
			cin >> r;
			ql.AddHinh(new HinhTron(r));
		}
		else if (op == 4)
		{
			double canh;
			cout << "Canh = ";
			cin >> canh;
			ql.AddHinh(new HinhVuong(canh));
		}
		else if (op == 5)
		{
			double r;
			cout << "Ban kinh = ";
			cin >> r;
			ql3d.AddHinh(new HinhCau(r));
		}
		else if (op == 6)
		{
			double canh;
			cout << "Canh = ";
			cin >> canh;
			ql3d.AddHinh(new HinhLP(canh));
		}
		else if (op == 0)
		{
			cout << "2D\n";
			ql.printChuVi();
			cout << endl;
			cout << endl;
			ql.printDienTich();
			cout << endl << endl;
			
			cout << "\n3D\n";
			ql3d.printDienTichXQ();
			cout << endl;
			cout << endl;
			ql3d.printTheTich();
			cout << endl;
			cout << endl;
			break;
		}
		else break;
		system("pause");
	}
}
int main()
{
	QuanLyHinhHocPhang ql;
	QuanLyHinhHoc3D ql3d;
	Menu(ql,ql3d);
	return 0;
}