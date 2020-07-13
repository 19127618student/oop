#include "Header.h"

int main()
{
	fstream f1, f2;
	f1.open("input4a.txt", ios::in);
	if (!f1.is_open())
	{
		cout << "Cant open";
	}
	else
	{
		list ls; khoitao(ls);
		readData(f1, ls);
		xuat(ls);
		f1.close();
		f2.open("input4b.txt", ios::in);
		if (!f2.is_open())
		{
			cout << "Cant open";
		}
		else
		{
			cout << endl;
			list lst; khoitao(lst);
			readData(f2, lst);
			xuat(lst);
			cout << endl;
			/*if (compare(ls, lst)) cout << "No different";
			else compare(ls, lst);*/
			compare(ls, lst);
			f2.close();
		}
	}
	return 0;
}