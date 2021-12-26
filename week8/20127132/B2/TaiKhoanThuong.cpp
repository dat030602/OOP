#include "TaiKhoanThuong.h"

TaiKhoanThuong::TaiKhoanThuong()
{
	thongtin = "";
	taiKhoanThuong = false;
}
TaiKhoanThuong::~TaiKhoanThuong()
{
	thongtin = "";
	taiKhoanThuong = false;
}

void TaiKhoanThuong::XuatTaiKhoan()
{
	TaiKhoan::XuatTaiKhoan();
	//bool tk;
	IsNormal(taiKhoanThuong);
	if (taiKhoanThuong)
		cout << thongtin << endl;
	else
		cout << "Tai Khoan VIP\n";
}
void TaiKhoanThuong::TaoTaiKhoan()
{
	TaiKhoan::TaoTaiKhoan();
	taiKhoanThuong = true;
}