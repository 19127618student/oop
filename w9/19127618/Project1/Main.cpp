#include "Header.h"

int main()
{
	myString ms1("abcdsf");
	myString ms2 = "____" + ms1;
	myString ms3 = ms1 + ms2;
	cout << "ms1= " << ms1 << endl;
	cout << "ms2= " << ms2 << endl;
	cout << "ms3= " << ms3 << endl << endl;
	myString ms ("a,b,c;d.r;.,h;e,w__u,t.f;j_..");
	vector<char> arrChar;
	arrChar.push_back(',');
	arrChar.push_back('.');
	arrChar.push_back(';');
	arrChar.push_back(' ');
	
	vector<myString> vms = ms.Split(arrChar, false);
	cout << "Split:" << endl;
	for (vector<myString>::iterator itmS = vms.begin(); itmS != vms.end(); itmS++)
	{
		cout << *itmS << " ";
	}
	cout << endl << "size= " << vms.size() << endl << endl;
	vms = ms.Split(arrChar, true);
	cout << "Split co loai bo empty:" << endl;
	for (vector<myString>::iterator itmS = vms.begin(); itmS != vms.end(); itmS++)
	{
		cout << *itmS << " ";
	}
	cout << endl << "size= " << vms.size() << endl << endl;
	
	return 0;
}