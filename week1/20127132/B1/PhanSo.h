#pragma once
#include <iostream>
using namespace std;
class PhanSo
{
public:
	int tu, mau;
public:
	void input();
	void output();
	void reduce();
	void cong(PhanSo);
	void tru(PhanSo);
	void nhan(PhanSo);
	void chia(PhanSo);
};