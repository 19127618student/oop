#include "Header.h"
void inputData(student& s)
{
	cout << "Enter Name: ";
	cin.getline(s.name, 29);
	cout << "Enter Age: ";
	cin >> s.age;
	cout << "Enter Address: ";
	cin.ignore();
	cin.getline(s.address, 99);
}
void displayData(student s)
{
	cout << "\nName: " << s.name << "\nAge: " << s.age << "\nAddress: " << s.address;
}
void saveData(ofstream& f, student s)
{
	f.write((char*)&s.name, sizeof(s.name));
	f.write((char*)&s.age, sizeof(s.age));
	f.write((char*)&s.address, sizeof(s.address));
}
void loadData(ifstream& f, student& s)
{
	f.read((char*)&s.name, sizeof(s.name));
	f.read((char*)&s.age, sizeof(s.age));
	f.read((char*)&s.address, sizeof(s.address));


}
