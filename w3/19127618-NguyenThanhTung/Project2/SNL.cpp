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
SoNguyenLon SoNguyenLon::operator+(const unsigned long&snl)
{
	SoNguyenLon snKQ;
	SoNguyenLon snl2(snl);
	const SoNguyenLon* snlSCSMax = (soCS > snl2.soCS) ? this : &snl;
	const SoNguyenLon* snlSCSMin = (soCS < snl2.soCS) ? this : &snl;
	int soCSMin = (soCS > snl2.soCS) ? snl2.soCS : soCS;
	int nho = 0;
	for (int i = 0; i < snlSCSMin->soCS; ++i)
	{
		snKQ.a
	}
}

