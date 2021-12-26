#include "XeThuongMai.h"

XeThuongMai::XeThuongMai()
{
	m_MauXe = new MauXe;
	GiaBan = 0;
	BienSoXe = "";
}
XeThuongMai::XeThuongMai(MauXe obj, unsigned int GiaBan)
{
	m_MauXe = new MauXe;
	m_MauXe = &obj;
	this->GiaBan = GiaBan;
}
XeThuongMai::XeThuongMai(const XeThuongMai& ps)
{
	this->m_MauXe = ps.m_MauXe;
}
XeThuongMai::XeThuongMai(string PhienBanXe, string MauSac, string PhanLoai, unsigned int GiaBan, string BienSoXe)
{
	m_MauXe = new MauXe;
	m_MauXe->CapNhatPhienBanXe(PhienBanXe);
	m_MauXe->CapNhatMauSac(MauSac);
	m_MauXe->CapNhatPhanLoai(PhanLoai);
	this->GiaBan = GiaBan;
	this->BienSoXe = BienSoXe;
}
XeThuongMai::~XeThuongMai()
{
	GiaBan = 0;
	BienSoXe = "";
}
bool checkSame(string x, string y)
{
	int size;
	if (x.size() > y.size())
		size = x.size();
	else
		size = y.size();
	for (int i = 0; i < size; i++)
		if (x[i] != y[i])
			return false;
	return true;
}
XeThuongMai& XeThuongMai::operator=(const XeThuongMai& obj)
{
	if (checkSame(this->m_MauXe->LayPhienBanXe(), obj.m_MauXe->LayPhienBanXe()) &&
		checkSame(this->m_MauXe->LayMauSac(), obj.m_MauXe->LayMauSac()))
	{
		this->m_MauXe->CapNhatPhanLoai(obj.m_MauXe->LayPhanLoai());
		this->GiaBan = obj.GiaBan;
	}
	return *this;
}
istream& operator>>(istream& is, XeThuongMai& obj)
{
	is >> *obj.m_MauXe;
	cout << "Nhap Gia Ban: ";
	is >> obj.GiaBan;
	cout << "Nhap Bien So Xe: ";
	is.ignore();
	getline(is, obj.BienSoXe);
	return is;
}
ostream& operator<<(ostream& os, XeThuongMai& obj)
{
	os << *obj.m_MauXe;
	os << "Gia Ban: " << obj.GiaBan << endl;
	os << "Bien So Xe: " << obj.BienSoXe << endl;
	return os;
}
XeThuongMai& XeThuongMai::operator-(int x)
{
	this->GiaBan = this->GiaBan - this->GiaBan / 100 * 5.5;
	return *this;
}