#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class NhanVien
{
	string name;
	int numberOfWorkingDay;
	string msnv;
	string jobTitle;
	float coefficientsSalary;
public:
	NhanVien();
	NhanVien(string, int);
	NhanVien(const NhanVien&);
	NhanVien(string, int, string, string, float);
	~NhanVien();
	void setName(string);
	void setNumberOfWorkingDay(int);
	void setMsnv(string);
	void setJobTitle(string);
	void setCoefficientsSalary(float);
	string getName();
	int getNumberOfWorkingDay();
	string getMsnv();
	string getJobTitle();
	float getCoefficientsSalary();
	void display()
	{
		cout << "Ten: " << name << endl;
		cout << "So ngay lam viec: " << numberOfWorkingDay << endl;
		cout << "Ma so nhan vien: " << jobTitle << endl;
		cout << "He so luong: " << coefficientsSalary << endl << endl;
	}
	friend istream& operator>>(istream& is, NhanVien& obj);
	friend ostream& operator<<(ostream& outDev, const NhanVien& obj);
};
int search(vector<NhanVien> a, string name);