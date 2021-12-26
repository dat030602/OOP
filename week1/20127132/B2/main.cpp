#include "Point.h"

int main()
{
	Point a, b;
	int choice;
	a.input();
	b.input();
	while (1)
	{
		cout << "Hay lua chon:\n";
		cout << "1. Nhap 2 diem\n";
		cout << "2. Xuat 2 diem\n";
		cout << "3. Khoang cach 2 diem\n";
		cout << "4. Exit\n";
		cout << "Nhap lua chon: ";
		cin >> choice;
		if (choice == 1)
		{
			a.input();
			b.input();
		}
		else if (choice == 2)
		{
			a.output();
			b.output();
		}
		else if (choice == 3)
		{
			cout << a.module(b);
		}
		else
			break;
		cout << endl;
	}
}