#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
template <typename T>

class Mang
{
private:
	T* data;
	int n;
	vector<T> myVector;
public:
	Mang()
	{
		data = new T[n];
		myVector.resize(0);
	}
	Mang(T* data, int n){
		this->data = data;
		this->n = n;
		for(int i=0;i<n;i++)
		{
			myVector.push_back(data[i]);
		}
	}
	~Mang(){}
	void Sort()
	{
		for (int i = 0; i < n - 1; i++) 
			for (int j = 0; j < n - i - 1; j++) 
				if (data[j] > data[j + 1]) {
					T temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
		sort(myVector.begin(), myVector.end());
	}
	int timkiem(const T& key) const
	{
		if (n != 0)
		{
			int cur = 0;
			bool flag = 0;
			for(int i=0;i<myVector.size();i++)
			{
				if (myVector.at(i) == key) { cur++; flag = 1; break; }
				else cur++;
			}
			if (flag) return cur;
			else return -1;
		}
		else return -1;
	}
	void ghifile(string tenfile)
	{
		ofstream fout;
		string name = tenfile + ".bin";
		fout.open(name, ios::out, ios::binary);
		if (!fout.is_open()) cout << "Cant create.";
		else
		{
			savearr(fout, data, n); 
			fout.close();
		}
	}
	void savearr(ofstream& fout, T* a, int n) {
		fout.write((char*)&n, sizeof(n));
		for (int i = 0; i < n; i++) {
			fout.write((char*)&a[i], sizeof(a[i]));
		}
	}
	void docfile(string tenfile)
	{
		ifstream fin;
		string name = tenfile + ".bin";
		fin.open(name, ios::out, ios::binary);
		if (!fin.is_open()) cout << "Cant open.";
		else
		{
			cout << "ok";
			loadarr(fin, data, n);
			myVector.resize(0);
			for (int i = 0; i < n; i++)
			{
				myVector.push_back(data[i]);
			}
			fin.close();
		}
	}
	void loadarr(ifstream& fin, T*& a, int& n) {
		fin.read((char*)&n, sizeof(n));
		a = new T[n];
		for (int i = 0; i < n; i++) {
			fin.read((char*)&a[i], sizeof(a[i]));
		}
	}
	int timmax()const
	{
		int m = *max_element(myVector.begin(), myVector.end());
		return m;
	}
	int timmin()const
	{
		int m = *min_element(myVector.begin(), myVector.end());
		return m;
	}
	void nhap()
	{
		T umk;
		cout << "\ninput: ";
		cin >> umk;
		cout << umk << endl;

		int m = n + 1;
		T *datas = new T[m];
		for(int i=0;i<n;i++)
		{
			datas[i] = data[i];
		}
		datas[n] = umk;
		n = m;
		data = new T[n];
		for(int i=0;i<n;i++)
		{
			data[i] = datas[i];
		}
		myVector.push_back(umk);
	}
	void xuat()const
	{
		if (!myVector.empty())
			for (int i = 0; i < n; i++)
			{
				cout << data[i] << " ";
			}
		else cout << "empty.";
		cout << endl<<endl;
	}
	bool ktRong()const
	{
		if (myVector.empty())return 1;
		else return 0;
	}
};

class Hocsinh
{
private:
	string hoten;
	int tuoi;
	float dtb;
public:
	Hocsinh() {};
	Hocsinh(string hoten1, int tuoi, float dtb)
	{
		this->hoten = hoten1;
		this->tuoi = tuoi;
		this->dtb = dtb;
	}

	friend ostream& operator << (ostream& os, Hocsinh& hs)
	{
		os << "\nTen: " << hs.hoten << endl << "Tuoi: " << hs.tuoi << endl << "DTB: " << hs.dtb << endl;
		return os;
	}
	friend istream& operator >> (istream& is, Hocsinh& hs)
	{
		cout << "Ten: ";
		getline(is, hs.hoten);
		cout << "Tuoi: ";
		is >> hs.tuoi;
		cout << "DTB: ";
		is >> hs.dtb;
		return is;
	}
	bool operator > (Hocsinh& r)
	{
		if (this->dtb > r.dtb) return 1;
		else return 0;
	}
	bool operator < (const Hocsinh& r)
	{
		if (this->dtb < r.dtb) return 1;
		else return 0;
	}
	friend void sapxep(Hocsinh a[], int n)
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - 1 - i; j++)
				if (a[j] > a[j + 1])
				{
					Hocsinh t = a[j];
					a[j] = a[j + 1];
					a[j + 1] = t;
				}
	}
};
