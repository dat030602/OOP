#include "NhacBanQuyen.h"

void NhacBanQuyen::XuatThongTin()
{
	cout << nhacBanQuyen << endl;
	BaiHat::XuatThongTin();
}
void NhacBanQuyen::PlayMusic()
{
	//Choi Nhac
	cout << "Ban Dang Nghe Bai: " << BaiHat::LayTenBaiHat() << "(Chi Mang Tinh Chat Gia Lap)\n";
	Sleep(3000);
}
void NhacBanQuyen::TaoBaiHat()
{
	BaiHat::TaoBaiHat();
	nhacBanQuyen = "Nhac Ban Quyen";
	cout << "Gia Tri Ban Quyen: ";
	unsigned int temp;
	cin >> temp;
	BaiHat::SuaGiaTriBanQuyen(temp);
}