#pragma once
#include "NhaMayOto.h"
#include "MauXe.h"

class XeThuongMai
{
	MauXe* m_MauXe;
	unsigned int GiaBan;
	string BienSoXe;
public:
	XeThuongMai();
	XeThuongMai(const XeThuongMai&);
	XeThuongMai(MauXe, unsigned int);
	XeThuongMai(string, string, string, unsigned int, string);
	~XeThuongMai();
	void CapNhatBienSoXe(string BienSoXe) {
		this->BienSoXe = BienSoXe;
	}
	XeThuongMai& operator=(const XeThuongMai&);
	friend istream& operator>>(istream& is, XeThuongMai& obj);
	friend ostream& operator<<(ostream& os, XeThuongMai& obj);
	XeThuongMai& operator-(int);
};

