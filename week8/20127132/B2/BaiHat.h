#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <fstream>
#include <Windows.h>

using namespace std;


class BaiHat
{
	string TenBaiHat;
	vector<string> LoiBaiHat;
	string TenCaSi;
	string TheLoaiNhac;
	unsigned int NamSangTac;
	unsigned int LuotNghe;
	unsigned int GiaTriBanQuyen;
public:
	BaiHat();
	BaiHat(string, vector<string>, string, string, unsigned int, unsigned int, unsigned int);
	~BaiHat();
	string LayTenBaiHat() { return TenBaiHat; }
	unsigned int LayLuotNghe() { return LuotNghe; }
	unsigned int LayGiaTriBanQuyen();
	void SuaGiaTriBanQuyen(unsigned int);
	virtual void XuatThongTin();
	virtual void PlayMusic() {};
	virtual void TaoBaiHat();
	virtual void BanQuyen(bool&) {};
};

int partition(vector<BaiHat*>& DanhSachNhac, int l, int r);
void quicksort(vector<BaiHat*>& DanhSachNhac, int l, int r);
void InitMusic(vector<BaiHat*>& DanhsachNhac);