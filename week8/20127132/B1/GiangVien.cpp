#include "GiangVien.h"

GiangVien::~GiangVien()
{
	HocHam = "";
	HocVi = "";
	SoNamGiangDay = -1;
};
double GiangVien::TinhLuong()
{
	return length() * SoNamGiangDay * 0.12 * 20000;
}

void GiangVien::Nhap()
{
	TruongDaiHoc::Nhap();
	cout << "Nhap Hoc Ham: ";
	cin.ignore();
	getline(cin, HocHam);
	cout << "Nhap Hoc Vi: ";
	getline(cin, HocVi);
	cout << "Nhap So Nam Giang Day: ";
	cin >> SoNamGiangDay;

	int size;
	cout << "Nhap So Mon Hoc: ";
	cin >> size;
	cout << "Nhap Mon Hoc:\n";
	TruongDaiHoc::NhapDanhSach(size);
}
void GiangVien::Xuat()
{
	TruongDaiHoc::Xuat();
	cout << "Hoc Ham: " << HocHam << endl;
	cout << "Hoc Vi: " << HocVi << endl;
	cout << "So Nam Giang Day: " << SoNamGiangDay << endl;
	cout << "Danh Sach Mon Hoc: " << endl;
	TruongDaiHoc::XuatDanhSach();
}