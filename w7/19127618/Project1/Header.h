#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
using namespace std;

class Base
{
public:
	virtual void testFunction();
};

class Derived :public Base
{
public:
	void testFunction() override;
};

#endif