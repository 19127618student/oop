#include "Header.h"
void menu(May& m)
{
	while (true)
	{
		system("cls");
		cout << "1: nhap vao chi tiet may" << endl;
		cout << "2: tim chi tiet" << endl;
		cout << "3: tinh trong luong" << endl;
		cout << "4: tinh gia thanh " << endl;
		cout << "0: thoat." << endl;
		cout << "\nOption: ";
		int op;
		cin >> op;

		if (op == 1)
		{
			system("cls");
			cout << "1: chi tiet don" << endl;
			cout << "2: chi tiet phuc" << endl;
			cout << "\nOption: ";
			int opt;
			cin >> opt;
			if (opt == 1)
			{
				string id;
				double tl, gt;
				cout << "ID: ";
				cin.ignore();
				getline(cin, id);
				cout << "Trong luong: ";
				cin >> tl;
				cout << "Gia thanh: ";
				cin >> gt;
				m.Addd(new ChiTietDon(id, tl, gt));
			}
			else if (opt == 2)
			{
				string id;
				cout << "ID: ";
				cin.ignore();
				getline(cin, id);
				ChiTietPhuc cp(id);

				cout << "Chi tiet gom so chi tiet con: ";
				int n;
				cin >> n;
				for (int i = 0; i < n; i++)
				{
					cout << "Chi tiet con " << i + 1 << ": \n";
					string idd;
					double tl, gt;
					cout << "ID: ";
					cin.ignore();
					getline(cin, idd);
					cout << "Trong luong: ";
					cin >> tl;
					cout << "Gia thanh: ";
					cin >> gt;
					cp.addCTD(idd, tl, gt);

					m.Addd(new ChiTietDon(idd, tl, gt));
				}

				cout << "Chi tiet gom so chi tiet phuc: ";
				int nn;
				cin >> nn;
				for (int i = 0; i < nn; i++)
				{
					cout << "Chi tiet phuc " << i + 1 << ": \n";
					string idd;
					cout << "ID: ";
					cin.ignore();
					getline(cin, idd);
					cp.addCTP(idd);

					m.Addp(new ChiTietPhuc(idd));
				}
				m.Addp(new ChiTietPhuc(cp));
			}
		}
		else if (op == 2)
		{
			cout << "Nhap vao Id muon tim: ";
			string find;
			cin.ignore();
			getline(cin, find);
			m.Seart(find);
			cout << endl;
		}
		else if (op == 3)
		{
			cout << "Trong luong: ";
			cout << m.TinhTrongLuong();
			cout << endl;
		}
		else if (op == 4)
		{
			cout << "Gia thanh: ";
			cout << m.TinhGiaThanh();
			cout << endl;
		}
		else if (op == 0)
		{
			break;
		}
		else break;
		system("pause");
	}
}
