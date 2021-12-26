#pragma once
#include "MauXe.h"
#include "XeThuongMai.h"

using namespace std;

class NhaMayOto
{
	vector<MauXe*> DanhSachMauXe;
public:
	NhaMayOto();
	~NhaMayOto();
	friend istream& operator>>(istream& is, NhaMayOto& obj);
	friend ostream& operator<<(ostream& os, NhaMayOto& obj);
	MauXe* LayMauXe1(string, string, string);
	//XeThuongMai SanXuatXeThuongMai(string, string, string, unsigned int);
};