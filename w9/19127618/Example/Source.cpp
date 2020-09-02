#include "Header.h"
void SoNguyenLon::Pow10(const int& n)
{
	for (int i = 0; i < n; ++i)
		lCS.insert(lCS.begin(), 0);
}
SoNguyenLon::SoNguyenLon(void)
{
	lCS.push_back(0);
}
SoNguyenLon::SoNguyenLon(const int& cs, const int& scs)
{
	int csR = cs;
	if (csR < 1)
		csR = 1;
	if (csR > 9)
		csR = 9;
	int soCS = abs(scs);
	if (soCS < 1)
		soCS = 1;
	for (int i = 0; i < soCS; ++i)
		lCS.push_back(csR);
}
SoNguyenLon::SoNguyenLon(const unsigned long& n)
{
	unsigned long temp = n;
	while (temp > 9)
	{
		lCS.push_back(temp % 10);
		temp /= 10;
	}
	lCS.push_back(temp % 10);
}
SoNguyenLon::SoNguyenLon(const SoNguyenLon& snl)
{
	lCS = snl.lCS;
}
SoNguyenLon::~SoNguyenLon(void)
{
}
int SoNguyenLon::SoCS()
{
	return lCS.size();
}
bool SoNguyenLon::operator>(SoNguyenLon& snl)
{
	if (lCS.size() > snl.lCS.size())
		return true;
	if (lCS.size() < snl.lCS.size())
		return false;
	for (int i = 0; i < lCS.size(); i++)
	{
		if (lCS[i] == snl.lCS[i])
			continue;
		if (lCS[i] > snl.lCS[i])
			return true;
		return false;
	}
	return false;
}
const SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& snl)
{
	lCS = snl.lCS;
	return *this;
}
SoNguyenLon& SoNguyenLon::operator+=(SoNguyenLon snl)
{
	int soCSMin = (SoCS() < snl.SoCS()) ? SoCS() : snl.SoCS();
	int nho = 0, temp;
	unsigned char* pTemp;
	for (int i = 0; i < soCSMin; ++i)
	{
		pTemp = &lCS[i];
		*pTemp += snl.lCS[i] + nho;
		nho = *pTemp / 10;
		*pTemp %= 10;
	}
	if (SoCS() == soCSMin)
	{
		for (int i = soCSMin; i < snl.SoCS(); ++i)
		{
			temp = snl.lCS[i] + nho;
			lCS.push_back(temp % 10);
			nho = temp / 10;
		}
	}
	else
	{
		for (int i = soCSMin; i < SoCS(); ++i)
		{
			pTemp = &lCS[i];
			*pTemp += nho;
			nho = *pTemp / 10;
			*pTemp %= 10;
			if (nho == 0)
				break;
		}
	}
	if (nho > 0)
		lCS.push_back(1);
	return *this;
}
SoNguyenLon SoNguyenLon::operator+(SoNguyenLon snl)
{
	SoNguyenLon snlKQ;
	snlKQ.lCS.clear();
	SoNguyenLon* snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
	SoNguyenLon* snlSCSMin = (SoCS() < snl.SoCS()) ? this : &snl;
	int nho = 0, temp;
	for (int i = 0; i < snlSCSMin->SoCS(); ++i)
	{
		temp = lCS[i] + snl.lCS[i] + nho;
		snlKQ.lCS.push_back(temp % 10);
		nho = temp / 10;
	}
	for (int i = snlSCSMin->SoCS(); i < snlSCSMax->SoCS(); ++i)
	{
		temp = snlSCSMax->lCS[i] + nho;
		snlKQ.lCS.push_back(temp % 10);
		nho = temp / 10;
	}
	if (nho > 0)
		snlKQ.lCS.push_back(1);
	return snlKQ;
}
SoNguyenLon SoNguyenLon::operator-(SoNguyenLon snl)
{
	SoNguyenLon snlKQ;
	snlKQ.lCS.clear();
	int nho = 0, i, temp;
	if (SoCS() >= snl.SoCS())
	{
		for (i = 0; i < snl.SoCS(); ++i)
		{
			temp = lCS[i] - snl.lCS[i] - nho;
			nho = 0;
			if (temp < 0)
			{
				temp += 10;
				nho = 1;
			}
			snlKQ.lCS.push_back(temp);
		}
		for (; i < SoCS(); ++i)
		{
			temp = lCS[i] - nho;
			nho = 0;
			if (temp < 0)
			{
				temp += 10;
				nho = 1;
			}
			snlKQ.lCS.push_back(temp);
		}
		while (snlKQ.lCS[snlKQ.lCS.size() - 1] == 0)
		{
			snlKQ.lCS.pop_back();
		}
	}
	return snlKQ;
}
SoNguyenLon SoNguyenLon::operator*(SoNguyenLon snl)
{
	SoNguyenLon snlKQ, * psnlTemp;
	SoNguyenLon* snlSCSMax = (SoCS() > snl.SoCS()) ? this : &snl;
	SoNguyenLon* snlSCSMin = (SoCS() < snl.SoCS()) ? this : &snl;
	int nho = 0, temp;
	for (int i = 0; i < snlSCSMin->SoCS(); ++i)
	{
		psnlTemp = new SoNguyenLon;
		psnlTemp->lCS.clear();
		nho = 0;
		for (int j = 0; j < snlSCSMax->SoCS(); ++j)
		{
			temp = snlSCSMin->lCS[i] * snlSCSMax->lCS[j] + nho;
			psnlTemp->lCS.push_back(temp % 10);
			nho = temp / 10;
		}
		if (nho > 0)
			psnlTemp->lCS.push_back(nho);
		psnlTemp->Pow10(i);
		snlKQ += *psnlTemp;
		delete psnlTemp;
	}
	return snlKQ;
}
SoNguyenLon operator+(const unsigned int& n, const SoNguyenLon& snl)
{
	SoNguyenLon snlTemp(n);
	SoNguyenLon snlKQ = snlTemp + snl;
	return snlKQ;
}
SoNguyenLon operator-(const unsigned int& n, const SoNguyenLon& snl)
{
	SoNguyenLon snlTemp(n);
	return snlTemp - snl;
}
ostream& operator<<(ostream& os, SoNguyenLon& snl)
{
	for (int i = snl.lCS.size() - 1; i >= 0; --i)
		os << (int)snl.lCS[i];
	return os;
}