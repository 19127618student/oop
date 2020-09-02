#include "myString.h"

int main()
{
	vector<char> punct;
	punct.push_back(' ');
	punct.push_back(',');
	punct.push_back('.');
	punct.push_back(';');
	punct.push_back('\n');
	
	myString ms;
	string name = "input.txt";
	//cout << "Nhap vao duong link file (vi du: D:/input.txt):  "; // file demo trong folder
	//cin >> name;
	fstream f1;
	ifstream f2;
	f2.open(name);
	f1.open(name, ios::in);
	if (!f1.is_open())
	{
		cout << "\nCant open!";
	}
	else
	{
		readData(f1,ms);
		f1.close();
		f2.close();
	}

	vector<myString> vms = ms.Split(punct, 1);
	cout << "Data: \n";
	for(auto i=vms.begin();i!=vms.end();i++)
	{
		cout << *i<<" ";
	}

	cout << endl << "\nTotal size = " << vms.size() << endl << endl;

	map<string,int> mymap = ms.compact(vms);
	cout << endl << "Number of words = " << mymap.size() << endl << endl;

	cout << endl << "The number of occurrence:\n";
	for(auto i = mymap.begin();i!=mymap.end();i++)
	{
		cout << i->first << " : " << i->second << endl;
	}
	cout << endl << endl;
	
	return 0;
}