#pragma once
#ifndef _HEADER_H
#define _HEADRE_H
#include <string>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class myString
{
private:
	string Data;
public:
	myString();
	myString(string a);
	void setData(string data);

	friend myString operator+(const myString& data1, const myString& data2);
	friend myString operator+(const string& data1, const myString& data2);
	friend ostream& operator<< (ostream& os, const myString& data);
	vector<myString> Split(vector<char> a, bool flag);
	bool check(vector<char>a, char c);
	bool checkspace(vector<char>a, char c, char cc);
};
#endif