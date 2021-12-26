#pragma once
#include "Linh.h"

class LinhKhien :public Linh
{
public:
	LinhKhien();
	~LinhKhien() {}
	LinhKhien(const LinhKhien&);
	LinhKhien(string, int, int, int, int, int);
	void Draw();
	void LevelUp();
};