#include "MauXe.h"

MauXe::MauXe()
{
	PhienBanXe = "";
	MauSac = "";
	PhanLoai = "";
}
MauXe::MauXe(string PhienBanXe, string MauSac, string PhanLoai)
{
	this->PhienBanXe = PhienBanXe;
	this->MauSac = MauSac;
	this->PhanLoai = PhanLoai;
}
MauXe::~MauXe()
{
	PhienBanXe = "";
	MauSac = "";
	PhanLoai = "";
}
istream& operator>>(istream& is, MauXe& obj)
{
	cout << "Nhap Phien Ban Xe: ";
	getline(is, obj.PhienBanXe);
	cout << "Nhap Mau Sac: ";
	getline(is, obj.MauSac);
	cout << "Nhap Phan Loai: ";
	getline(is, obj.PhanLoai);
	return is;
}
ostream& operator<<(ostream& os, MauXe& obj)
{
	os << "Phien Ban Xe: " << obj.PhienBanXe << endl;
	os << "Mau Sac: " << obj.MauSac << endl;
	os << "Phan Loai: " << obj.PhanLoai << endl;
	return os;
}