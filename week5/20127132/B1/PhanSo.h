#pragma once
#include <iostream>

using namespace std;

class PhanSo
{
	int* tuso;
	int* mauso;
public:
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
	void checkNegative();
	PhanSo& operator=(const PhanSo&);
	PhanSo operator+(const PhanSo& ps);
	PhanSo operator-(const PhanSo& ps);
	PhanSo operator*(const PhanSo& ps);
	PhanSo operator/(const PhanSo& ps);
	PhanSo& operator+=(const PhanSo&);
	PhanSo& operator-=(const PhanSo&);
	PhanSo& operator*=(const PhanSo&);
	PhanSo& operator/=(const PhanSo&);
	PhanSo operator++(int);
	PhanSo& operator++();
	PhanSo operator--(int);
	PhanSo& operator--();
	bool operator==(const PhanSo&);
	bool operator!=(const PhanSo&);
	bool operator>(const PhanSo&);
	bool operator<(const PhanSo&);
	bool operator>=(const PhanSo&);
	bool operator<=(const PhanSo&);
	friend istream& operator>>(istream& is, PhanSo& obj);
	friend ostream& operator<<(ostream& os, PhanSo obj);
};