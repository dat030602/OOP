#pragma once
#include "HinhChuNhat.h"

class HinhVuong :public HinhChuNhat
{
	//float chieudai, chieurong;
	float canh;
public:
	HinhVuong();
	HinhVuong(float);
	~HinhVuong();
	float LayCanh();
	float dientich();
	float chuvi();
};