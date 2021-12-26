#include "PhanSo.h"

int PhanSo::gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

PhanSo::PhanSo()
{
	tuso = new int, mauso = new int;
	*tuso = 0;
	*mauso = 1;
}

PhanSo::PhanSo(int tu)
{
	tuso = new int, mauso = new int;
	*tuso = tu;
	*mauso = 1;
}

PhanSo::PhanSo(int tu, int mau)
{
	tuso = new int, mauso = new int;
	*tuso = tu;
	*mauso = mau;
	checkNegative();
}

PhanSo::~PhanSo()
{
	delete tuso, mauso;
}

PhanSo::PhanSo(const PhanSo& ps)
{
	tuso = new int;
	mauso = new int;
	*tuso = *ps.tuso;
	*mauso = *ps.mauso;
}

void PhanSo::setTu(int* tu)
{
	this->tuso = tu;
}

void PhanSo::setMau(int* mau)
{
	this->mauso = mau;
}

int PhanSo::getTu()
{
	return *tuso;
}

int PhanSo::getMau()
{
	return *mauso;
}

void PhanSo::checkNegative()
{
	if (*mauso < 0)
	{
		*mauso *= -1;
		*tuso *= -1;
	}
}

PhanSo& PhanSo::operator=(const PhanSo& ps)
{
	if (this == &ps)
		return *this;
	delete tuso;
	delete mauso;
	tuso = new int;
	mauso = new int;
	*this->tuso = *ps.tuso;
	*this->mauso = *ps.mauso;
	return *this;
}

PhanSo PhanSo::operator+(const PhanSo& ps)
{
	int tu1 = *(this->tuso) * *(ps.mauso) + *(this->mauso) * *(ps.tuso);
	int mau1 = *(this->mauso) * *(ps.mauso);
	int _gcd = gcd(abs(tu1), abs(mau1));
	PhanSo temp(tu1 / _gcd, mau1 / _gcd);
	temp.checkNegative();
	return temp;
}

PhanSo PhanSo::operator-(const PhanSo& ps)
{
	int tu1 = *(this->tuso) * *(ps.mauso) - *(this->mauso) * *(ps.tuso);
	int mau1 = *(this->mauso) * *(ps.mauso);
	int _gcd = gcd(abs(tu1), abs(mau1));
	PhanSo temp(tu1 / _gcd, mau1 / _gcd);
	temp.checkNegative();
	return temp;
}

PhanSo PhanSo::operator*(const PhanSo& ps)
{
	int tu1 = *(this->tuso) * *(ps.tuso);
	int mau1 = *(this->mauso) * *(ps.mauso);
	int _gcd = gcd(abs(tu1), abs(mau1));
	PhanSo temp(tu1 / _gcd, mau1 / _gcd);
	temp.checkNegative();
	return temp;
}

PhanSo PhanSo::operator/(const PhanSo& ps)
{
	int tu1 = *(this->tuso) * *(ps.mauso);
	int mau1 = *(this->mauso) * *(ps.tuso);
	int _gcd = gcd(abs(tu1), abs(mau1));
	PhanSo temp(tu1 / _gcd, mau1 / _gcd);
	temp.checkNegative();
	return temp;
}

istream& operator>>(istream& is, PhanSo& obj)
{
	cout << "Nhap tu so: ";
	is >> *obj.tuso;
	cout << "Nhap mau so: ";
	is >> *obj.mauso;
	obj.checkNegative();
	return is;
}

ostream& operator<<(ostream& os, PhanSo obj)
{
	obj.checkNegative();
	os << *obj.tuso << " / " << *obj.mauso << endl;
	return os;
}

PhanSo& PhanSo::operator+=(const PhanSo& ps)
{
	*this->tuso = *this->tuso * *ps.mauso + *this->mauso * *ps.tuso;
	*this->mauso = *this->mauso * *ps.mauso;
	int _gcd = gcd(abs(*this->tuso), abs(*this->mauso));
	PhanSo temp(*this->tuso / _gcd, *this->mauso / _gcd);
	temp.checkNegative();
	return *this;
}

PhanSo& PhanSo::operator-=(const PhanSo& ps)
{
	*this->tuso = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	*this->mauso = *this->mauso * *ps.mauso;
	int _gcd = gcd(abs(*this->tuso), abs(*this->mauso));
	PhanSo temp(*this->tuso / _gcd, *this->mauso / _gcd);
	temp.checkNegative();
	return *this;
}

PhanSo& PhanSo::operator*=(const PhanSo& ps)
{
	*this->tuso = *this->tuso * *ps.tuso;
	*this->mauso = *this->mauso * *ps.mauso;
	int _gcd = gcd(abs(*this->tuso), abs(*this->mauso));
	PhanSo temp(*this->tuso / _gcd, *this->mauso / _gcd);
	temp.checkNegative();
	return *this;
}

PhanSo& PhanSo::operator/=(const PhanSo& ps)
{
	*this->tuso = *this->tuso * *ps.mauso;
	*this->mauso = *this->mauso * *ps.tuso;
	int _gcd = gcd(abs(*this->tuso), abs(*this->mauso));
	PhanSo temp(*this->tuso / _gcd, *this->mauso / _gcd);
	temp.checkNegative();
	return *this;
}

PhanSo PhanSo::operator++(int x)
{
	PhanSo result(*this);
	*this->tuso = *this->tuso + *this->mauso;
	return result;
}

PhanSo& PhanSo::operator++()
{
	*this->tuso = *this->tuso + *this->mauso;
	return *this;
}

PhanSo PhanSo::operator--(int x)
{
	PhanSo result(*this);
	*this->tuso = *this->tuso - *this->mauso;
	result.checkNegative();
	return result;
}

PhanSo& PhanSo::operator--()
{
	*this->tuso = *this->tuso - *this->mauso;
	checkNegative();
	return *this;
}

bool PhanSo::operator==(const PhanSo& ps)
{
	int result = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	if (result == 0)
		return true;
	else
		return false;
}

bool PhanSo::operator!=(const PhanSo& ps)
{
	int result = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	if (result != 0)
		return true;
	else
		return false;
}

bool PhanSo::operator>(const PhanSo& ps)
{
	int result = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	if (result > 0)
		return true;
	else
		return false;
}

bool PhanSo::operator<(const PhanSo& ps)
{
	int result = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	if (result < 0)
		return true;
	else
		return false;
}

bool PhanSo::operator>=(const PhanSo& ps)
{
	int result = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	if (result >= 0)
		return true;
	else
		return false;
}

bool PhanSo::operator<=(const PhanSo& ps)
{
	int result = *this->tuso * *ps.mauso - *this->mauso * *ps.tuso;
	if (result <= 0)
		return true;
	else
		return false;
}