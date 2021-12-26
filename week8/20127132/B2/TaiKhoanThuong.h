#pragma once
#include "TaiKhoan.h"

class TaiKhoanThuong : public TaiKhoan
{
	string thongtin;
	bool taiKhoanThuong;
public:
	TaiKhoanThuong();
	TaiKhoanThuong(string TaiKhoan, string MatKhau, unsigned int SoDuTaiKhoan) : TaiKhoan(TaiKhoan, MatKhau, SoDuTaiKhoan)
	{
		thongtin = "Tai Khoan Thuong";
		taiKhoanThuong = true;
	}
	~TaiKhoanThuong();
	void IsNormal(bool& taiKhoanThuong) { taiKhoanThuong = this->taiKhoanThuong; };
	void TaoTaiKhoan();
	void XuatTaiKhoan();
};