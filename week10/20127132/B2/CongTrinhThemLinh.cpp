#include "CongTrinhThemLinh.h"

CongTrinhThemLinh::CongTrinhThemLinh() :CongTrinh() {
	name = "TL";
};

CongTrinhThemLinh::CongTrinhThemLinh(const CongTrinhThemLinh& ps) :CongTrinh(ps) {};

CongTrinhThemLinh::CongTrinhThemLinh(string name, int heal, int dame, int def) :CongTrinh(name, heal, dame, def) {};

bool CongTrinhThemLinh::LevelUp()
{
    return false;
}

void CongTrinhThemLinh::Draw()
{
	GotoXY(LEFT + 4 + x * 9, TOP + 2 + 4 * y);
	cout << name;
}

void CongTrinhThemLinh::ThemCongTrinh()
{
	int y = TOP + 3;
	GotoXY(RIGHT + 5, y++);
	cout << "Nhap Ten Cong Trinh Them Linh(2 ki tu): ";
	GotoXY(RIGHT + 5, y++);
	cin >> name;
	while (name.size() != 2)
	{
		GotoXY(RIGHT + 5, y++);
		cout << "Nhap Lai Ten (2 ki tu): ";
		cin >> name;
	}
	GotoXY(RIGHT + 5, y++);
	cout << "Nhap Mau: ";
	cin >> heal;
	GotoXY(RIGHT + 5, y++);
	cout << "Nhap Suc Manh: ";
	cin >> dame;
	GotoXY(RIGHT + 5, y++);
	cout << "Nhap Phong Thu: ";
	cin >> def;
	for (int i = TOP + 3; i <= y; i++)
	{
		GotoXY(RIGHT + 5, i);
		cout << "                                          ";
	}
}