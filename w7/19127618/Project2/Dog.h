#ifndef _DOG_H_
#define _DOG_H_
#include <iostream>
#include "Mammal.h"
using namespace std;

class Dog:public Mammal
{
public:
	Dog();
	~Dog();
	void move() const override;
	void speak() const override;
};
#endif