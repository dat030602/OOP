#include "PhanSo.h"

int main()
{
	PhanSo a;
	cout << "Nhap phan so A:\n";
	cin >> a;
	PhanSo b;
	cout << "\nNhap phan so B:\n";
	cin >> b;
	int choice;
	while (1)
	{
		cout << "\nHay chon:\n";
		cout << "1. Toan Tu Gan\n";
		cout << "2. Toan tu +, -, *, /\n";
		cout << "3. Toan tu +=, -=, *=, /=\n";
		cout << "4. Toan tu ==, <, >, <=, >=, !=\n";
		cout << "5. Xuat\n";
		cout << "6. Thoat\n";
		cout << "Lua chon: ";
		cin >> choice;
		if (choice == 1)
		{
			PhanSo c;
			cout << "Nhap phan so muon gan:\n";
			cin >> c;
			cout << "Phan so muon gan (1 : A, 2 : B): ";
			cin >> choice;
			if (choice == 1)
			{
				a = c;
				cout << "Phan So Sau Khi Gan: ";
				cout << a;
			}
			else
			{
				b = c;
				cout << "Phan So Sau Khi Gan: ";
				cout << b;
			}
		}
		else if (choice == 2)
		{
			cout << "Nhap Toan Tu:\n";
			cout << "1. +\n";
			cout << "2. -\n";
			cout << "3. *\n";
			cout << "4. /\n";
			cout << "Lua chon: ";
			cin >> choice;
			if (choice == 1)
			{
				cout << "Phan So Sau Khi +: ";
				cout << a + b;
			}
			else if (choice == 2)
			{
				cout << "Phan So Sau Khi -: ";
				cout << a - b;
			}
			else if (choice == 3)
			{
				cout << "Phan So Sau Khi *: ";
				cout << a * b;
			}
			else if (choice == 4)
			{
				cout << "Phan So Sau Khi /: ";
				cout << a / b;
			}
		}
		else if (choice == 3)
		{
			PhanSo c;
			cout << "Nhap phan so muon thuc hien:\n";
			cin >> c;
			cout << "Phan so muon gan (1 : A, 2 : B): ";
			cin >> choice;
			if (choice == 1)
			{
				cout << "Nhap Toan Tu:\n";
				cout << "1. +=\n";
				cout << "2. -=\n";
				cout << "3. *=\n";
				cout << "4. /=\n";
				cout << "Lua chon: ";
				cin >> choice;
				if (choice == 1)
				{
					cout << "Phan So Sau Khi +=: ";
					a += c;
					cout << a;
				}
				else if (choice == 2)
				{
					cout << "Phan So Sau Khi -=: ";
					a *= c;
					cout << a;
				}
				else if (choice == 3)
				{
					cout << "Phan So Sau Khi *=: ";
					a *= c;
					cout << a;
				}
				else if (choice == 4)
				{
					cout << "Phan So Sau Khi /=: ";
					a /= c;
					cout << a;
				}
			}
			else
			{
				cout << "Nhap Toan Tu:\n";
				cout << "1. +=\n";
				cout << "2. -=\n";
				cout << "3. *=\n";
				cout << "4. /=\n";
				cout << "Lua chon: ";
				cin >> choice;
				if (choice == 1)
				{
					cout << "Phan So Sau Khi +=: ";
					b += c;
					cout << b;
				}
				else if (choice == 2)
				{
					cout << "Phan So Sau Khi -=: ";
					b *= c;
					cout << b;
				}
				else if (choice == 3)
				{
					cout << "Phan So Sau Khi *=: ";
					a *= c;
					cout << a;
				}
				else if (choice == 4)
				{
					cout << "Phan So Sau Khi /=: ";
					b /= c;
					cout << b;
				}
			}
		}
		else if (choice == 4)
		{
			cout << "Nhap Toan Tu:\n";
			cout << "1. ==\n";
			cout << "2. !=\n";
			cout << "3. >\n";
			cout << "4. >=\n";
			cout << "5. <\n";
			cout << "6. <=\n";
			cout << "Lua chon: ";
			cin >> choice;
			if (choice == 1)
			{
				if (a == b)
					cout << "Phan So A == Phan So B";
				else
					cout << "Phan So A != Phan So B";
			}
			else if (choice == 2)
			{
				if (a != b)
					cout << "Phan So A != Phan So B";
				else
					cout << "Phan So A == Phan So B";
			}
			else if (choice == 3)
			{
				if (a > b)
					cout << "Phan So A > Phan So B";
				else
					cout << "Phan So A <= Phan So B";
			}
			else if (choice == 4)
			{
				if (a >= b)
					cout << "Phan So A >= Phan So B";
				else
					cout << "Phan So A < Phan So B";
			}
			else if (choice == 5)
			{
				if (a > b)
					cout << "Phan So A < Phan So B";
				else
					cout << "Phan So A >= Phan So B";
			}
			else if (choice == 6)
			{
				if (a >= b)
					cout << "Phan So A <= Phan So B";
				else
					cout << "Phan So A > Phan So B";
			}
		}
		else if (choice == 5)
		{
			cout << "Phan So A: " << a;
			cout << "Phan So B: " << b;
		}
		else if (choice == 6)
			break;
	}
}