#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>

using namespace std;

class TaiKhoan
{
	string taiKhoan;
	string MatKhau;
	unsigned int SoDuTaiKhoan;
public:
	TaiKhoan();
	TaiKhoan(string, string, unsigned int);
	~TaiKhoan();
	string KiemTraTaiKhoan();
	string LayTaiKhoan();
	string LayMatKhau();
	unsigned int LaySoDuTaiKhoan();
	void SuaSoDuTaiKhoan(unsigned int SoDuTaiKhoan);
	void NhapTaiKhoan();
	virtual void TaoTaiKhoan();
	virtual void XuatTaiKhoan();
	virtual void IsNormal(bool&) {};
};
