#include "Header.h"

long long howManyLine(ifstream &f1)
{
	string s;
	int numlines = 0;
	while (getline(f1, s)) numlines++;
	return numlines;
}
void readData(fstream& f, int n, ifstream &f1)
{
	string s;
	int count = 0;
	long long numline = howManyLine(f1);
	cout << numline<<endl;
	while (getline(f, s))
	{
		if (count >= numline-n) {
			cout << s<<endl;
		}
		count++;
	}
}