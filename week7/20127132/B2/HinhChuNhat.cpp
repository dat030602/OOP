#include "HinhChuNhat.h"

HinhChuNhat::HinhChuNhat()
{
	chieudai = 0;
	chieurong = 0;
}

HinhChuNhat::HinhChuNhat(float chieudai, float chieurong)
{
	this->chieudai = chieudai;
	this->chieurong = chieurong;
}

HinhChuNhat::~HinhChuNhat()
{
	chieudai = 0;
	chieurong = 0;
}

float HinhChuNhat::LayChieuDai()
{
	return chieudai;
}

float HinhChuNhat::LayChieuRong()
{
	return chieurong;
}

float HinhChuNhat::chuvi()
{
	return (chieudai + chieurong) * 2;
}

float HinhChuNhat::dientich()
{
	return chieudai * chieurong;
}