#include "Header.h"

class SinhVien
{
protected:
	string MSSV;
	string HoTen;
	string DiaChi;
	int GioiTinh;
	int SoTinChi;
	double *DTB;
	int nam;
public:
	SinhVien()
	{
		MSSV = HoTen = DiaChi = "Null";
		GioiTinh = SoTinChi = 0;
		DTB = 0;
		nam = 0;
	}
	SinhVien(string ms,string ht,string dc,int gt,int tc,double *dtb, int nam)
	{
		MSSV = ms; HoTen = ht; DiaChi = dc;
		GioiTinh = gt; SoTinChi = tc;
		DTB = dtb;
		this->nam = nam;
	}
	void setMS(string& ms)
	{
		MSSV = ms;
	}
	void setHT(string& ht)
	{
		HoTen = ht;
	}
	void setDC(string &dc)
	{
		DiaChi = dc;
	}
	void setGT(int &gt)
	{
		GioiTinh = gt;
	}
	int getGT()
	{
		return GioiTinh;
	}
	void setTC(int& tc)
	{
		SoTinChi = tc;
	}
	void setDTB(double *&dtb)
	{
		for(int i=0; i < nam ;i++)
		{
			cout << "Nam " << i + 1 << " : ";
			cin >> dtb[i];
		}
		*DTB = *dtb;
	}
	void setN(int &nam)
	{
		this->nam = nam;
	}
	virtual bool Tot_Nghiep() const = 0 {};
	virtual void Display() {};
	double getTDTB()
	{
		double d = 0;
		for (int i = 0; i < nam; i++)
		{
			d += DTB[i];
		}
		return d;
	}
};

class CaoDang:public SinhVien
{
protected:
	
public:
	static int Cd;
	CaoDang():SinhVien()
	{
		Cd++;
	}
	CaoDang(string ms, string ht, string dc, int gt, int tc, double *dtb,int n):SinhVien(ms,ht,dc,gt,tc,dtb,n)
	{
		setMS(ms);
		setHT(ht);
		setDC(dc);
		setGT(gt);
		setTC(tc);
		setN(n);
		setDTB(dtb);
		Cd++;
	}
	void Display() override
	{
		cout << endl;
		cout << "MSSV: " << MSSV <<endl;
		cout << "Ho ten: " << HoTen <<endl;
		cout << "Dia chi: " << DiaChi <<endl;
		cout << "Gioi Tinh: " << GioiTinh <<endl;
		cout << "So tin chi: " << SoTinChi <<endl;
		cout << "DTB cac nam: " << endl;
		for (int i = 0; i < nam; i++)
		{
			cout << DTB[i] << endl;
		}
		cout << endl;
		if (Tot_Nghiep() == 1) cout << "Tot Nghiep!";
		else cout << "Khong Tot Nghiep!";
		cout << endl;
	}
	bool Tot_Nghiep() const override
	{
		double TDTB = 0;
		for(int i=0;i<nam;i++)
		{
			TDTB += DTB[i];
		}
		TDTB = TDTB / nam;
		if (SoTinChi >= 120 && TDTB >= 5.0) return 1;
		else return 0;
	}
};
class DaiHoc :public SinhVien
{
protected:
	double Toeic;
public:
	DaiHoc() :SinhVien()
	{
		Toeic = 0;
	}
	DaiHoc(string ms, string ht, string dc, int gt, int tc, double *dtb, int n, double to) :SinhVien(ms, ht, dc, gt, tc, dtb,n)
	{
		setMS(ms);
		setHT(ht);
		setDC(dc);
		setGT(gt);
		setTC(tc);
		setN(n);
		setDTB(dtb);
		Toeic = to;
		
	}
	void Display() override
	{
		cout << endl;
		cout << "MSSV: " << MSSV << endl;
		cout << "Ho ten: " << HoTen << endl;
		cout << "Dia chi: " << DiaChi << endl;
		cout << "Gioi Tinh: " << GioiTinh << endl;
		cout << "So tin chi: " << SoTinChi << endl;
		cout << "DTB cac nam: " << endl;
		for(int i = 0 ;i < nam;i++)
		{
			cout << DTB[i] << endl;
		}
		cout << "Diem Toeic: " << Toeic << endl;
		if (Tot_Nghiep() == 1) cout << "Tot Nghiep!";
		else cout << "Khong Tot Nghiep!";
		cout << endl;
	}
	bool Tot_Nghiep() const override
	{
		double TDTB = 0;
		for (int i = 0; i < nam; i++)
		{
			TDTB += DTB[i];
		}
		TDTB = TDTB / nam;
		if (SoTinChi >= 140 && TDTB >= 5.0 && Toeic>=500) return 1;
		else return 0;
	}
};
class CLC:public SinhVien
{
	protected:
	double Toeic;
public:
	CLC() :SinhVien()
	{
		Toeic = 0;
	}
	CLC(string ms, string ht, string dc, int gt, int tc, double* dtb, int n, double to) :SinhVien(ms, ht, dc, gt, tc, dtb, n)
	{
		setMS(ms);
		setHT(ht);
		setDC(dc);
		setGT(gt);
		setTC(tc);
		setN(n);
		setDTB(dtb);
		Toeic = to;

	}
	void Display() override
	{
		cout << endl;
		cout << "MSSV: " << MSSV << endl;
		cout << "Ho ten: " << HoTen << endl;
		cout << "Dia chi: " << DiaChi << endl;
		cout << "Gioi Tinh: " << GioiTinh << endl;
		cout << "So tin chi: " << SoTinChi << endl;
		cout << "DTB cac nam: " << endl;
		for (int i = 0; i < nam; i++)
		{
			cout << DTB[i] << endl;
		}
		cout << "Diem Toeic: " << Toeic << endl;
		if (Tot_Nghiep() == 1) cout << "Tot Nghiep!";
		else cout << "Khong Tot Nghiep!";
		cout << endl;
	}
	bool Tot_Nghiep() const override
	{
		double TDTB = 0;
		for (int i = 0; i < nam; i++)
		{
			if (DTB[i] < 4.0)return 0;
			else TDTB += DTB[i];
		}
		TDTB = TDTB / nam;
		if (SoTinChi >= 140 && TDTB >= 5.0 && Toeic >= 500) return 1;
		else return 0;
	}
};

