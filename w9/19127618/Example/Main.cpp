#include "Header.h"
void main()
{
	list<int> lI;
	srand(12345);
	int n = rand() % 10 + 10;
	for (int i = 0; i < n; ++i)
		if (rand() % 2 == 0)
			lI.push_back(rand() % 100);
		else
			lI.push_front(1000 + rand() % 100);
	for (list<int>::iterator it = lI.begin(); it != lI.end(); it++)
		cout << *it << ", ";
	cout << endl;
}