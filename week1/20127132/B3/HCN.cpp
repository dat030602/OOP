#include "HCN.h"

void HCN::input()
{
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
}
void HCN::output()
{
	cout << "(" << x << " ; " << y << ")\n";
}
bool HCN::checkHCN(HCN a, HCN b, HCN c)
{
	int temp1 = (a.x - x)*(c.x - x) + (a.y - y) * (c.y - y);
	int temp2 = (b.x - c.x) * (c.x - x) + (b.y - c.y) * (c.y - y);
	int temp3 = (a.x - x) * (b.x - a.x) + (a.y - y) * (b.y - a.y);
	if (!temp1 && !temp2 && !temp3)
		return 1;
	else
		return 0;
}
int HCN::module1(HCN a, HCN b)
{
	return sqrt((b.x - a.x)* (b.x - a.x) + (b.y - a.y)*(b.y - a.y));
}
int HCN::Perimeter(HCN a, HCN b, HCN c)
{
	return (module1(a, b) + module1(b, c)) * 2;
}
int HCN::Area(HCN a, HCN b, HCN c)
{
	return module1(a, b) * module1(b, c);
}