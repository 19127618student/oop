#include "Header.h"

void menu(QLTM& C, ThuMuc& bt, ThuMuc& lt, ThuMuc& btc)
{
	system("cls");
	while (true)
	{
		system("cls");

		cout << "1: xuat cay thu muc" << endl;
		cout << "2: dem so luong thu muc va tap tin" << endl;
		cout << "3: tinh kich thuoc" << endl;
		cout << "0: thoat" << endl;

		int op;
		cout << "Option: ";
		cin >> op;
		cout << endl;
		if (op == 0)
		{
			break;
		}
		else if (op == 1)
		{
			C.getName();
		}
		else if (op == 2)
		{
			while (true) {
				system("cls");

				cout << "1: [C:]" << endl;
				cout << "2: [Bai tap]" << endl;
				cout << "3: [Ly thuyet]" << endl;
				cout << "4: [Bai tap C]" << endl;
				cout << "0: thoat " << endl;

				cout << "Option: ";
				int opt;
				cin >> opt;
				cout << endl;

				if (opt == 0)
				{
					break;
				}
				else if (opt == 1)
				{
					cout << "So tap tin va thu muc: " << C.SoLuong() << endl;
				}
				else if (opt == 2)
				{
					cout << "So tap tin va thu muc: " << bt.SoLuong() << endl;
				}
				else if (opt == 3)
				{
					cout << "So tap tin va thu muc: " << lt.SoLuong() << endl;
				}
				else if (opt == 4)
				{
					cout << "So tap tin va thu muc: " << btc.SoLuong() << endl;
				}
				else break;
				cout << endl;
				system("pause");
			}
		}
		else if (op == 3)
		{
			while (true) {
				system("cls");

				cout << "1: [C:]" << endl;
				cout << "2: [Bai tap]" << endl;
				cout << "3: [Ly thuyet]" << endl;
				cout << "4: [Bai tap C]" << endl;
				cout << "0: thoat " << endl;

				cout << "Option: ";
				int opt;
				cin >> opt;
				cout << endl;

				if (opt == 0)
				{
					break;
				}
				else if (opt == 1)
				{
					cout << "Kich thuoc: " << C.getSize() << " B" << endl;
				}
				else if (opt == 2)
				{
					cout << "Kich thuoc: " << bt.getSize() << " B" << endl;
				}
				else if (opt == 3)
				{
					cout << "Kich thuoc: " << lt.getSize() << " B" << endl;
				}
				else if (opt == 4)
				{
					cout << "Kich thuoc: " << btc.getSize() << " B" << endl;
				}
				else break;
				cout << endl;
				system("pause");
			}
		}
		else break;
		cout << endl;
		system("pause");
	}
}