#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class TruongDaiHoc
{
	string HoTen;
	int NgaySinh;
	int ThangSinh;
	int NamSinh;
	int MaSoNhanSu;
	vector<string> danhsach;
public:
	TruongDaiHoc();
	TruongDaiHoc(string, int, int, int, int, vector<string>);
	virtual double TinhLuong() = 0;
	int length() { return danhsach.size(); }
	vector<string> DanhSach() { return danhsach; }
	void Nhap();
	void NhapDanhSach(int);
	void Xuat();
	void XuatDanhSach();
};

