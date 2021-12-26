#include "Sach.h"

Sach::Sach()
{
	tensach = "";
	soluong = 0;
	tinhtrang = false;
}

Sach::Sach(string tensach, int soluong, bool tinhtrang)
{
	this->tensach = tensach;
	this->soluong = soluong;
	this->tinhtrang = tinhtrang;
}

Sach::~Sach()
{
	tensach = "";
	soluong = 0;
	tinhtrang = false;
}
istream& operator>> (istream& is, Sach& ps)
{
	cout << "Nhap ten sach: ";
	is.ignore();
	getline(is, ps.tensach);
	cout << "Nhap so luong: ";
	is >> ps.soluong;
	cout << "Nhap tinh trang sach (1: tot, 0: khong tot): ";
	is >> ps.tinhtrang;
	return is;
}
ostream& operator<< (ostream& os, Sach& ps)
{
	os << "Ten sach: " << ps.tensach << endl;
	os << "So Luong: " << ps.soluong << endl;
	if (ps.tinhtrang)
		os << "Tinh trang: Tot" << endl;
	else
		os << "Tinh trang: Khong tot" << endl;
	return os;
}
