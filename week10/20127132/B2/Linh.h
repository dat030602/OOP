#pragma once
#include "MainHeader.h"
class Linh
{
protected:
	string name;
	int heal;
	int dame;
	int def;
	int x, y;
public:
	Linh();
	~Linh();
	Linh(const Linh&);
	Linh(string, int, int, int, int, int);
	string GetName();
	int GetDame();
	int X();
	int Y();
	bool battle(int);
	void setPos(int, int);
	virtual void Draw() = 0;
	virtual void LevelUp() = 0;
};