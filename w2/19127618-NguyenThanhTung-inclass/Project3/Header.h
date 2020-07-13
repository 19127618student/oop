#include <iostream>
using namespace std;
class SoPhuc
{
private:
	int thuc, ao;
public:
	SoPhuc();
	SoPhuc(int t, int a);
	SoPhuc(const int&);
	SoPhuc operator+(const SoPhuc&);
	friend ostream& operator<<(ostream&, const SoPhuc&);
};