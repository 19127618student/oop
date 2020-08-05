#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ChiTiet
{
protected:
	string ID;
	double	TrongLuong;
	double GiaThanh;
public:
	ChiTiet() {}
	ChiTiet(string id, double tl, double gt)
	{
		ID = id;
		TrongLuong = tl;
		GiaThanh = gt;
	}
	void setID(string& id)
	{
		ID = id;
	}
	void setTL(double& tl)
	{
		TrongLuong = tl;
	}
	void setGT(double& gt)
	{
		GiaThanh = gt;
	}
	string getID()
	{
		return ID;
	}
	virtual void getIF() {};
	virtual double Weight()const = 0 {};
	virtual double Price()const = 0 {};
};

class ChiTietDon :public  ChiTiet
{
protected:

public:
	ChiTietDon() {};
	ChiTietDon(string id, double tl, double gt)
	{
		setTL(tl);
		setGT(gt);
		setID(id);
	}
	double Price()const
	{
		return GiaThanh;
	}
	double Weight()const
	{
		return TrongLuong;
	}
	void getIF()
	{
		cout << "ID: ";
		cout << ID << endl;
		cout << "Trong luong: ";
		cout << TrongLuong << endl;
		cout << "Gia thanh: ";
		cout << GiaThanh << endl;
	}
};

class ChiTietPhuc :public ChiTiet
{
protected:
	vector<string> ctd;
public:
	ChiTietPhuc()
	{
		ctd.resize(0);
	};
	ChiTietPhuc(string id)
	{
		ctd.resize(0);
		setID(id);
	}
	ChiTietPhuc(string id, double tl, double gt)
	{
		ctd.resize(0);
		setID(id);
		setTL(tl);
		setGT(gt);
	}
	void addCTD(string& id, double& tl, double& gt)
	{
		ctd.push_back(id);
		TrongLuong += tl;
		GiaThanh += gt;
	}
	void addCTP(string& id)
	{
		ctd.push_back(id);
	}
	void getListID()
	{
		if (!ctd.empty()) {
			int j = 0;
			for (auto i = ctd.begin(); i != ctd.end(); i++) {
				cout << ctd.at(j) << endl;
				j++;
			}
		}
	}
	double Price() const
	{
		return GiaThanh;
	}
	double Weight() const
	{
		return TrongLuong;
	}
	void getIF()
	{
		cout << "Ma so: " << ID << endl;
		if (TrongLuong != 0) {
			cout << "Trong luong: " << TrongLuong << endl;
			cout << "Gia: " << GiaThanh << endl;
			cout << "Cau thanh boi: \n";
		}
		getListID();
		if (TrongLuong == 0)
		{
			cout << "Chua co thong tin.";
		}
		cout << endl;
	}
};

class May
{
protected:
	vector<ChiTietDon*> Ctd;
	vector<ChiTietPhuc*> Ctp;
	vector<string> name;
	double TL, GT;
public:
	May()
	{
		TL = GT = 0;
		Ctd.resize(0);
		Ctp.resize(0);
	}
	void Addd(ChiTietDon* ct)
	{
		Ctd.push_back(ct);
	}
	void Addp(ChiTietPhuc* ct)
	{
		Ctp.push_back(ct);
	}
	void Seart(string id)
	{
		if (!Ctd.empty()) {
			for (auto i = Ctd.begin(); i != Ctd.end(); i++)
				if (*i)
					if ((*i)->getID() == id)
						(*i)->getIF();
		}
		if (!Ctp.empty()) {
			for (auto i = Ctp.begin(); i != Ctp.end(); i++)
				if (*i)
					if ((*i)->getID() == id)
						(*i)->getIF();
		}
	}
	double TinhTrongLuong()
	{
		if (!Ctd.empty()) {
			for (auto i = Ctd.begin(); i != Ctd.end(); i++)
				if (*i)
					TL += (*i)->Weight();
		}
		return TL * 1.1;
	}
	double TinhGiaThanh()
	{
		if (!Ctd.empty()) {
			for (auto i = Ctd.begin(); i != Ctd.end(); i++)
				if (*i)
					GT += (*i)->Price();
		}
		return GT * 1.2;
	}
};
void menu(May& m);
#endif