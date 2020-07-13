#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <fstream>
using namespace std;

void loadData(fstream& f, int& n, double**& data);
void displayData(int n, double** data);
void printData(fstream &f, int n, double** data);
void printAverage(fstream& f, int n, double** data, double average[]);
void printMaxDay(fstream& f, int n, double** data, double max[]);
void printMinDay(fstream& f, int n, double** data, double min[]);

#endif
