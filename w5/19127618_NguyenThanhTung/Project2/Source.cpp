#include "Header.h"
void menu(QLNV& ql)
{
	while (true)
	{
		system("cls");
		cout << "1: them danh sach" << endl;
		cout << "2: them 1 nv" << endl;
		cout << "3: so luong nv" << endl;
		cout << "4: so luong nvql" << endl;
		cout << "5: xuat danh sach" << endl;
		cout << "0: thoat" << endl;

		cout << "\nOption: ";
		int op;
		cin >> op;

		if (op == 1)
		{
			while (true)
			{
				system("cls");
				cout << "1: nhan vien san xuat" << endl;
				cout << "2: nhan vien cong nhat" << endl;
				cout << "3: nhan vien quan ly" << endl;
				cout << "0: thoat" << endl;

				cout << "\nOption: ";
				int opt;
				cin >> opt;

				int n = 0;
				if (opt != 0) {
					cout << "So luong nv: ";
					cin >> n;
				}

				if (opt == 1)
				{
					for (int i = 0; i < n; i++)
					{
						int id, sl;
						string name;
						cout << "\nID: ";
						cin >> id;
						cout << "Ten: ";
						cin.ignore();
						getline(cin, name);
						cout << "So luong sp: ";
						cin >> sl;
						ql.add(new NVSX(id, name, sl));
					}
				}
				else if (opt == 2)
				{
					for (int i = 0; i < n; i++)
					{
						int id, sl;
						string name;
						cout << "\nID: ";
						cin >> id;
						cout << "Ten: ";
						cin.ignore();
						getline(cin, name);
						cout << "So ngay cong: ";
						cin >> sl;
						ql.add(new NVCN(id, name, sl));
					}
				}
				else if (opt == 3)
				{
					for (int i = 0; i < n; i++)
					{
						int id;
						string name;
						double hsl, lcb;
						cout << "\nID: ";
						cin >> id;
						cout << "Ten: ";
						cin.ignore();
						getline(cin, name);
						cout << "Luong co ban: ";
						cin >> lcb;
						cout << "He so luong: ";
						cin >> hsl;
						ql.add(new NVQL(id, name, lcb, hsl));
					}
				}
				else if (opt == 0)
				{
					break;
				}
				else break;
				system("pause");
			}
		}
		else if (op == 2)
		{
			while (true)
			{
				system("cls");
				cout << "1: nhan vien san xuat" << endl;
				cout << "2: nhan vien cong nhat" << endl;
				cout << "3: nhan vien quan ly" << endl;
				cout << "0: thoat" << endl;

				cout << "Option: ";
				int opt;
				cin >> opt;

				int n = 1;

				if (opt == 1)
				{
					for (int i = 0; i < n; i++)
					{
						int id, sl;
						string name;
						cout << "\nID: ";
						cin >> id;
						cout << "Ten: ";
						cin.ignore();
						getline(cin, name);
						cout << "So luong sp: ";
						cin >> sl;
						ql.add(new NVSX(id, name, sl));
					}
				}
				else if (opt == 2)
				{
					for (int i = 0; i < n; i++)
					{
						int id, sl;
						string name;
						cout << "\nID: ";
						cin >> id;
						cout << "Ten: ";
						cin.ignore();
						getline(cin, name);
						cout << "So ngay cong: ";
						cin >> sl;
						ql.add(new NVCN(id, name, sl));
					}
				}
				else if (opt == 3)
				{
					for (int i = 0; i < n; i++)
					{
						int id;
						string name;
						double hsl, lcb;
						cout << "\nID: ";
						cin >> id;
						cout << "Ten: ";
						cin.ignore();
						getline(cin, name);
						cout << "Luong co ban: ";
						cin >> lcb;
						cout << "He so luong: ";
						cin >> hsl;
						ql.add(new NVQL(id, name, lcb, hsl));
					}
				}
				else if (opt == 0)
				{
					break;
				}
				else break;
				system("pause");
			}
		}
		else if (op == 3)
		{
			cout << "\nSo luong nhan vien: ";
			cout << QLNV::slnv;
			cout << endl;
		}
		else if (op == 4)
		{
			cout << "So luong nhan vien quan li: ";
			cout << NVQL::SLQL << endl;
		}
		else if (op == 5)
		{
			ql.display();
		}
		else if (op == 6)
		{
			break;
		}
		else
		{
			break;
		}
		system("pause");
	}
}