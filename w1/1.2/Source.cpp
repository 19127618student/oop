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
void themvaocuoi(list& l, node* p) {
	if (l.pHead == NULL) {
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void xuat(list l) {
	for (node* k = l.pHead; k != NULL; k = k->pNext) {
		cout << k->data << " ";
	}
}
int read(ifstream& f, list&l)
{
	string temp;
	int i = 0;
	while (f >> temp)
	{
		
		node* p = khoitaonode(temp);
		themvaocuoi(l, p);
		i++;
	}
	return i;
}

void compare(list l,int n)
{
	int* flag = new int[n];
	for (int i = 0; i < n; i++) flag[i] = 1;
	int j = 0;
	while (l.pHead!=NULL)
	{
		node* cur = l.pHead->pNext;
		while (cur!=NULL)
		{
			if(l.pHead->data==cur->data)
			{
				flag[j] = 0;
			}
			cur = cur->pNext;
		}
		j++;
		l.pHead = l.pHead->pNext;
	}
	int sum = 0;
	for (int i = 0; i < n; i++) sum += flag[i];
	cout << "\n\nNumber of distinct words: " << sum;
}