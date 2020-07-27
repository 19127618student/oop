#include "Header.h"

SoNguyenLon::SoNguyenLon()
{
	soCS = 1;
	AddHead(0);
}
SoNguyenLon::SoNguyenLon(const long long &snl)
{
	soCS = 0;
	long long temp = snl;
	while (temp > 9)
	{
		AddHead(temp % 10);
		temp /= 10;
		soCS++;
	}
	AddHead(temp);
	soCS++;
	curN = soCS;
}
SoNguyenLon::SoNguyenLon(const int &sn, const long unsigned &scs)
{
	int s = sn; long unsigned cs = scs;
	if (sn < 0)
	{
		s = 1;
		cs = 1;
	}
	else if (sn > 9)
	{
		s = 9;
	}
	else s = sn;
	if(scs <1)
	{
		cs = 1;
		s = 0;
	}
	else
	{
		cs = scs;
	}
	soCS = cs;

	for(long unsigned i=0;i<cs;i++)
	{
		AddHead(s);
	}
	
}
void SoNguyenLon::swap2SNL(SoNguyenLon& s1, SoNguyenLon& s2)
{
	SoNguyenLon temp = s1;
	s1 = s2;
	s2 = temp;
}
SoNguyenLon SoNguyenLon::operator+(const unsigned long&snl)
{
	SoNguyenLon snl1 = *this;
	SoNguyenLon snl2(snl);
	SoNguyenLon snlKQ;
	if (snl1.curN < snl2.curN) swap2SNL(snl1, snl2);
	long leng = snl2.curN;
	int nho = 0;
	for(long unsigned i=0;i<leng;i++)
	{
		int temp = nho + snl1.pTail->data + snl2.pTail->data;
		nho = temp / 10;
		if (temp > 9)
			snlKQ.AddHead(temp % 10);
		else snlKQ.AddHead(temp);
		snl1.pTail = snl1.pTail->pPrev;
		snl2.pTail = snl2.pTail->pPrev;
	}
	for(long unsigned i=0;i<snl1.curN-snl2.curN;i++)
	{
		int temp = nho + snl1.pTail->data;
		if (temp > 9) snlKQ.AddHead(temp%10);
		else snlKQ.AddHead(temp);
		nho = 0;
		snl1.pTail = snl1.pTail->pPrev;
	}
	snlKQ.RemoveTail();
	return snlKQ;
}SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon& snl)
{
	SoNguyenLon snl1 = *this;
	SoNguyenLon snl2 = snl;
	SoNguyenLon snlKQ;
	if (snl1.curN < snl2.curN) swap2SNL(snl1, snl2);
	long leng = snl2.curN;
	int nho = 0;
	for (long unsigned i = 0; i < leng; i++)
	{
		int temp = nho + snl1.pTail->data + snl2.pTail->data;
		nho = temp / 10;
		if (temp > 9)
			snlKQ.AddHead(temp % 10);
		else snlKQ.AddHead(temp);
		snl1.pTail = snl1.pTail->pPrev;
		snl2.pTail = snl2.pTail->pPrev;
	}
	for (long unsigned i = 0; i < snl1.curN - snl2.curN; i++)
	{
		int temp = nho + snl1.pTail->data;
		if (temp > 9) snlKQ.AddHead(temp % 10);
		else snlKQ.AddHead(temp);
		nho = 0;
		snl1.pTail = snl1.pTail->pPrev;
	}
	snlKQ.RemoveTail();
	return snlKQ;
}
SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon&snl)
{
	SoNguyenLon snl1 = *this;
	SoNguyenLon snl2 = snl;
	SoNguyenLon snlKQ;
	if (snl1.curN < snl2.curN) swap2SNL(snl1, snl2);
	long leng = snl2.curN;
	int nho = 0;
	//snl1.AddHead(0);
	for (long unsigned i = 0; i < leng; i++)
	{
		int temp = - nho + snl1.pTail->data - snl2.pTail->data;
		nho = 0;
		if (temp < 0) {
			snlKQ.AddHead(temp + 10);
			nho = 1;
		}
		else snlKQ.AddHead(temp);
		snl1.pTail = snl1.pTail->pPrev;
		snl2.pTail = snl2.pTail->pPrev;
	}
	for (long unsigned i = 0; i < snl1.curN - snl2.curN; i++)
	{
		int temp = - nho + snl1.pTail->data;
		if (temp < 0) {
			snlKQ.AddHead(temp + 10);
			nho = 1;
		}
		else snlKQ.AddHead(temp);
		nho = 0;
		snl1.pTail = snl1.pTail->pPrev;
	}
	snlKQ.RemoveTail();
	return snlKQ;
}
SoNguyenLon operator-(const int&snl, const SoNguyenLon&snl2)
{
	SoNguyenLon snl1(snl);
	return snl1 - snl2;
}

SoNguyenLon nhanNho(int a,const SoNguyenLon s)
{
	SoNguyenLon snlKQ;
	SoNguyenLon b = s;
	int temp = 0;
	for (int i = b.curN-1; i >= 0; i--)
	{
		temp = a * b.pTail->data + temp;
		snlKQ.AddHead(temp % 10);
		temp = temp / 10;
		b.pTail = b.pTail->pPrev;
	}
	if (temp > 0)
	{
		snlKQ.AddHead(temp);
	}
	return snlKQ;
}
SoNguyenLon SoNguyenLon::operator*(const SoNguyenLon&snl)
{
	SoNguyenLon snlKQ;
	SoNguyenLon snl1 = *this;
	SoNguyenLon snl2 = snl;
	SoNguyenLon temp;
	int l = snl2.curN;
	for (int i = l-1; i >= 0; i--)
	{
		temp = (nhanNho(snl2.pTail->data, snl1));
		for (int j = 0; j < l - i - 1; j++) {
			temp.AddTail(0);
		}
		snlKQ = snlKQ + temp;
		snl2.pTail = snl2.pTail->pPrev;
	}
	snlKQ.RemoveTail();
	return snlKQ;
}