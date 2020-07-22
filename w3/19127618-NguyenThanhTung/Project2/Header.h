#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* pNext;
	struct Node* pPrev;
};

class LinkedList
{
public:
	Node* pHead, * pTail;
	long unsigned curN;
	
	LinkedList(void);
	~LinkedList(void){};
	static Node* CreateNode(const int& n);
	Node* AddHead(const int& n);
	Node* AddTail(const int& n);
	Node* RemoveHead();
	Node* RemoveTail();
	friend ostream& operator<<(ostream& os, const LinkedList& ll);
};

class SoNguyenLon:public LinkedList
{
private:
	long unsigned soCS;
public:
	SoNguyenLon();
	SoNguyenLon(const long long&);
	SoNguyenLon(const int&, const long unsigned &);
	~SoNguyenLon(){};
	void swap2SNL(SoNguyenLon&, SoNguyenLon&);
	
	SoNguyenLon operator+(const long unsigned&);
	SoNguyenLon operator+(const SoNguyenLon&);
	SoNguyenLon operator-(const SoNguyenLon&);
	SoNguyenLon operator*(const SoNguyenLon&);
	
	friend SoNguyenLon operator-(const int&,const SoNguyenLon&);
};
SoNguyenLon nhanNho(int a, const SoNguyenLon b);
#endif