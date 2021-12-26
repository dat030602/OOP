#pragma once
#include "TruongDaiHoc.h"

class TroGiang : public TruongDaiHoc
{
public:
	TroGiang() :TruongDaiHoc() {};
	TroGiang(string HoTen, int NgaySinh, int ThangSinh, int NamSinh,
		int MaSoNhanSu, vector<string> danhsach) :
		TruongDaiHoc(HoTen, NgaySinh, ThangSinh, NamSinh, MaSoNhanSu, danhsach) {};
	~TroGiang() {};
	virtual double TinhLuong();
	void Nhap();
	void Xuat();
};