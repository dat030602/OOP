#pragma once
#include "Linh.h"
class CungThu : public Linh
{
public:
	CungThu();
	~CungThu() {}
	CungThu(const CungThu&);
	CungThu(string, int, int, int, int, int);
	void Draw();
	void LevelUp();
};