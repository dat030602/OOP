#include "TaiKhoanVip.h"

TaiKhoanVip::TaiKhoanVip()
{
	thongtin = "";
	taiKhoanThuong = true;
}
TaiKhoanVip::~TaiKhoanVip()
{
	thongtin = "";
	taiKhoanThuong = true;
}

void TaiKhoanVip::XuatTaiKhoan()
{
	TaiKhoan::XuatTaiKhoan();
	TaiKhoanVip::IsNormal(taiKhoanThuong);
	if (taiKhoanThuong)
		cout << "Tai Khoan Thuong\n";
	else
		cout << thongtin << endl;
}

void TaiKhoanVip::TaoTaiKhoan()
{
	TaiKhoan::TaoTaiKhoan();
	taiKhoanThuong = false;
}