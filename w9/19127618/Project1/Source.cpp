#include "Header.h"
myString::myString()
{
	Data = "";
}
myString::myString(string a)
{
	Data = a;
}
void myString::setData(string data)
{
	Data = data;
}
myString operator+(const myString& data1, const myString& data2)
{
	myString data;
	data.setData(data2.Data + data1.Data);
	return data;
}
myString operator+(const string& data1, const myString& data2)
{
	myString data;
	data.setData(data1 + data2.Data);
	return data;
}
ostream& operator<< (ostream& os, const myString& data)
{
	os << data.Data;
	return os;
}
vector<myString> myString::Split(vector<char> a, bool flag)
{
	vector<myString> data;
	string str;
	myString test;
	for (int i = 0; i < Data.length(); i++)
	{
		if (flag == 1 && checkspace(a, Data[i], Data[i + 1]))
		{

		}
		else if (check(a, Data[i]))
		{
			str += Data[i];
		}
		else
		{
			test = str;
			data.push_back(test);
			str.clear();
		}
	}
	test = str;
	if (!str.empty() && flag == 1) data.push_back(test);
	else if (flag == 0 && checkspace(a,Data[Data.size()-2],Data[Data.size()-3]))
	{
		myString t("");
		data.push_back(t);
		data.push_back(test);
	}
	else if (flag == 0 && checkspace(a, Data[Data.size() - 2], Data[Data.size() - 3])==0) data.push_back(test);
	
	return data;
}
bool myString::check(vector<char>a, char c)
{
	bool f = 0;
	if (a.size() == 0) return 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a.at(i) != c) { f = 1; }
		else
		{
			f = 0;
			return 0;
		}
	}
	if (f == 1)return 1;
}
bool myString::checkspace(vector<char>a, char c, char cc)
{
	bool f = 0;
	if (a.size() == 0) return 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (check(a, c) == 0 && check(a, cc) == 0) f = 1;
		else return 0;
	}
	if (f == 1)return 1;
}