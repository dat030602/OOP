#include "HocSinh.h"

HocSinh::HocSinh()
{
	GPA = 0;
	name = "";
}
HocSinh::HocSinh(const HocSinh& ps)
{
	GPA = ps.GPA;
	name = ps.name;
}
HocSinh::~HocSinh()
{
	GPA = 0;
	name = "";
}
bool HocSinh::operator==(const HocSinh& ps)
{
	int result = this->GPA - ps.GPA;
	if (result == 0)
		return true;
	else
		return false;
}
bool HocSinh::operator>(const HocSinh& ps)
{
	int result = this->GPA - ps.GPA;
	if (result > 0)
		return true;
	else
		return false;
}
bool HocSinh::operator>=(const HocSinh& ps)
{
	int result = this->GPA - ps.GPA;
	if (result >= 0)
		return true;
	else
		return false;
}
bool HocSinh::operator<(const HocSinh& ps)
{
	int result = this->GPA - ps.GPA;
	if (result == 0)
		return true;
	else
		return false;
}
bool HocSinh::operator<=(const HocSinh& ps)
{
	int result = this->GPA - ps.GPA;
	if (result <= 0)
		return true;
	else
		return false;
}
bool HocSinh::operator!=(const HocSinh& ps)
{
	int result = this->GPA - ps.GPA;
	if (result != 0)
		return true;
	else
		return false;
}
HocSinh& HocSinh::operator=(const HocSinh& ps)
{
	this->GPA = ps.GPA;
	this->name = ps.name;
	return *this;
}
HocSinh::operator char* () const
{
	int size = this->name.size();
	char* temp = new char[size];
	for (int i = 0; i < size; i++)
		temp[i] = this->name[i];
	temp[size] = '\0';
	return temp;
}
istream& operator>>(istream& is, HocSinh& ps)
{
	cout << "Nhap Ten: ";
	//cin.ignore();
	getline(is, ps.name);
	cout << "Nhap GPA: ";
	is >> ps.GPA;
	return is;
}

ostream& operator<<(ostream& os, HocSinh& ps)
{
	os << "Ten: " << ps.name << endl;
	os << "GPA: " << ps.GPA << endl;
	return os;
}