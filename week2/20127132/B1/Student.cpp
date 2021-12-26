#include "Student.h"

istream& operator>>(istream& inDev, Student& ms)
{
	cout << "Nhap ten: ";
	inDev.ignore();
	getline(inDev, ms.name);
	while (ms.name.size() == 0 || ms.name.size() > 20 || !checkName(ms.name))
	{
		cout << "Nhap lai ten: ";
		getline(inDev, ms.name);
	}
	cout << "Nhap so dien thoai: ";
	getline(inDev, ms.phoneNumber);
	while (ms.phoneNumber.size() < 9 || ms.phoneNumber.size() > 11 || !checkPhone(ms.phoneNumber))
	{
		cout << "Nhap lai so dien thoai: ";
		getline(inDev, ms.phoneNumber);
	}
	cout << "Nhap diem trung binh: ";
	inDev >> ms.mean;
	while (ms.mean < 0 || ms.mean > 10)
	{
		cout << "Nhap lai diem trung binh: ";
		inDev >> ms.mean;
	}
	cout << endl;
	return inDev;
}
ostream& operator<<(ostream& outDev, const Student& ms)
{
	outDev << "Ten: " << ms.name << endl;
	outDev << "So dien thoai lien lac: " << ms.phoneNumber << endl;
	outDev << "Diem trung binh: " << ms.mean << endl << endl;
	return outDev;
}
Student::Student() {
	name = "NONE";
	phoneNumber = "NONE";
	mean = -1;
};