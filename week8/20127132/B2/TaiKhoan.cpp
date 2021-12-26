#include "TaiKhoan.h"

TaiKhoan::TaiKhoan()
{
	taiKhoan = "";
	MatKhau = "";
	SoDuTaiKhoan = 0;
}
TaiKhoan::TaiKhoan(string TaiKhoan, string MatKhau, unsigned int SoDuTaiKhoan)
{
	this->taiKhoan = TaiKhoan;
	this->MatKhau = MatKhau;
	this->SoDuTaiKhoan = SoDuTaiKhoan;
}
TaiKhoan::~TaiKhoan()
{
	taiKhoan = "";
	SoDuTaiKhoan = 0;
	MatKhau = "";
}
bool checkSpace(string a)
{
	for (int i = 0; i < a.size(); i++)
		if (a[i] == ' ')
			return true;
	return false;
}
void TaiKhoan::NhapTaiKhoan()
{
	cout << "Nhap Tai Khoan: ";
	cin.ignore();
	getline(cin, taiKhoan);
	cout << "Nhap Mat Khau: ";
	getline(cin, MatKhau);
	while (MatKhau.size() < 8 || checkSpace(MatKhau))
	{
		cout << "Nhap Lai Mat Khau: ";
		getline(cin, MatKhau);
	}
}
void TaiKhoan::TaoTaiKhoan()
{
	cout << "Nhap Tai Khoan: ";
	cin.ignore();
	getline(cin, taiKhoan);
	cout << "Nhap Mat Khau: ";
	getline(cin, MatKhau);
	while (MatKhau.size() < 8 || checkSpace(MatKhau))
	{
		cout << "Nhap Lai Mat Khau: ";
		getline(cin, MatKhau);
	}
	cout << "Nap Tien: ";
	cin >> SoDuTaiKhoan;
}
void TaiKhoan::XuatTaiKhoan()
{
	cout << "Tai Khoan : " << taiKhoan << endl;
	cout << "Mat Khau : " << MatKhau << endl;
}
unsigned int TaiKhoan::LaySoDuTaiKhoan()
{
	return SoDuTaiKhoan;
}
void TaiKhoan::SuaSoDuTaiKhoan(unsigned int SoDuTaiKhoan)
{
	this->SoDuTaiKhoan = SoDuTaiKhoan;
}
string TaiKhoan::KiemTraTaiKhoan()
{
	fstream fi;
	fi.open("users.txt");
	string temp1, temp2 , temp3;
	unsigned int temp4;
	while (!fi.eof())
	{
		getline(fi, temp1, '\n');
		getline(fi, temp2, '\n');
		getline(fi, temp3, '\n');
		fi >> temp4;
		if (temp1 == taiKhoan && temp2 == MatKhau)
		{
			fi.close();
			SoDuTaiKhoan = temp4;
			return temp3;
		}
		getline(fi, temp3, '\n');
	}
	fi.close();
	return "";
}
string TaiKhoan::LayTaiKhoan()
{
	return taiKhoan;
}
string TaiKhoan::LayMatKhau()
{
	return MatKhau;
}