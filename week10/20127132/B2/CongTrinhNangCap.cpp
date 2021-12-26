#include "CongTrinhNangCap.h"

CongTrinhNangCap::CongTrinhNangCap() :CongTrinh() {
	name = "NC";
};

CongTrinhNangCap::CongTrinhNangCap(const CongTrinhNangCap& ps) :CongTrinh(ps) {};

CongTrinhNangCap::CongTrinhNangCap(string name, int heal, int dame, int def) :CongTrinh(name, heal, dame, def) {};

bool CongTrinhNangCap::LevelUp()
{
    return true;
}

void CongTrinhNangCap::Draw()
{
	GotoXY(LEFT + 4 + x * 9, TOP + 2 + 4 * y);
	cout << name;
}

void CongTrinhNangCap::ThemCongTrinh()
{
	int y = TOP + 3;
	GotoXY(RIGHT + 5, y++);
	cout << "Nhap Ten Cong Trinh Nang Cap(2 ki tu): ";
	GotoXY(RIGHT + 5, y++);
	cin >> name;
	while (name.size() != 2)
	{
		GotoXY(RIGHT + 5, y++);
		cout << "Nhap Lai Ten (2 ki tu): ";
		cin >> name;
	}
	for (int i = TOP + 3; i <= y; i++)
	{
		GotoXY(RIGHT + 5, i);
		cout << "                                          ";
	}
}