#pragma once
#include "MainHeader.h"

class QuaiVat
{
	string name;
	int heal;
	int pow;
	int dame;
	int x, y;
public:
	QuaiVat();
	~QuaiVat();
	QuaiVat(const QuaiVat&);
	QuaiVat(string, int, int, int);
	int X();
	int Y();
	int GetDame();
	bool dead();
	void Draw();
	void LevelUp();
	void setHeal(int);
	void setPos(int, int);
	void ThemQuaiVat();
};