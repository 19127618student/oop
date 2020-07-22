#include "Header.h"
SoNguyenLon::SoNguyenLon(void)
{
	soCS = 1;
	mangSo[soCS - 1] = 0;
	if (*this > snlMax)
	{
		snlMax = *this;
	}
}
SoNguyenLon::SoNguyenLon(const int& cs, const int& scs)
{
	int csR = cs;
	if (csR < 1)
	{
		csR = 1;
	}
	if (csR > 9)
	{
		csR = 9;
	}
	soCS = abs(scs);
	if (soCS < 1)
	{
		soCS = 1;
	}
	if (soCS > MAXLEN)
	{
		soCS = MAXLEN;
	}
	for (int i = 0; i < soCS; ++i)
	{
		mangSo[i] = cs;
	}
	if (*this > snlMax)
	{
		snlMax = *this;
	}
}
SoNguyenLon::SoNguyenLon(const unsigned int& n)
{
	unsigned int temp = n;
	soCS = 0;
	while (temp > 9)
	{
		mangSo[soCS++] = temp % 10;
		temp /= 10;
	}
	mangSo[soCS++] = temp;
	if (*this > snlMax)
	{
		snlMax = *this;
	}
}
SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl)
{
	soCS = snl.soCS;
	for (int i = 0; i < soCS; ++i)
	{
		mangSo[i] = snl.mangSo[i];
	}
}
SoNguyenLon::~SoNguyenLon(void)
{
}
bool SoNguyenLon::operator>(const SoNguyenLon& snl)
{
	if (soCS > snl.soCS)
	{
		return true;
	}
	if (soCS < snl.soCS)
	{
		return false;
	}
	for (int i = soCS - 1; i >= 0; --i)
	{
		if (mangSo[i] == snl.mangSo[i])
		{
			continue;
		}
		if (mangSo[i] > snl.mangSo[i])
		{
			return true;
		}
		return false;
	}
	return false;
}
const SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& snl)
{
	soCS = snl.soCS;
	for (int i = 0; i < soCS; ++i)
	{
		mangSo[i] = snl.mangSo[i];
	}
	return *this;
}
SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon& snl)
{
	SoNguyenLon snlKQ;
	const SoNguyenLon* snlSCSMax = (soCS > snl.soCS) ? this : &snl;
	const SoNguyenLon* snlSCSMin = (soCS < snl.soCS) ? this : &snl;
	int soCSMin = (soCS > snl.soCS) ? snl.soCS : soCS;
	int nho = 0;
	for (int i = 0; i < snlSCSMin->soCS; ++i)
	{
		snlKQ.mangSo[i] = mangSo[i] + snl.mangSo[i] + nho;
		nho = snlKQ.mangSo[i] / 10;
		snlKQ.mangSo[i] %= 10;
	}
	for (int i = snlSCSMin->soCS; i < snlSCSMax->soCS; ++i)
	{
		snlKQ.mangSo[i] = snlSCSMax->mangSo[i] + nho;
		nho = snlKQ.mangSo[i] / 10;
		snlKQ.mangSo[i] %= 10;
	}
	snlKQ.soCS = snlSCSMax->soCS;
	if (nho > 0)
	{
		snlKQ.mangSo[snlKQ.soCS++] = 1;
	}
	if (snlKQ > snlMax)
	{
		snlMax = snlKQ;
	}
	return snlKQ;
}
SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon& snl)
{
	SoNguyenLon snlKQ;
	int nho = 0, i;
	if (soCS >= snl.soCS)
	{
		for (i = 0; i < snl.soCS; ++i)
		{
			snlKQ.mangSo[i] = mangSo[i] - snl.mangSo[i] - nho;
			nho = 0;
			if (snlKQ.mangSo[i] < 0)
			{
				snlKQ.mangSo[i] += 10;
				nho = 1;
			}
		}
		for (; i < soCS; ++i)
		{
			snlKQ.mangSo[i] = mangSo[i] - nho;
			nho = 0;
			if (snlKQ.mangSo[i] < 0)
			{
				snlKQ.mangSo[i] += 10;
				nho = 1;
			}
		}
		snlKQ.soCS = soCS;
		while (snlKQ.mangSo[snlKQ.soCS - 1] == 0)
		{
			snlKQ.soCS--;
		}
	}
	return snlKQ;
}
SoNguyenLon operator+(const unsigned int& n, const SoNguyenLon& snl)
{
	SoNguyenLon snlTemp(n);
	SoNguyenLon snlKQ = snlTemp + snl;
	if (snlKQ > SoNguyenLon::snlMax)
	{
		SoNguyenLon::snlMax = snlKQ;
	}
	return snlKQ;
}
SoNguyenLon operator-(const unsigned int& n, const SoNguyenLon& snl)
{
	SoNguyenLon snlTemp(n);
	return snlTemp - snl;
}
ostream& operator<<(ostream& os, const SoNguyenLon& snl)
{
	for (int i = snl.soCS - 1; i >= 0; --i)
	{
		os << snl.mangSo[i];
	}
	return os;
}
SoNguyenLon SoNguyenLon::SNLMax()
{
	return snlMax;
}