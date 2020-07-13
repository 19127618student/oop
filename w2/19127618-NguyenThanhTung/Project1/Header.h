#ifndef _HEADER_H_
#define _HEADER_H_
#include "Date.h"
#include <iostream>
using namespace std;

struct sp
{
	int day = 1, month = 1, year = 1;
};
bool isLeapYear(int year);
int howManyLeapYear(int month, int year);
int howManyLeapDay(int day);

#endif

