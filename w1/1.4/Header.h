#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <string>
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

void readData(fstream& f, list &l);
int compare(list l1, list l2);
#endif