class QLSV
{
protected:
	vector<SinhVien*>SV;
public:
	QLSV()
	{
		SV.resize(0);
	}
	void addSV(SinhVien*sv)
	{
		SV.push_back(sv);
	}
	void DisplaySV()
	{
		if(!SV.empty())
		{
			for(auto i = SV.begin();i!=SV.end();i++)
			{
				
				if (*i)
					if ((*i)->Tot_Nghiep() == 1)
						(*i)->Display();
			}
		}
	}
	void DSSVTN()
	{
		if (!SV.empty())
		{
			for (auto i = SV.begin(); i != SV.end(); i++)
			{
				if (*i)
				{
					if ((*i)->getTDTB()>=8.0) {
						(*i)->Display();
					}
				}
			}
		}
	}
	void DISGT()
	{
		int nam=0;
		int nu=0;
		if (!SV.empty())
		{
			for (auto i = SV.begin(); i != SV.end(); i++)
			{
				if (*i)
				{
					if ((*i)->getGT() == 0) nu++;
					else nam++;
				}
			}
		}
		cout << "Nam: " << nam;
		cout << "\nNu: " << nu;
	}
};
int CaoDang::Cd = 0;
int main()
{
	double* dtb = new double[10];
	double* dtb1 = new double[10];
	double* dtb2 = new double[10];
	//CaoDang cd("1912","tung","491,ndc",1,130,dtb,3);
	//cd.Display();
	
	//DaiHoc dh("1912", "tung", "491,ndc", 1, 140, dtb, 2 ,600);
	//dh.Display();

	QLSV sv;
	sv.addSV(new CaoDang("1912", "tung", "491,ndc", 1, 130, dtb, 2));
	sv.addSV(new DaiHoc("191f2", "tungdd", "491,ndcsss", 1, 140, dtb1, 2, 600));
	sv.addSV(new CLC("1912cc", "tungcc", "491,ndcccc", 1, 140, dtb2, 2, 600));
	
	sv.DisplaySV();
	sv.DSSVTN();
	sv.DISGT();
	cout << "\n So SVCD:" << CaoDang::Cd;
	
	return 0;
}