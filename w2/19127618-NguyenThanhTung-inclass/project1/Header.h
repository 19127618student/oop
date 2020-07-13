#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
using namespace std;
class SoPhuc
{
private:
	int thuc, ao;
public:
	SoPhuc();
	SoPhuc(int t, int a);
	SoPhuc operator+(const int&);
	friend ostream& operator<<(ostream&, const SoPhuc&);
	friend SoPhuc& operator+ (int a, SoPhuc b);
};

#endif
