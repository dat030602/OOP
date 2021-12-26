#include "HinhVuong.h"

HinhVuong::HinhVuong()
{
	canh = 0;
}

HinhVuong::HinhVuong(float canh)
{
	this->canh = canh;
}

HinhVuong::~HinhVuong()
{
	canh = 0;
}
float HinhVuong::LayCanh()
{
	return canh;
}
float HinhVuong::dientich()
{
	return canh * canh;
}
float HinhVuong::chuvi()
{
	return canh * 4;
}