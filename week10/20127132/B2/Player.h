#pragma once
#include "MainHeader.h"
#include "Linh.h"
#include "CongTrinh.h"
#include "QuaiVat.h"

class Player
{
	int x, y;
	bool dead;
	vector<Linh*> m_Linh;
public:
	Player();
	~Player();
	int X();
	int Y();
	int length();
	bool IsDead();
	bool IsImpact(vector<Linh*>&);
	bool IsImpact(vector<QuaiVat*>&);
	bool IsImpact(CongTrinh*);
	void Draw();
	void move(char);
	void setPos(int, int);
};