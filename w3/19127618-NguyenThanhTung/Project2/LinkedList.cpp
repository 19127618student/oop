#include "Header.h"
LinkedList::LinkedList()
{
	pHead = NULL;
	pTail = NULL;
	curN = 0;
}

Node* LinkedList::CreateNode(const int& n)
{
	Node* p = new Node;
	p->data = n;
	p->pNext = NULL;
	p->pPrev = NULL;
	return p;
}
Node* LinkedList::AddHead(const int& n)
{
	Node* p = CreateNode(n);
	if (pHead == NULL) {
		pHead = pTail = p;
	}
	else {
		pHead->pPrev = p;
		p->pNext = pHead;
		pHead = p;
	}
	curN++;
	return pHead;
}
Node* LinkedList::AddTail(const int& n)
{
	Node* p = CreateNode(n);
	if (pHead == NULL) {
		pHead = pTail = p;
	}
	else {
		p->pPrev = pTail;
		pTail->pNext = p;
		pTail = p;
	}
	curN++;
	return pHead;
}
ostream& operator<<(ostream& os, const LinkedList& ll)
{
	for (Node* k = ll.pHead; k != NULL; k = k->pNext) {
		os << k->data;
	}
	return os;
}
Node* LinkedList::RemoveHead()
{
	curN--;
	if (pHead == NULL)
		return NULL;
	Node* temp = pHead;
	pHead = pHead->pNext;
	delete temp;
	return pHead;
}
Node* LinkedList::RemoveTail()
{
	curN--;
	if (pHead == NULL)
		return NULL;

	if (pHead->pNext == NULL) {
		delete pHead;
		return NULL;
	}

	Node* second_last = pHead;
	while (second_last->pNext->pNext != NULL)
		second_last = second_last->pNext;
	delete (second_last->pNext);
	second_last->pNext = NULL;
	pTail = second_last;
	return pHead;
}

