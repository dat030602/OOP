#include "MangSoNguyen.h"

MangSoNguyen::MangSoNguyen()
{
	kichthuoc = 1;
	dulieu = new int[kichthuoc];
}
MangSoNguyen::MangSoNguyen(int kichthuoc, int dulieu[])
{
	delete[] this->dulieu;
	this->kichthuoc = kichthuoc;
	this->dulieu = new int[kichthuoc];
	for (int i = 0; i < kichthuoc; i++)
		this->dulieu[i] = dulieu[i];
}

MangSoNguyen::MangSoNguyen(const MangSoNguyen& ps)
{
	delete[] this->dulieu;
	this->kichthuoc = ps.kichthuoc;
	this->dulieu = new int[ps.kichthuoc];
	for (int i = 0; i < ps.kichthuoc; i++)
		this->dulieu[i] = ps.dulieu[i];
}
MangSoNguyen::~MangSoNguyen()
{
	kichthuoc = 0;
	delete[] dulieu;
}

istream& operator>> (istream& is, MangSoNguyen& ps)
{
	cout << "Nhap kich thuoc: ";
	is >> ps.kichthuoc;
	delete[] ps.dulieu;
	ps.dulieu = new int[ps.kichthuoc];
	for (int i = 0; i < ps.kichthuoc; i++)
	{
		cout << "a[" << i << "] = ";
		is >> ps.dulieu[i];
	}
	return is;
}
ostream& operator<< (ostream& os, MangSoNguyen& ps)
{
	cout << "{ ";
	for (int i = 0; i < ps.kichthuoc; i++)
	{
		os << ps.dulieu[i];
		if (i == ps.kichthuoc - 1)
			cout << " }\n";
		else
			cout << ", ";
	}
	return os;
}
MangSoNguyen& MangSoNguyen::operator++(int x)
{
	for (int i = 0; i < this->kichthuoc; i++)
		*(this->dulieu + i) += 1;
	return *this;
}
MangSoNguyen& MangSoNguyen::operator++()
{
	for (int i = 0; i < this->kichthuoc; i++)
		*(this->dulieu + i) += 1;
	return *this;
}
MangSoNguyen& MangSoNguyen::operator--(int x)
{
	for (int i = 0; i < this->kichthuoc; i++)
		*(this->dulieu + i) -= 1;
	return *this;
}
MangSoNguyen& MangSoNguyen::operator--()
{
	for (int i = 0; i < this->kichthuoc; i++)
		*(this->dulieu + i) -= 1;
	return *this;
}
MangSoNguyen& MangSoNguyen::operator=(int dulieu1[])
{
	delete[] this->dulieu;
	int size = sizeof(dulieu1);
	this->dulieu = new int[size];
	this->kichthuoc = size;
	for (int i = 0; i < size; i++)
		this->dulieu[i] = dulieu1[i];
	return *this;
}

MangSoNguyen& MangSoNguyen::operator+(const MangSoNguyen& ps)
{
	int size = min(this->kichthuoc, ps.kichthuoc);
	for (int i = 0; i < size; i++)
		this->dulieu[i] += ps.dulieu[i];
	return *this;
}