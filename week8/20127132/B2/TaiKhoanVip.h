#pragma once
#include "TaiKhoan.h"
class TaiKhoanVip : public TaiKhoan
{
	string thongtin;
	bool taiKhoanThuong;
public:
	TaiKhoanVip();
	TaiKhoanVip(string TaiKhoan, string MatKhau, unsigned int SoDuTaiKhoan) : TaiKhoan(TaiKhoan, MatKhau, SoDuTaiKhoan)
	{
		thongtin = "Tai Khoan VIP";
		taiKhoanThuong = false;
	}
	~TaiKhoanVip();
	void IsNormal(bool& taiKhoanThuong) { taiKhoanThuong = this->taiKhoanThuong; };
	void XuatTaiKhoan();
	void TaoTaiKhoan();
};