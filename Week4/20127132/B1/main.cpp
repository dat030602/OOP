#include "PhanSo.h"

int main()
{
	PhanSo a;
	PhanSo b;
	cout << "Nhap phan so 1\n";
	cin >> a;
	cout << "\nNhap phan so 2\n";
	cin >> b;

	int choice;
	while (1)
	{
		cout << "\nHay lua chon:\n";
		cout << "1. Xuat tu, mau so\n";
		cout << "2. Cong 2 phan so\n";
		cout << "3. Tru 2 phan so\n";
		cout << "4. Nhan 2 phan so\n";
		cout << "5. Chia 2 phan so\n";
		cout << "6. Thoat\n";
		cout << "Nhap lua chon: ";
		cin >> choice;
		if (choice == 1)
		{
			cout << "Phan So 1:\nTu: ";
			cout << a.getTu();
			cout << "\nMau: " << a.getMau() << endl << endl;

			cout << "Phan So 2:\nTu: ";
			cout << a.getTu();
			cout << "\nMau: " << a.getMau() << endl << endl;
		}
		else if (choice == 2)
			cout << "Tong la: " << a + b << endl;
		else if (choice == 3)
			cout << "Hieu la: " << a - b << endl;
		else if (choice == 4)
			cout << "Tich la: " << a * b << endl;
		else if (choice == 5)
			cout << "Thuong la: " << a / b << endl;
		else if (choice == 6)
			break;
	}
	return 0;
}