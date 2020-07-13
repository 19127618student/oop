#include "Header.h"

int main()
{
	int n = 0;
	double** data;
	fstream fin;
	fin.open("input3.txt", ios::in);
	if(!fin.is_open())
	{
		cout << "can't open.";
	}
	else
	{
		loadData(fin, n, data);
	//	displayData(n, data);
		fin.close();
		fstream fout;
		fout.open("output3.txt", ios::out);
		if(!fout.is_open())
		{
			cout << "Can't create.";
		}
		else
		{
			printData(fout, n, data);
			/*double average[7];
			double max[7];
			double min[7];
			printAverage(n, data, average);
			printMaxDay(n, data, max);
			printMinDay(n, data, min);*/
			fout.close();
			delete []data;
			cout << "Done!";
		}
	}
	return 0;
}