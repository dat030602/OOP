#pragma once
#include "BaiHat.h"

class NhacBanQuyen : public BaiHat
{
	string nhacBanQuyen;
public:
	NhacBanQuyen() {};
	NhacBanQuyen(string TenBaiHat, vector<string> LoiBaiHat, string TenCaSi,
		string TheLoaiNhac, unsigned int NamSangTac, unsigned int LuotNghe, unsigned int GiaTriBanQuyen) :BaiHat(TenBaiHat, LoiBaiHat, TenCaSi,
			TheLoaiNhac, NamSangTac, LuotNghe, GiaTriBanQuyen)
	{
		nhacBanQuyen = "Nhac Ban Quyen";
	}
	void XuatThongTin();
	void PlayMusic();
	void TaoBaiHat();
	void BanQuyen(bool& check) { check = true; }
};