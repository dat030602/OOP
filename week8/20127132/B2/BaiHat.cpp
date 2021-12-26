#include "BaiHat.h"

BaiHat::BaiHat()
{
	TenBaiHat = "";
	LoiBaiHat.push_back("");
	TenCaSi = "";
	TheLoaiNhac = "";
	NamSangTac = 0;
	LuotNghe = 0;
}
BaiHat::BaiHat(string TenBaiHat, vector<string> LoiBaiHat, string TenCaSi,
	string TheLoaiNhac, unsigned int NamSangTac, unsigned int LuotNghe, unsigned int GiaTriBanQuyen)
{
	this->TenBaiHat = TenBaiHat;
	this->LoiBaiHat = LoiBaiHat;
	this->TenCaSi = TenCaSi;
	this->TheLoaiNhac = TheLoaiNhac;
	this->NamSangTac = NamSangTac;
	this->LuotNghe = LuotNghe;
	this->GiaTriBanQuyen = GiaTriBanQuyen;
}
BaiHat::~BaiHat()
{
	TenBaiHat = "";
	LoiBaiHat.clear();
	TenCaSi = "";
	TheLoaiNhac = "";
	NamSangTac = 0;
	LuotNghe = 0;
}

void BaiHat::XuatThongTin()
{
	cout << "Ten Bai Hat : " << this->TenBaiHat << endl;
	cout << "Ten Ca Si : " << this->TenCaSi << endl;
	cout << "The Loai Nhac: " << this->TheLoaiNhac << endl;
	cout << "Nam Sang Tac : " << this->NamSangTac << endl;
	cout << "Luot Nghe : " << this->LuotNghe << endl;
	char ask = 'A';
	while (ask != 'Y' && ask != 'N')
	{
		cout << "\nBan co muon xem Lyric (Y/N): ";
		ask = toupper(_getch());
		if (ask == 'Y')
		{
			cout << endl << endl << this->TenBaiHat << " :\n";
			for (int i = 0; i < this->LoiBaiHat.size(); i++)
				cout << "\t" << this->LoiBaiHat[i] << endl;
		}
	}
	cout << endl;
}
void BaiHat::TaoBaiHat()
{
	cout << "Nhap Ten Bai Hat : ";
	cin.ignore();
	getline(cin, this->TenBaiHat);
	cout << "Nhap Ten Ca Si : ";
	getline(cin, this->TenCaSi);
	cout << "Nhap The Loai Nhac: ";
	getline(cin, this->TheLoaiNhac);
	cout << "Nhap Nam Sang Tac : ";
	cin >> this->NamSangTac;
	cout << "Nhap Luot Nghe : ";
	cin >> this->LuotNghe;
	cout << "Nhap Lyric (-1: Stop):\n";
	string temp = "";
	while (temp != "-1")
	{
		getline(cin, temp);
		if (temp != "-1")
			this->LoiBaiHat.push_back(temp);
	}
	cout << endl;
}
unsigned int BaiHat::LayGiaTriBanQuyen()
{
	return GiaTriBanQuyen;
}
void BaiHat::SuaGiaTriBanQuyen(unsigned int GiaTriBanQuyen)
{
	this->GiaTriBanQuyen = GiaTriBanQuyen;
}