#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

class PhanSo
{
private:
	int* tu;
	int* mau;
public:
	PhanSo();
	PhanSo(int);
	PhanSo(int, int);
	~PhanSo();
	PhanSo(const PhanSo& ps);
	void setTu(int*);
	void setMau(int*);
	int getTu();
	int getMau();
	int gcd(int, int);
	PhanSo operator+(const PhanSo& ps);
	PhanSo operator-(const PhanSo& ps);
	PhanSo operator*(const PhanSo& ps);
	PhanSo operator/(const PhanSo& ps);
	friend istream& operator>>(istream& is, PhanSo& obj);
	friend ostream& operator<<(ostream& os, PhanSo obj);
};