#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NhanVien
{
protected:
	int MaSo;
	string HoTen;
public:
	NhanVien()
	{
		MaSo = 0;
		HoTen = "Null";
	}
	NhanVien(int m, string n)
	{
		MaSo = m;
		HoTen = n;
	}
	void setID(int id)
	{
		MaSo = id;
	}
	void setName(string name)
	{
		HoTen = name;
	}
	virtual void getIF() {};
};

class NVSX :public NhanVien
{
	int SL;
public:
	NVSX() {};
	NVSX(int m, string n, int sl)
	{
		setID(m);
		setName(n);
		SL = sl;
	}
	void setSL(int m, string n, int sl)
	{
		setID(m);
		setName(n);
		SL = sl;
	}
	double Luong()
	{
		return SL * 20000;
	}
	void getIF()
	{
		cout << MaSo << endl;
		cout << HoTen << endl;
		cout << SL << endl;
		cout << Luong() << endl;
	}
};
class NVCN :public NhanVien
{
	int NC;
public:
	NVCN() {}
	NVCN(int m, string n, int sl)
	{
		setID(m);
		setName(n);
		NC = sl;
	}
	void setSL(int m, string n, int sl)
	{
		setID(m);
		setName(n);
		NC = sl;
	}
	double Luong()
	{
		return NC * 50000;
	}
	void getIF()
	{
		cout << MaSo << endl;
		cout << HoTen << endl;
		cout << NC << endl;
		cout << Luong() << endl;
	}
};
class NVQL :public NhanVien
{
	double QL, HS;
public:
	static int SLQL;
	NVQL() {}
	NVQL(int m, string n, double sl, double hs)
	{
		setID(m);
		setName(n);
		QL = sl;
		HS = hs;
		SLQL++;
	}
	void setSL(int m, string n, double sl, double hs)
	{
		setID(m);
		setName(n);
		QL = sl;
		HS = hs;
		SLQL++;
	}
	double Luong()
	{
		return (QL * HS);
	}

	void getIF()
	{
		cout << MaSo << endl;
		cout << HoTen << endl;
		cout << QL << endl;
		cout << Luong() << endl;
		cout << SLQL << endl;
	}
};

class QLNV :public NhanVien
{
private:
	vector<NhanVien*> QL;
public:
	static int slnv;
	QLNV()
	{
		QL.resize(0);
	}
	void add(NhanVien* nv)
	{
		QL.push_back(nv);
		slnv++;
	}
	void display()
	{
		if (!QL.empty())
		{
			for (auto i = QL.begin(); i != QL.end(); i++)
			{
				cout << endl;
				if (*i) (*i)->getIF();
				cout << endl;
			}
		}
	}
};
void menu(QLNV& ql);
#endif