#include "Mammal.h"
Mammal::Mammal():itsAge(1)
{
	cout << "Mammal constructor...\n";
}
Mammal::~Mammal()
{
	cout << "Mammal destructor...\n";
}

void Mammal::move() const
{
	cout << "Mammal moves a step!\n";
}
void Mammal::speak() const
{
	cout << "What does a mammal speak? Mammilian!\n";
}
