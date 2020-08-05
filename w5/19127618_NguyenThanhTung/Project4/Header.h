#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class interface
{
public:
	virtual void getName() {};
	virtual double getSize() = 0 {};
	virtual int SoLuong() = 0 {};
};

class TapTin :
	public interface
{
protected:
	string Ten;
	double KichThuoc;
public:
	TapTin() {}
	TapTin(const string& t, const double& kt)
	{
		Ten = t;
		KichThuoc = kt;
	}
	void setTen(const string& t)
	{
		Ten = t;
	}
	void setKT(const double& kt)
	{
		KichThuoc = kt;
	}
	void getName() override
	{
		cout << "\t\t" << Ten << "\t  " << KichThuoc << " B\n";
	}
	double getSize() override
	{
		return KichThuoc;
	}
	string getT()
	{
		return Ten;
	}
	void disIF()
	{
		cout << getT() << "" << KichThuoc << " B" << endl;
	}
	int SoLuong() override { return 1; }
};

class ThuMuc :
	public TapTin, public interface
{
protected:
	string Name;
	double Size;
	vector<TapTin*> TT;
	vector<ThuMuc*> TM;
	int SL;
public:
	static int k;

	ThuMuc()
	{
		TT.resize(0);
		Size = 0;
		SL = 0;
	}
	ThuMuc(const string& n)
	{
		TT.resize(0);
		Name = n;
		SL = 0;
	}
	void setName(const string& n)
	{
		Name = n;
	}
	void setSize(const double& s)
	{
		Size = s;
	}
	void disIF()
	{
		cout << "[" << Name << "]" << endl;
	}
	void getName() override
	{
		for (int j = 0; j < k - 1; j++) { cout << "\t  "; }
		cout << "[" << Name << "]" << endl;
		for (int j = 0; j < k - 2; j++) { cout << "\t  "; }

		if (!TT.empty()) {
			for (auto i = TT.begin(); i != TT.end(); i++)
				if (*i) {
					(*i)->getName();
					k++;
				}
		}
		//for (int j = 0; j < k; j++) { cout << "\t"; }
		if (!TM.empty())
			for (auto i = TM.begin(); i != TM.end(); i++)
				if (*i)
				{
					k++;
					(*i)->getName();
				}
	}

	double getSize() override
	{
		if (!TT.empty())
			for (auto i = TT.begin(); i != TT.end(); i++)
				if (*i) Size += (*i)->getSize();
		if (!TM.empty())
			for (auto i = TM.begin(); i != TM.end(); i++)
				if (*i) Size += (*i)->getSize();
		return Size;
	}
	void addFile(TapTin* tt)
	{
		TT.push_back(tt);
		SL++;
	}
	void addFolder(ThuMuc* tm)
	{
		TM.push_back(tm);
		SL++;
	}
	int SoLuong()
	{
		return SL;
	}
};

class QLTM :
	public interface
{
protected:
	vector<ThuMuc*>TM;
	vector<QLTM*>QL;
	string name;
	double SiZe;
	int SL;
public:
	static int kk;
	QLTM()
	{
		QL.resize(0);
		TM.resize(0);
		SiZe = 0;
		SL = 0;
	}
	QLTM(const string& n)
	{
		name = n;
		SiZe = 0;
		SL = 0;
		QL.resize(0);
		TM.resize(0);
	}
	void addTM(ThuMuc* tm)
	{
		TM.push_back(tm);
		SL++;
	}
	void addQLTM(QLTM* ql)
	{
		QL.push_back(ql);
		SL++;
	}
	void getName() override
	{
		cout << "[" << name << "]\n";
		if (!TM.empty())
			for (auto i = TM.begin(); i != TM.end(); i++)
				if (*i)
				{
					ThuMuc::k = kk;
					cout << "\t";
					(*i)->getName();
				}
		if (!QL.empty())
			for (auto i = QL.begin(); i != QL.end(); i++)
				if (*i)
				{
					ThuMuc::k = kk;
					kk++;
					(*i)->getName();
				}
	}
	double getSize() override
	{
		if (!TM.empty())
			for (auto i = TM.begin(); i != TM.end(); i++)
				if (*i)
				{
					SiZe += (*i)->getSize();
				}
		if (!QL.empty())
			for (auto i = QL.begin(); i != QL.end(); i++)
				if (*i)
				{
					SiZe += (*i)->getSize();
				}
		return SiZe;
	};
	int SoLuong()
	{
		return SL;
	}
	~QLTM()
	{
		if (!QL.empty())
			for (auto i = QL.begin(); i != QL.end(); i++)
				if (*i) delete* i;
		if (!TM.empty())
			for (auto i = TM.begin(); i != TM.end(); i++)
				if (*i) delete* i;
	}
};

void menu(QLTM& Q, ThuMuc& bt, ThuMuc& lt, ThuMuc& btc);
#endif