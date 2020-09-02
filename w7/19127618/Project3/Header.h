#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
using namespace std;

class Mammal
{
public:
	Mammal();
	 ~Mammal();
	virtual void move()const;
	virtual void speak()const;
};

class Dog :public Mammal
{
public:
	Dog();
	~Dog();
	void move() const override;
	void speak() const override;
};

class Cat:public Mammal
{
public:
	Cat();
	~Cat();
	void move() const override;
	void speak() const override;
};

class Horse :public Mammal
{
public:
	Horse();
	~Horse();
	void move() const override;
	void speak() const override;
};

class GuineaPig :public Mammal
{
public:
	GuineaPig();
	~GuineaPig();
	void move() const override;
	void speak() const override;
};
#endif