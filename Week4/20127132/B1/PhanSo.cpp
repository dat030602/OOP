#include "PhanSo.h"

int PhanSo::gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

PhanSo::PhanSo()
{
	tu = new int, mau = new int;
	*tu = 0;
	*mau = 1;
}

PhanSo::PhanSo(int tuso)
{
	tu = new int, mau = new int;
	*tu = tuso;
	*mau = 1;
}

PhanSo::PhanSo(int tuso, int mauso)
{
	tu = new int, mau = new int;
	if (mauso < 0)
	{
		mauso *= -1;
		tuso *= -1;
	}
	*tu = tuso;
	*mau = mauso;
}

PhanSo::~PhanSo()
{
	delete tu, mau;
}

PhanSo::PhanSo(const PhanSo& ps)
{
	tu = new int;
	mau = new int;
	*tu = *ps.tu;
	*mau = *ps.mau;
}

void PhanSo::setTu(int* tu)
{
	this->tu = tu;
}

void PhanSo::setMau(int* mau)
{
	this->mau = mau;
}

int PhanSo::getTu()
{
	return *tu;
}

int PhanSo::getMau()
{
	return *mau;
}

PhanSo PhanSo::operator+(const PhanSo& ps)
{
	int tu1 = *(this->tu) * *(ps.mau) + *(this->mau) * *(ps.tu);
	int mau1 = *(this->mau) * *(ps.mau);
	int _gcd = gcd(abs(tu1), abs(mau1));
	PhanSo temp(tu1 / _gcd, mau1 / _gcd);
	return temp;
}
PhanSo PhanSo::operator-(const PhanSo& ps)
{
	int tu1 = *(this->tu) * *(ps.mau) - *(this->mau) * *(ps.tu);
	int mau1 = *(this->mau) * *(ps.mau);
	int _gcd = gcd(abs(tu1), abs(mau1));
	PhanSo temp(tu1 / _gcd, mau1 / _gcd);
	return temp;
}
PhanSo PhanSo::operator*(const PhanSo& ps)
{
	int tu1 = *(this->tu) * *(ps.tu);
	int mau1 = *(this->mau) * *(ps.mau);
	int _gcd = gcd(abs(tu1), abs(mau1));
	PhanSo temp(tu1 / _gcd, mau1 / _gcd);
	return temp;
}
PhanSo PhanSo::operator/(const PhanSo& ps)
{
	int tu1 = *(this->tu) * *(ps.mau);
	int mau1 = *(this->mau) * *(ps.tu);
	int _gcd = gcd(abs(tu1), abs(mau1));
	PhanSo temp(tu1 / _gcd, mau1 / _gcd);
	return temp;
}
istream& operator>>(istream& is, PhanSo& obj)
{
	cout << "Nhap tu so: ";
	is >> *obj.tu;
	cout << "Nhap mau so: ";
	is >> *obj.mau;
	if (*obj.mau < 0)
	{
		*obj.mau *= -1;
		*obj.tu *= -1;
	}
	return is;
}
ostream& operator<<(ostream& os, PhanSo obj)
{
	if (*obj.mau < 0)
	{
		*obj.mau *= -1;
		*obj.tu *= -1;
	}
	os << *obj.tu << " / " << *obj.mau << endl;
	return os;
}