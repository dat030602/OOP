#include "NhanVien.h"

NhanVien::NhanVien()
{
	name = "";
	numberOfWorkingDay = -1;
	msnv = "";
	jobTitle = "";
	coefficientsSalary = 0;
}
NhanVien::NhanVien(string name, int numberOfWorkingDay, string msnv, string jobTitle, float coefficientsSalary)
{
	this->name = name;
	this->numberOfWorkingDay = numberOfWorkingDay;
	this->msnv = msnv;
	this->jobTitle = jobTitle;
	this->coefficientsSalary = coefficientsSalary;
}
NhanVien::NhanVien(string name, int numberOfWorkingDay)
{
	this->name = name;
	this->numberOfWorkingDay = numberOfWorkingDay;
	this->msnv = to_string(numberOfWorkingDay) + name;
	if (numberOfWorkingDay >= 0 && numberOfWorkingDay <= 365)
	{
		this->jobTitle = "Nhan Vien";
		this->coefficientsSalary = 1;
	}
	else if (numberOfWorkingDay > 365 && numberOfWorkingDay <= 730)
	{
		this->jobTitle = "Quan Ly";
		this->coefficientsSalary = 1.5;
	}
	else if (numberOfWorkingDay > 730 && numberOfWorkingDay <= 1460)
	{
		this->jobTitle = "Truong Phong";
		this->coefficientsSalary = 2.25;
	}
	else if (numberOfWorkingDay > 1460)
	{
		this->jobTitle = "Truong Ban Quan Ly";
		this->coefficientsSalary = 4;
	}
}
NhanVien::NhanVien(const NhanVien& temp)
{
	this->jobTitle = temp.jobTitle;
	this->coefficientsSalary = temp.coefficientsSalary;
	this->numberOfWorkingDay = temp.numberOfWorkingDay;
}
NhanVien::~NhanVien()
{
	name = "";
	numberOfWorkingDay = -1;
	msnv = "";
	jobTitle = "";
	coefficientsSalary = 0;
}
void NhanVien::setName(string name) { this->name = name; }
void NhanVien::setNumberOfWorkingDay(int)
{ 
	this->numberOfWorkingDay = numberOfWorkingDay;
	if (numberOfWorkingDay >= 0 && numberOfWorkingDay <= 365)
	{
		this->jobTitle = "Nhan Vien";
		this->coefficientsSalary = 1;
	}
	else if (numberOfWorkingDay > 365 && numberOfWorkingDay <= 730)
	{
		this->jobTitle = "Quan Ly";
		this->coefficientsSalary = 1.5;
	}
	else if (numberOfWorkingDay > 730 && numberOfWorkingDay <= 1460)
	{
		this->jobTitle = "Truong Phong";
		this->coefficientsSalary = 2.25;
	}
	else if (numberOfWorkingDay > 1460)
	{
		this->jobTitle = "Truong Ban Quan Ly";
		this->coefficientsSalary = 4;
	}
}
void NhanVien::setMsnv(string) { this->msnv = msnv; }
void NhanVien::setJobTitle(string) { 
	this->jobTitle = jobTitle;
	if (jobTitle == "Nhan Vien")
		this->coefficientsSalary = 1;
	else if (jobTitle == "Quan Ly")
		this->coefficientsSalary = 1.5;
	else if (jobTitle == "Truong Phong")
		this->coefficientsSalary = 2.25;
	else if (jobTitle == "Truong Ban Quan Ly")
		this->coefficientsSalary = 4;
}
void NhanVien::setCoefficientsSalary(float) { this->coefficientsSalary = coefficientsSalary; }
string NhanVien::getName() { return name; }
int NhanVien::getNumberOfWorkingDay() { return numberOfWorkingDay; };
string NhanVien::getMsnv() { return msnv; };
string NhanVien::getJobTitle() { return jobTitle; };
float NhanVien::getCoefficientsSalary() { return coefficientsSalary; };
istream& operator>>(istream& is, NhanVien& obj)
{
	cout << "Nhap ten: ";
	is.ignore();
	getline(is, obj.name);
	cout << "Nhap So Ngay Lam Viec: ";
	is >> obj.numberOfWorkingDay;
	cout << "Nhap Ma So Nhan Vien: ";
	is.ignore();
	getline(is, obj.msnv);
	cout << "Nhap Chuc Danh: ";
	getline(is, obj.jobTitle);
	cout << "Nhap He So Luong: ";
	is >> obj.coefficientsSalary;
	return is;
}
ostream& operator<<(ostream& outDev, const NhanVien& obj)
{
	outDev << "Ten: " << obj.name << endl;
	outDev << "So ngay lam viec: " << obj.numberOfWorkingDay << endl;
	outDev << "Ma So Nhan Vien: " << obj.msnv << endl;
	outDev << "Chuc Danh: " << obj.jobTitle << endl;
	outDev << "He so luong: " << obj.coefficientsSalary << endl << endl;

	return outDev;
}
int search(vector<NhanVien> a, string name)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i].getName() == name)
			return i;
	return -1;
}