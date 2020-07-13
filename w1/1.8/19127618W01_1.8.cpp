#include "Header.h"
int main()
{
	
	student s;
	if (0) {
		ofstream fout;
		inputData(s);
		fout.open("input7.bin", ios::binary);
		if (!fout.is_open())cout << "cant create";
		else
		{
			saveData(fout, s);
			displayData(s);
			fout.close();
		}
	}
	if (1) {
		ifstream fin;
		fin.open("input7.bin", ios::binary);
		if (!fin.is_open())cout << "cant open";
		else
		{
			loadData(fin, s);
			displayData(s);
			fin.close();
		}
	}
	return 0;
}