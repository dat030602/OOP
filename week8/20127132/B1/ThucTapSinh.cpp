#include "ThucTapSinh.h"

ThucTapSinh::~ThucTapSinh()
{
	ThoiHanThucTap = -1;
};
double ThucTapSinh::TinhLuong()
{
	int len = 0;
	vector<string> temp = TruongDaiHoc::DanhSach();
	for (int i = 0; i < length(); i++)
		if (temp[i][0] == 'R')
			len++;
	return (len * 10 / 100) * 10000;
}

void ThucTapSinh::Nhap()
{
	TruongDaiHoc::Nhap();
	cout << "Nhap Thoi Han Thuc Tap (thang): ";
	cin >> ThoiHanThucTap;
	int size;
	cout << "Nhap So Du An Giao Duc: ";
	cin >> size;
	cout << "Nhap Du An Nghien Cuu Du Bi:\n";
	TruongDaiHoc::NhapDanhSach(size);
}
void ThucTapSinh::Xuat()
{
	TruongDaiHoc::Xuat();
	cout << "Thoi Han Thuc Tap: " << ThoiHanThucTap << endl;
	cout << "Danh Sach Du An Nghien Cuu Du Bi: " << endl;
	TruongDaiHoc::XuatDanhSach();
}