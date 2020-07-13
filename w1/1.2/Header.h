#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct node
{
	string data;
	struct node* pNext;
};
struct list
{
	node* pHead;
	node* pTail;
};
void khoitao(list& l);
node* khoitaonode(string x);
void themvaodau(list& l, node* p);
void themvaocuoi(list& l, node* p);
void xuat(list l);

int read(ifstream& f,list &l);
void display(string* s,int n);
void compare(list l,int n);
#endif
