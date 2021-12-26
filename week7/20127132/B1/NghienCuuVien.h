#pragma once
#include "TruongDaiHoc.h"

class NghienCuuVien : public TruongDaiHoc
{
	int SoNamNghienCuu;

public:
	NghienCuuVien() :TruongDaiHoc()
	{
		SoNamNghienCuu = -1;
	};
	NghienCuuVien(string HoTen, int NgaySinh, int ThangSinh, int NamSinh,
		int MaSoNhanSu, vector<string> danhsach, int SoNamNghienCuu) :
		TruongDaiHoc(HoTen, NgaySinh, ThangSinh, NamSinh, MaSoNhanSu, danhsach)
	{
		this->SoNamNghienCuu = SoNamNghienCuu;
	}
	~NghienCuuVien();
	double TinhLuong();
	void Nhap();
	void Xuat();
};