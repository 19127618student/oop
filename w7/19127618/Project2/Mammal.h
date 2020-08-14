#ifndef _MAMMAL_H_
#define _MAMMAL_H_
#include <iostream>
using namespace std;
class Mammal
{
public:
	Mammal();
	virtual ~Mammal();
	virtual void move()const;
	virtual void speak()const;
protected:
	int itsAge;
};
#endif