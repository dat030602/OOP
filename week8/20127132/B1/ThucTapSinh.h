#pragma once

#include "TruongDaiHoc.h"
#include "NghienCuuVien.h"

class ThucTapSinh : public NghienCuuVien
{
	double ThoiHanThucTap;

public:
	ThucTapSinh() :NghienCuuVien()
	{
		ThoiHanThucTap = -1;
	};
	ThucTapSinh(string HoTen, int NgaySinh, int ThangSinh, int NamSinh,
		int MaSoNhanSu, vector<string> danhsach, int SoNamNghienCuu, double ThoiHanThucTap) :
		NghienCuuVien(HoTen, NgaySinh, ThangSinh, NamSinh, MaSoNhanSu, danhsach, SoNamNghienCuu)
	{
		this->ThoiHanThucTap = ThoiHanThucTap;
	}
	~ThucTapSinh();
	virtual double TinhLuong();
	void Nhap();
	void Xuat();
};

