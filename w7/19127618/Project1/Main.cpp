#include "Header.h"
int main()
{
	Base* ptr = new Base;
	ptr->testFunction();
	delete ptr;
	ptr = new Derived;
	ptr->testFunction();
	delete ptr;
	return 0;
}