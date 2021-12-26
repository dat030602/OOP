#pragma once
#include "BaiHat.h"

class NhacPhoThong : public BaiHat
{
	string nhacPhoThong;
public:
	NhacPhoThong() {};
	NhacPhoThong(string TenBaiHat, vector<string> LoiBaiHat, string TenCaSi,
		string TheLoaiNhac, unsigned int NamSangTac, unsigned int LuotNghe, unsigned int GiaTriBanQuyen) :
		BaiHat(TenBaiHat, LoiBaiHat, TenCaSi, TheLoaiNhac, NamSangTac, LuotNghe, GiaTriBanQuyen)
	{
		nhacPhoThong = "Nhac Pho Thong";
	}
	void XuatThongTin();
	void PlayMusic();
	void TaoBaiHat();
	void BanQuyen(bool& check) { check = false; }
};