#ifndef  _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <fstream>
using namespace std;

struct student
{
	char name[30];
	char address[100];
	int age;
};
void inputData(student& s);
void saveData(ofstream& f, student s);
void displayData(student s);
void loadData(ifstream& f, student& s);
#endif
