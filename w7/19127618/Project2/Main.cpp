#include "Mammal.h"
#include "Dog.h"

int main()
{
	Mammal* pDog = new Dog;
	pDog->move();
	pDog->speak();

	Dog* pDog2 = new Dog;
	pDog2->move();
	pDog2->speak();
	
	delete pDog;
	delete pDog2;
	
	return 0;
}