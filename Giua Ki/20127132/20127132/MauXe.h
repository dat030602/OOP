#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MauXe
{
	string PhienBanXe;
	string MauSac;
	string PhanLoai;
public:
	MauXe();
	MauXe(string, string, string);
	~MauXe();
	friend istream& operator>>(istream& is, MauXe& obj);
	friend ostream& operator<<(ostream& os, MauXe& obj);
	string LayPhienBanXe() { return PhienBanXe; }
	string LayMauSac() {return MauSac;}
	string LayPhanLoai() { return PhanLoai;}
	void CapNhatPhienBanXe(string PhienBanXe){this->PhienBanXe = PhienBanXe;}
	void CapNhatMauSac(string MauSac){	this->MauSac = MauSac;}
	void CapNhatPhanLoai(string PhanLoai){	this->PhanLoai = PhanLoai;}
};