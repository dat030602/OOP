#include "LinhKhien.h"

LinhKhien::LinhKhien() :Linh() {}

LinhKhien::LinhKhien(const LinhKhien& ps) : Linh(ps) {}

LinhKhien::LinhKhien(string name, int heal, int dame, int def, int x, int y) : Linh(name, heal, dame, def, x, y) {}

void LinhKhien::Draw()
{
	GotoXY(LEFT + 4 + x * 9, TOP + 2 + 4 * y);
	cout << name;
}

void LinhKhien::LevelUp()
{
	dame++;
	def += 5;
	heal += 10;
}
