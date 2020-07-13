#include "Header.h"

int main()
{
	fstream f1, f2, f3;
	
	f1.open("input6a.txt", ios::in);
	f2.open("input6b.txt", ios::in);
	if (!f1.is_open() || !f2.is_open())
	{
		cout << "Cant open";
	}
	else
	{
		list l; khoitao(l);
		readData(f1, l);
		xuat(l);
		cout << endl;
		list ls; khoitao(ls);
		readData(f2, ls);
		xuat(ls);
		f1.close();
		f2.close();
		f3.open("output6.txt", ios::out);
		if (!f3.is_open())
		{
			cout << "Cant create";
		}
		else
		{
			cout << endl;
			list lst; khoitao(lst);
			cout << endl;
			doSomething(l, ls, lst);
			xuat(lst);
			save(f3, lst);
			cout << "\nDone!\n";
			f3.close();
		}
	}
	return 0;
}