#pragma once
#include "MainHeader.h"

class CongTrinh
{
protected:
	string name;
	int heal;
	int dame;
	int def;
	int x, y;
public:
	CongTrinh();
	~CongTrinh();
	CongTrinh(const CongTrinh&);
	CongTrinh(string, int, int, int);
	string GetName();
	bool LinhDef();
	int X();
	int Y();
	int GetHeal();
	int GetDame();
	int GetDef();
	void setPos(int, int);
	virtual void Draw() = 0;
	virtual bool LevelUp() = 0;
	virtual void ThemCongTrinh() = 0;
};