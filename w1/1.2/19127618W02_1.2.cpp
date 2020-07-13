// linked list version.(I did it in class by vector)
#include "Header.h"

int main()
{
	ifstream fin;
	list l; khoitao(l);
	fin.open("input.txt");
	if (!fin.is_open()) cout << "cant open";
	else
	{
		int n = 0;
		n = read(fin, l); cout << endl;
		xuat(l);
		compare(l,n);
		fin.close();
	}
	cout << endl;
	return 0;
}