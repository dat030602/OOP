#pragma once
#include "TruongDaiHoc.h"

class GiangVien : public TruongDaiHoc
{
	string HocHam;
	string HocVi;
	int SoNamGiangDay;

public:
	GiangVien() :TruongDaiHoc()
	{
		HocHam = "";
		HocVi = "";
		SoNamGiangDay = -1;
	};
	GiangVien(string HoTen, int NgaySinh, int ThangSinh, int NamSinh,
		int MaSoNhanSu, vector<string> danhsach, string HocHam, string HocVi, int SoNamGiangDay):
		TruongDaiHoc(HoTen, NgaySinh, ThangSinh, NamSinh, MaSoNhanSu, danhsach)
	{
		this->HocHam = HocHam;
		this->HocVi = HocVi;
		this->SoNamGiangDay = SoNamGiangDay;
	}
	~GiangVien();
	virtual double TinhLuong();
	void Nhap();
	void Xuat();
};