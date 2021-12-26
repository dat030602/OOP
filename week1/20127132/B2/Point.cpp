#include "Point.h"
void Point::input()
{
	cout << "Nhap x: ";
	cin >> x;
	cout << "Nhap y: ";
	cin >> y;
}
void Point::output()
{
	cout << "(" << x << " ; " << y << ")\n";
}
double Point::module(Point a)
{
	double temp1 = x-a.x;
	double temp2 = y - a.y;
	return sqrt(temp1 * temp1 + temp2 * temp2);
}