#include "Header.h"

int main()
{
	Mammal* theArray[5];
	Mammal* ptr;
	int choice;
	
	for(int i=0;i<5;i++)
	{
		cout << "(1)dog (2)cat (3)horse (4)guinea pig: ";
		cin >> choice;
		switch (choice)
		{
		case 1: ptr = new Dog;
			break;
		case 2: ptr = new Cat;
			break;
		case 3: ptr = new Horse;
			break;
		case 4: ptr = new GuineaPig;
			break;
		default:ptr = new Mammal;
			break;
		}
		theArray[i] = ptr;
	}
	for(int i=0;i<5;i++)
	{
		theArray[i]->speak();
	}
	for (int i = 0; i < 5; i++)
	{
		delete theArray[i];
	}
	return 0;
}