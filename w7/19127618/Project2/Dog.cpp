#include "Dog.h"
#include "Mammal.h"
Dog::Dog()
{
	cout << "Dog constructor...\n";
}
Dog::~Dog()
{
	cout << "Dog destructor...\n";
}
void Dog::move() const
{
	cout << "Dog moves a step!\n";
}
void Dog::speak() const
{
	cout << "What does a Dog speak? Woof!\n";
}
