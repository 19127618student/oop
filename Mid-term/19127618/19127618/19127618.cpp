#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
	string Name, Address, Phone_number;
public:
	Person()
	{
		Name = Address = Phone_number = "Null";
	}
	
	Person(string n, string a, string p_n)
	{
		Name = n; Address = a; Phone_number = p_n;
	}
	
	void setName(const string& n)
	{
		this->Name = n;
	}
	void setAdderss(const string& add)
	{
		this->Address = add;
	}
	void setPhoneNumber(const string&p_n)
	{
		this->Phone_number = p_n;
	}
	string getName()
	{
		return Name;
	}
	string getAddress()
	{
		return Address;
	}
	string getPhonenumber()
	{
		return Phone_number;
	}
};

class Client:public Person
{
protected:
	int ID;
	bool Mailing;
public:
	Client()
	{
		ID = 0;
		Mailing = 0;
	}
	Client(string n, string a, string p_n,int id,bool mail):Person(n,a,p_n)
	{
		ID = id; Mailing = mail;
	}
	void setID(const int &id)
	{
		this->ID = id;
	}
	void setMailing(const bool & mail)
	{
		this->Mailing = mail;
	}
	int getID()
	{
		return ID;
	}
	bool getMailing()
	{
		return Mailing;
	}
};

class RegularClient:public Client
{
protected:
	static int Friend;
	int Amount;
	int Bill_Per_times[3];  // Nếu có thêm thời gian em sẽ làm mảng động để thêm được nhiều giá trị hơn.
	int Discount_LV[3];		// :((
	int Totol;
	double Has_Paid;
public:
	RegularClient():Client()
	{
		Amount = Totol = Has_Paid = 0;
	}
	RegularClient(string n, string a, string p_n, int id, bool mail,RegularClient *f,int amount):Client(n,a,p_n,id,mail)
	{
		Amount = amount;
	}
	void setAmount(const int& amount)
	{
		Amount = amount;
	}
	int getAmount()
	{
		return Amount;
	}
	int Count_(int price)
	{
		int Discount = 0;
		if(price >= 2500)
		{
			Discount = 15;
		}
		else if(price >= 2000)
		{
			Discount = 10;
		}
		else if(price >= 1500)
		{
			Discount = 7;
		}
		else if(price >=1000)
		{
			Discount = 6;
		}
		else if(price >=500)
		{
			Discount = 5;
		}
		else if (price <500)
		{
			Discount = 0;
		}
		return Discount;
	}
	void Count_LV()
	{
		Discount_LV[0] = Count_(Bill_Per_times[0]);
		Discount_LV[1] = Count_(Bill_Per_times[1] + Bill_Per_times[0]);
		Discount_LV[2] = Count_(Bill_Per_times[2] + Bill_Per_times[1] + Bill_Per_times[0]);
	}
	double Count_Has_Paid()
	{
		double totol = 0;
		totol += Bill_Per_times[0] -  1.0*Bill_Per_times[0] * Friend / 100;
		totol += Bill_Per_times[1] - (1.0*Bill_Per_times[1] * (Discount_LV[0] + Friend)) / 100;
		totol += Bill_Per_times[2] - (1.0*Bill_Per_times[2] * (Discount_LV[1] + Friend)) / 100;
		return totol;
	}
	// Nếu có thêm thời gian em sẽ làm setBill(mảng động) để nhập đươc nhiều giá hơn.
	void setBill(int x,int y, int z)
	{
		Bill_Per_times[0] = x;
		Bill_Per_times[1] = y; Bill_Per_times[2] = z;
	}
	void FriendPaid()
	{
		for (int i = 0; i < 3; i++) Totol += Bill_Per_times[i];
		
		if(Totol >=2500)
		{
			Friend++;
		}
	}
};

int RegularClient::Friend = 0;

int main()
{
	cout << "\nn% discount for the first time and forever if you are a friend of another eligible customer.\n**(n = the number of friends you qualify for)\n\n";
	RegularClient Nga;
	Nga.setName("Nga");
	Nga.setAdderss("HCM city");
	Nga.setPhoneNumber("0123456");
	Nga.setID(001);
	Nga.setMailing(0);
	Nga.setAmount(3);
	Nga.setBill(800, 800, 1600);
	Nga.Count_LV();
	cout << "Nga had paid: ";
	double Nga_Paid = Nga.Count_Has_Paid();
	cout << Nga_Paid;
	Nga.FriendPaid();
	
	cout << endl;
	
	RegularClient Khang;
	Khang.setName("Khang");
	Khang.setAdderss("HCM city");
	Khang.setPhoneNumber("0123457");
	Khang.setID(002);
	Khang.setMailing(0);
	Khang.setAmount(3);
	Khang.setBill(950, 950, 2200);
	Khang.Count_LV();
	cout << "Khang had paid: ";
	double Khang_Paid = Khang.Count_Has_Paid();
	cout << Khang_Paid;
	Khang.FriendPaid();

	cout << endl;
	
	RegularClient Thai;
	Thai.setName("Thai");
	Thai.setAdderss("HCM city");
	Thai.setPhoneNumber("0123451");
	Thai.setID(003);
	Thai.setMailing(1);
	Thai.setAmount(3);
	Thai.setBill(950, 850, 2400);
	Thai.Count_LV();
	cout << "Thai had paid: ";
	double Thai_Paid = Thai.Count_Has_Paid();
	cout << Thai_Paid;
	Thai.FriendPaid();

	cout << endl << endl;
	cout << "Totol: ";
	cout << Nga_Paid + Khang_Paid + Thai_Paid;
	cout << endl << endl;
	return 0;
}