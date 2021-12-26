#pragma once
#include <iostream>

using namespace std;

class HinhChuNhat
{
	float chieudai, chieurong;
public:
	HinhChuNhat();
	HinhChuNhat(float, float);
	~HinhChuNhat();
	float LayChieuDai();
	float LayChieuRong();
	float dientich();
	float chuvi();
};