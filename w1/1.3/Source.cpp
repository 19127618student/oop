#include "Header.h"
void loadData(fstream& f, int& n, double**& data)
{
	f >> n;
	data = new double* [n];
	for (int i = 0; i < n; i++)
	{
		data[i] = new double[24];
	}
	for (int i = 0; i < n; i++)
	{
		for(int j=0;j<24;j++)
		{
			f >> data[i][j];
		}
	}
}

void displayData(int n, double** data)
{
	for(int i=0;i<n;i++)
	{
		for (int j = 0; j < 24; j++)
		{
			cout << data[i][j] << " ";
		}
		cout << endl;
	}
}

void printData(fstream& f, int n, double** data)
{
	f << "mon\t\ttus\t\twed\t\tthu\t\tfri\t\tsat\t\tsun";
	double average[7];
	double max[7];
	double min[7];
	printAverage(f, n, data, average);
	printMaxDay(f, n, data, max);
	printMinDay(f, n, data, min);
	
}

void printAverage(fstream& f, int n, double** data, double average[])
{
	f << "\nAverage temperature:\n";
	for(int i=0;i<n;i++)
	{
		double av = 0;
		double sum = 0;
		for(int j=0;j<24;j++)
		{
			sum += data[i][j];
		}
		av = sum / 24;
		average[i] = av;
		
		f << average[i] << "\t\t";
	}
}
void printMaxDay(fstream& f, int n, double** data, double max[])
{
	f << "\nHigh temperature:\n";
	for (int i = 0; i < n; i++)
	{
		double m = 0;
		m = data[i][0];
		for (int j = 0; j < 24; j++)
		{
			if (m < data[i][j]) m = data[i][j];
		}
		max[i] = m;

		f << max[i] << "\t\t";
	}
}

void printMinDay(fstream& f, int n, double** data, double min[])
{
	f << "\nLow temperature:\n";
	for (int i = 0; i < n; i++)
	{
		double m = 0;
		m = data[i][0];
		for (int j = 0; j < 24; j++)
		{
			if (m > data[i][j]) m = data[i][j];
		}
		min[i] = m;

		f << min[i] << "\t\t";
	}
}