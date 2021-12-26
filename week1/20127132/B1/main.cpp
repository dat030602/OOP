#include "PhanSo.h"

int main()
{
	PhanSo a, b;
	int choice;
	a.input();
	b.input();
	while (1)
	{
		cout << "Hay lua chon:\n";
		cout << "1. Nhap 2 phan so\n";
		cout << "2. Xuat 2 phan so\n";
		cout << "3. Rut gon 2 phan so\n";
		cout << "4. Cong 2 phan so\n";
		cout << "5. Tru 2 phan so (Phan so 1 - Phan so 2)\n";
		cout << "6. Nhan 2 phan so\n";
		cout << "7. Chia 2 phan so (Phan so 1 / Phan so 2)\n";
		cout << "8. Exit\n";
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
			a.reduce();
			a.output();
			b.reduce();
			b.output();
		}
		else if (choice == 4)
		{
			a.cong(b);
			a.output();
		}
		else if (choice == 5)
		{
			a.tru(b);
			a.output();
		}
		else if (choice == 6)
		{
			a.nhan(b);
			a.output();
		}
		else if (choice == 7)
		{
			a.chia(b);
			a.output();
		}
		else if (choice == 8)
			break;
		cout << endl;
	}
}