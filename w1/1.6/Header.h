#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
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
void xuat(list l);

void readData(fstream& f, list& l);
void doSomething(list l, list ls, list &lst);
void save(fstream& f, list l);
#endif