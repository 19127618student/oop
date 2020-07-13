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
		cout << k->data << endl;
	}
}
void readData(fstream& f, list& l)
{
	string s;
	while (getline(f, s))
	{
		node* p = khoitaonode(s);
		themvaocuoi(l, p);
	}
}
int lengths(string s)
{
	int leng = 0;
	leng = s.length();
	int pos = 0;
	char* temp = new char[leng];
	for (int i=0;i<leng;i++)
	{
		temp[i] = s[i];
	}
	for (int i = 0; i < leng; i++)
	{
		pos++;
		if (temp[i] == ':') break;
	}
	delete []temp;
	return pos;
}
void doSomething(list l, list ls, list& lst)
{
	while (l.pHead != NULL)
	{
		int leng = lengths(l.pHead->data);
		while (ls.pHead != NULL)
		{
			int length = lengths(ls.pHead->data);
			if (leng == length)
			{
				int flag = 0;
				for (int i = 0; i < leng; i++)
				{
					flag = 0;
					if (l.pHead->data[i] == ls.pHead->data[i])
					{
						flag = 1;
					}
					else
					{
						flag = 0;
						break;
					}
				}
				if (flag == 1) {
					char* temp = new char[ls.pHead->data.length()];
					int k = 0;
					for(int i=length-1;i<ls.pHead->data.length()+1;i++)
					{
						temp[k] = ls.pHead->data[i];
						k++;
					}
					
					string t = l.pHead->data + temp;
					node*p = khoitaonode(t);
					themvaocuoi(lst, p);
					
				}
					l.pHead = l.pHead->pNext;
					ls.pHead = ls.pHead->pNext;
			}
		}
	}
	
}

void save(fstream &f, list l)
{
	while (l.pHead!=NULL)
	{
		f << l.pHead->data << endl;
		l.pHead = l.pHead->pNext;
	}
}