#include "HCN.h"

int main()
{
	HCN a, b, c, d;
	cout << "Nhap diem A:\n";
	a.input();
	cout << "Nhap diem B:\n";
	b.input();
	cout << "Nhap diem C:\n";
	c.input();
	cout << "Nhap diem D:\n";
	d.input();
	if (a.checkHCN(b, c, d))
	{
		cout << "Day la hinh chu nhat\n";
		cout << "Dien tich la: " << a.Area(a, b, c) << endl;
		cout << "Chu vi la: " << a.Perimeter(a, b, c) << endl;
	}
	else
		cout << "Day khong la hinh chu nhat";
}