#include "Header.h"

int main()
{
	int n = 0;
	cout << "Nhap vao n: "; // line thu nhat bat dau tu 0
	cin >> n;
	string name;
	cout << "Nhap vao duong link file (vi du: D:/input.txt):  "; // file demo trong folder
	cin >> name;
	fstream f1;
	ifstream f2;
	f2.open(name);
	//f1.open("D:/input.txt", ios::in);
	f1.open(name, ios::in);
	if (!f1.is_open())
	{
		cout << "Cant open";
	}
	else
	{
		readData(f1, n,f2);
		f1.close();
	}
	return 0;
}