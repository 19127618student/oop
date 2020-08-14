#include "Header.h"

Mammal::Mammal()
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

Cat::Cat()
{
	cout << "Cat constructor...\n";
}
Cat::~Cat()
{
	cout << "Cat destructor...\n";
}
void Cat::move() const
{
	cout << "Cat moves a step!\n";
}
void Cat::speak() const
{
	cout << "What does a Cat speak? Meow!\n";
}

Horse::Horse()
{
	cout << "Horse constructor...\n";
}
Horse::~Horse()
{
	cout << "Horse destructor...\n";
}
void Horse::move() const
{
	cout << "Horse moves a step!\n";
}
void Horse::speak() const
{
	cout << "What does a Horse speak? Ney!\n";
}

GuineaPig::GuineaPig()
{
	cout << "GuineaPig constructor...\n";
}
GuineaPig::~GuineaPig()
{
	cout << "GuineaPig destructor...\n";
}
void GuineaPig::move() const
{
	cout << "GuineaPig moves a step!\n";
}
void GuineaPig::speak() const
{
	cout << "What does a GuineaPig speak? Wheep WHEEP!\n";
}