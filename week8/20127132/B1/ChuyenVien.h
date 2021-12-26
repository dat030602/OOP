#pragma once
#include "TruongDaiHoc.h"

class ChuyenVien : public TruongDaiHoc
{
	int SoNamLamViec;

public:
	ChuyenVien() :TruongDaiHoc()
	{
		SoNamLamViec = -1;
	};
	ChuyenVien(string HoTen, int NgaySinh, int ThangSinh, int NamSinh,
		int MaSoNhanSu, vector<string> danhsach, int SoNamLamViec) :
		TruongDaiHoc(HoTen, NgaySinh, ThangSinh, NamSinh, MaSoNhanSu, danhsach)
	{
		this->SoNamLamViec = SoNamLamViec;
	}
	~ChuyenVien();
	virtual double TinhLuong();
	void Nhap();
	void Xuat();
};