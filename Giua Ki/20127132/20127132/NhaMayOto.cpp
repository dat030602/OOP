#include "NhaMayOto.h"

NhaMayOto::NhaMayOto()
{
}

NhaMayOto::~NhaMayOto()
{
	DanhSachMauXe.clear();
}
istream& operator>>(istream& is, NhaMayOto& obj)
{
	int size;
	cout << "Nhap So Luong Mau Xe Can Nhap: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		MauXe* temp = new MauXe();
		cout << "Xe " << i + 1 << ": \n";
		is >> *temp;
		obj.DanhSachMauXe.push_back(temp);
	}
	return is;
}
ostream& operator<<(ostream& os, NhaMayOto& obj)
{
	cout << "Danh Sach:\n";
	int size = obj.DanhSachMauXe.size();
	for (int i = 0; i < size; i++)
		os << *obj.DanhSachMauXe[i];
	return os;
}
MauXe* NhaMayOto::LayMauXe1(string PhienBanXe, string MauSac, string PhanLoai)
{
	int size = DanhSachMauXe.size();
	for (int i = 0; i < size; i++)
	{
		if (DanhSachMauXe[i]->LayPhienBanXe() == PhienBanXe &&
			DanhSachMauXe[i]->LayMauSac() == MauSac &&
			DanhSachMauXe[i]->LayPhanLoai() == PhanLoai)
			return DanhSachMauXe[i];
	}
	return new MauXe(PhienBanXe,MauSac,PhanLoai);
}
////XeThuongMai NhaMayOto::SanXuatXeThuongMai(string PhienBanXe, string MauSac, string PhanLoai, unsigned int GiaBan)
////{
////	MauXe* temp = LayMauXe1(PhienBanXe, MauSac, PhanLoai);
////	XeThuongMai temp1(*temp, GiaBan);
////	return temp1;
////}