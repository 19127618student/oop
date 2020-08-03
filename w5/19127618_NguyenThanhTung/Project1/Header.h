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
public:
	ChiTiet()
	{
		ID = "Null";
	}
	ChiTiet(string id)
	{
		ID = id;
	}
	void setID(string id)
	{
		ID = id;
	}
};

class ChiTietDon:public ChiTiet
{
protected:
	double Weight;
	double Price;
public:
	ChiTietDon():ChiTiet()
	{
		Weight = 0;
		Price = 0;
	}
	ChiTietDon(string id, double w, double p):ChiTiet(id)
	{
		Weight = w;
		Price = p;
	}
	void setWeight(double w)
	{
		Weight = w;
	}
	void setPrice(double p)
	{
		Price = p;
	}
};

class ChiTietPhuc : public ChiTiet , public ChiTietDon
{
protected:
	vector<ChiTietDon*> IDchitietdon;
	double Weight;
	double Price;
	int det;
public:
	ChiTietPhuc()
	{
		IDchitietdon.resize(0);
		Weight = 0;
		det = 0;
	}
	
	~ChiTietPhuc()
	{
		if (!IDchitietdon.empty())
		{
			for (auto i = 0; i < det; i++)
			{
				if (IDchitietdon.at(i)) delete (IDchitietdon.at(i));
			}
		}
	}
	void addChiTietDon()
	{
		cout << "Enter the number of details: ";
		int det;
		cin >> det;
		for (int i = 0; i < det; i++) {
			string id;
			double w, p;
			cin.ignore();
			cout << "ID: ";
			getline(cin, id);
			cout << "Weight: ";
			cin >> w;
			cout << "Price: ";
			cin >> p;
			ChiTietDon a(id, w, p);
			IDchitietdon.push_back(&a);
			Weight += w;
			Price += p;
		}
	}
	double totolWeight()
	{
		return Weight*1.1;
	}
	double totolPrice()
	{
		return Price*1.2;
	}
};

class May
{
protected:
	
public:
	
};


#endif