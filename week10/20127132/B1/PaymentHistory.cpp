#include "PaymentHistory.h"

PaymentHistory::PaymentHistory()
{
	SoTaiKhoan = "";
	SoTienChuyenKhoan = 0;
	NoidungChuyenKhoan = "";
	NgayGiaoDich = "01/01/1990";
}
PaymentHistory::PaymentHistory(const PaymentHistory& ps)
{
	SoTaiKhoan = ps.SoTaiKhoan;
	SoTienChuyenKhoan = ps.SoTienChuyenKhoan;
	NoidungChuyenKhoan = ps.NoidungChuyenKhoan;
	NgayGiaoDich = ps.NgayGiaoDich;
}
PaymentHistory::PaymentHistory(string SoTaiKhoan, double SoTienChuyenKhoan, string NoidungChuyenKhoan, string NgayGiaoDich)
{
	this->SoTaiKhoan = SoTaiKhoan;
	this->SoTienChuyenKhoan = SoTienChuyenKhoan;
	this->NoidungChuyenKhoan = NoidungChuyenKhoan;
	this->NgayGiaoDich = NgayGiaoDich;
}
PaymentHistory::~PaymentHistory()
{
	SoTaiKhoan = "";
	SoTienChuyenKhoan = 0;
	NoidungChuyenKhoan = "";
	NgayGiaoDich = "";
}
void PaymentHistory::showHistory()
{
	cout.precision(0);
	cout << "So Tai Khoan: " << SoTaiKhoan << endl;
	cout << "So Tien Chuyen Khoan: " << fixed << SoTienChuyenKhoan << endl;
	cout << "Noi Dung Chuyen Khoan: " << NoidungChuyenKhoan << endl;
	cout << "Ngay Giao Dich: " << NgayGiaoDich << endl << endl;
}

double PaymentHistory::getSoTienChuyenKhoan()
{
	return SoTienChuyenKhoan;
}

void PaymentHistory::NhapLichSu()
{
	cout << "Nhap So Tai Khoan Muon Chuyen: ";
	cin >> SoTaiKhoan;
	cout << "Nhap So Tien Muon Chuyen: ";
	cin >> SoTienChuyenKhoan;
	cout << "Nhap Noi Dung Chuyen Khoan: ";
	cin.ignore();
	getline(cin, NoidungChuyenKhoan);
	cout << "Nhap Ngay Giao Dich: ";
	cin >> NgayGiaoDich;
}