#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;


class PaymentHistory
{
	string SoTaiKhoan;
	double SoTienChuyenKhoan;
	string NoidungChuyenKhoan;
	string NgayGiaoDich;
public:
	PaymentHistory();
	PaymentHistory(const PaymentHistory&);
	PaymentHistory(string, double, string, string);
	~PaymentHistory();
	double getSoTienChuyenKhoan();
	void NhapLichSu();
	void showHistory();
};
