#include "NhanVien.h"

int main()
{
	vector<NhanVien> m_nhanVien;
	int choice;
	while (1)
	{
		cout << "\nHay lua chon: ";
		cout << "\n1. Them nhan vien";
		cout << "\n2. Xuat thong toan bo nhan vien";
		cout << "\n3. Xuat thong 1 nhan vien";
		cout << "\n4. Sao chep thong tin nhan vien nay sang nhan vien kia";
		cout << "\n5. Thoat";
		cout << "\nLua chon: ";
		cin >> choice;
		if (choice == 1)
		{
			NhanVien a;
			cin >> a;
			m_nhanVien.push_back(a);
		}
		else if (choice == 2)
		{
			for (int i = 0; i < m_nhanVien.size(); i++)
				cout << m_nhanVien[i];
		}
		else if (choice == 3)
		{
			string name;
			cout << "Nhap ten: ";
			getline(cin, name);
			int pos = search(m_nhanVien, name);
			if (pos == -1)
				cout << "Khong tim thay Nhan vien";
			else
				cout << m_nhanVien[pos] << endl;
		}
		else if (choice == 4)
		{
			string name1;
			cout << "Nhap ten duoc sao chep: ";
			getline(cin, name1);
			int pos1 = search(m_nhanVien, name1);
			string name2;
			cout << "Nhap ten muon sao chep: ";
			getline(cin, name2);
			int pos2 = search(m_nhanVien, name2);
			if (pos1 == -1 || pos2 == -1)
				cout << "Khong tim thay Nhan vien";
			else
			{
				m_nhanVien[pos2] = m_nhanVien[pos1];
				cout << m_nhanVien[pos2] << endl << m_nhanVien[pos1] << endl;
			}
		}
		else if (choice == 5)
			break;
	}
	return 0;
}