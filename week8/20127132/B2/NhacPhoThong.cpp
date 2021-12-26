#include "NhacPhoThong.h"

void NhacPhoThong::XuatThongTin()
{
	cout << nhacPhoThong << endl;
	BaiHat::XuatThongTin();
}
void NhacPhoThong::PlayMusic()
{
	//Choi Nhac
	cout << "Ban Dang Nghe Bai: " << BaiHat::LayTenBaiHat() << "(Chi Mang Tinh Chat Gia Lap)\n";
	Sleep(3000);
}
void NhacPhoThong::TaoBaiHat()
{
	BaiHat::TaoBaiHat();
	nhacPhoThong = "Nhac Pho Thong";
}