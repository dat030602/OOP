#include "QuaiVat.h"

QuaiVat::QuaiVat()
{
	name = "";
	heal = 0;
	pow = 0;
	dame = 0;
	x = 0;
	y = 0;
}

QuaiVat::~QuaiVat()
{
	name = "";
	heal = -1;
	pow = -1;
	dame = -1;
	x = -1;
	y = -1;
}

QuaiVat::QuaiVat(const QuaiVat& ps)
{
	this->name = ps.name;
	this->heal = ps.heal;
	this->pow = ps.pow;
	this->dame = ps.dame;
	this->x = ps.x;
	this->y = ps.y;
}

QuaiVat::QuaiVat(string name, int heal, int pow, int dame)
{
	this->name = name;
	this->heal = heal;
	this->pow = pow;
	this->dame = dame;
}

void QuaiVat::setPos(int x, int y)
{
	this->x = x;
	this->y = y;
}

int QuaiVat::X()
{ 
	return x;
}

int QuaiVat::Y()
{ 
	return y; 
}

void QuaiVat::LevelUp()
{
	pow += 3;
	heal += 10;
}

int QuaiVat::GetDame()
{
	return dame + pow * 2;
}

bool QuaiVat::dead()
{
	return heal <= 0;
}

void QuaiVat::setHeal(int d)
{
	heal -= d;
}

void QuaiVat::ThemQuaiVat()
{
	int y = TOP + 3;
	GotoXY(RIGHT + 5, y++);
	cout << "Nhap Ten Quai Vat (2 ki tu): ";
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
	for (int i = TOP + 3; i <= y; i++)
	{
		GotoXY(RIGHT + 5, i);
		cout << "                                          ";
	}
	pow = 1;
}
void QuaiVat::Draw()
{
	GotoXY(LEFT + 4 + x * 9, TOP + 2 + 4 * y);
	cout << name;
}