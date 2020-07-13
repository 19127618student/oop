#include "Header.h"

void khoitao(list& l) {
	l.pHead = NULL;
	l.pTail = NULL;

}
node* khoitaonode(string x) {
	node* p = new node;
	p->data = x;
	p->pNext = NULL;
	return p;
}
void themvaodau(list& l, node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void xuat(list l) {
	for (node* k = l.pHead; k != NULL; k = k->pNext) {
		cout << k->data << endl;
	}
}
void readData(fstream& f, list &l)
{
	string s;
	while (getline(f, s))
	{
		node* p = khoitaonode(s);
		themvaodau(l, p);
	}
}
int compare(list l1, list l2)
{
	bool flag = 0;
	node* p1 = l1.pHead;
	node* p2 = l2.pHead;
	while (p1!=NULL && p2!=NULL)
	{
		if (p1->data == p2->data)
		{
			flag = 1;
		}
		else
		{
			cout << endl;
			cout << "<" << p1->data;
			cout << endl;
			cout << ">" << p2->data;
			cout << endl;
			flag = 0;
			//break;
		}
		p1 = p1->pNext;
		p2 = p2->pNext;
	}
	return flag;
}
