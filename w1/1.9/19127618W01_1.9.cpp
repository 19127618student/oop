#include "Header.h"

int main()
{
	//ex1
	char* ex1;
	//ex2
	char** ex2;
	//ex3
	char* ex3[10];
	//ex4
	char(*ex4)[30];
	//ex5
	char(*ex5[10])[500];
	//ex6
	extern int* const ex6;
	//ex7
	const int* ex7;
	//ex8
	char pc;
	char *b;
	b = ex8(&pc);
	//ex9
	int pi; cout << "pi = "; cin >> pi;
	float *x;
	x = ex9(&pi);
	//ex10
	
	ex10(&pi);
	cout << endl;
	system("pause");
	//ex11
	ex11();
	return 0;
}