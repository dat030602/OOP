#include "CungThu.h"

CungThu::CungThu() :Linh() {}

CungThu::CungThu(const CungThu& ps) : Linh(ps) {}

CungThu::CungThu(string name, int heal, int dame, int def, int x, int y) : Linh(name, heal, dame, def, x, y) {}

void CungThu::Draw()
{
	GotoXY(LEFT + 4 + x * 9, TOP + 2 + 4 * y);
	cout << name;
}
void CungThu::LevelUp()
{
	dame += 5;
	def++;
	heal += 10;
}
