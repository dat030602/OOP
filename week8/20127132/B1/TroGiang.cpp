#include "TroGiang.h"

double TroGiang::TinhLuong()
{
	return length() * 0.3 * 18000;
}

void TroGiang::Nhap()
{
	TruongDaiHoc::Nhap();
	int size;
	cout << "Nhap So Mon Tro Giang: ";
	cin >> size;
	cout << "Nhap Mon Tro Giang:\n";
	TruongDaiHoc::NhapDanhSach(size);
}
void TroGiang::Xuat()
{
	TruongDaiHoc::Xuat();
	cout << "Danh Sach Mon Tro Giang: " << endl;
	TruongDaiHoc::XuatDanhSach();
}