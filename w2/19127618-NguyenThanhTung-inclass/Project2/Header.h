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
	friend SoPhuc operator+(const int&, const SoPhuc&);
	friend ostream& operator<<(ostream&, const SoPhuc&);
};