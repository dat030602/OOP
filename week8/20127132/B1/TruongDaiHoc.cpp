#include "TruongDaiHoc.h"

TruongDaiHoc::TruongDaiHoc()
{
	HoTen = "";
	NgaySinh = -1;
	ThangSinh = -1;
	NamSinh = -1;
	MaSoNhanSu = -1;
}

TruongDaiHoc::TruongDaiHoc(string HoTen, int NgaySinh, int ThangSinh, int NamSinh, int MaSoNhanSu, vector<string> danhsach)
{
	this->HoTen = HoTen;
	this->NgaySinh = NgaySinh;
	this->ThangSinh = ThangSinh;
	this->NamSinh = NamSinh;
	this->MaSoNhanSu = MaSoNhanSu;
	this->danhsach = danhsach;
}
void TruongDaiHoc::Nhap()
{
	cout << "Nhap Ho Ten: ";
	cin.ignore();
	getline(cin, HoTen);
	cout << "Nhap Ngay Sinh: ";
	cin >> NgaySinh;
	cout << "Nhap Thang Sinh: ";
	cin >> ThangSinh;
	cout << "Nhap Nam Sinh: ";
	cin >> NamSinh;
	cout << "Nhap Ma So Nhan Su: ";
	cin >> MaSoNhanSu;
}
void TruongDaiHoc::Xuat()
{
	cout << "Ten: " << HoTen << endl;
	cout << "Ngay/Thang/Nam Sinh: ";
	if (NgaySinh < 10)
		cout << 0;
	cout << NgaySinh << " / ";
	if (ThangSinh < 10)
		cout << 0;
	cout << ThangSinh << " / " << NamSinh << endl;
	cout << "Ma So Nhan Su: " << MaSoNhanSu << endl;
}
void TruongDaiHoc::NhapDanhSach(int size)
{
	string temp;
	cin.ignore();
	for (int i = 0; i < size; i++)
	{
		getline(cin, temp);
		danhsach.push_back(temp);
	}
}
void TruongDaiHoc::XuatDanhSach()
{
	for (int i = 0; i < danhsach.size(); i++)
		cout << "\t" << i + 1 << ". " << danhsach[i] << endl;
}