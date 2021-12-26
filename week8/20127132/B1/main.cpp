#include "TruongDaiHoc.h"
#include "GiangVien.h"
#include "ChuyenVien.h"
#include "NghienCuuVien.h"
#include "TroGiang.h"
#include "ThucTapSinh.h"

int main()
{
	vector<GiangVien*> m_GiangVien;
	vector<TroGiang*> m_TroGiang;
	vector<NghienCuuVien*> m_NghienCuuVien;
	vector<ChuyenVien*> m_ChuyenVien;
	vector<ThucTapSinh*> m_ThucTapSinh;
	int size, choose;
	double luong = 0;
	double luong_max = 0;
	while (1)
	{
		cout << "1. Them Giang vien" << endl;
		cout << "2. Them Tro Giang" << endl;
		cout << "3. Them Nghien Cuu Vien" << endl;
		cout << "4. Them Chuyen Vien" << endl;
		cout << "5. Them Thuc Tap Sinh" << endl;
		cout << "6. Xuat Tat Ca Giang vien" << endl;
		cout << "7. Xuat Tat Ca Tro Giang" << endl;
		cout << "8. Xuat Tat Ca Nghien Cuu Vien" << endl;
		cout << "9. Xuat Tat Ca Chuyen Vien" << endl;
		cout << "10. Xuat Tat Ca Thuc Tap Sinh" << endl;
		cout << "11. Luong Cua Nhan Vien" << endl;
		cout << "12. Luong Cao Nhat Cua Nhan Vien" << endl;
		cout << "13. Thoat" << endl;
		cout << "Nhap Lua Chon: ";
		cin >> choose;
		if (choose == 1)
		{
			GiangVien* temp = new GiangVien;
			temp->Nhap();
			m_GiangVien.push_back(temp);
			m_GiangVien[0]->Xuat();
			double luongTemp = temp->TinhLuong();
			luong += luongTemp;
			if (luong_max < luongTemp)
				luong_max = luongTemp;
		}
		else if (choose == 2)
		{
			TroGiang* temp = new TroGiang;
			temp->Nhap();
			m_TroGiang.push_back(temp);
			double luongTemp = temp->TinhLuong();
			luong += luongTemp;
			if (luong_max < luongTemp)
				luong_max = luongTemp;
		}
		else if (choose == 3)
		{
			NghienCuuVien* temp = new NghienCuuVien;
			temp->Nhap();
			m_NghienCuuVien.push_back(temp);
			double luongTemp = temp->TinhLuong();
			luong += luongTemp;
			if (luong_max < luongTemp)
				luong_max = luongTemp;
		}
		else if (choose == 4)
		{
			ChuyenVien* temp = new ChuyenVien;
			temp->Nhap();
			m_ChuyenVien.push_back(temp);
			double luongTemp = temp->TinhLuong();
			luong += luongTemp;
			if (luong_max < luongTemp)
				luong_max = luongTemp;
		}
		else if (choose == 5)
		{
			ThucTapSinh* temp = new ThucTapSinh;
			temp->Nhap();
			m_ThucTapSinh.push_back(temp);
			double luongTemp = temp->TinhLuong();
			luong += luongTemp;
			if (luong_max < luongTemp)
				luong_max = luongTemp;
		}
		else if (choose == 6)
		{
			for (int i = 0; i < m_GiangVien.size(); i++)
				m_GiangVien[i]->Xuat();
		}
		else if (choose == 7)
		{
			for (int i = 0; i < m_TroGiang.size(); i++)
				m_TroGiang[i]->Xuat();
		}
		else if (choose == 8)
		{
			for (int i = 0; i < m_NghienCuuVien.size(); i++)
				m_NghienCuuVien[i]->Xuat();
		}
		else if (choose == 9)
		{
			for (int i = 0; i < m_ChuyenVien.size(); i++)
				m_ChuyenVien[i]->Xuat();
		}
		else if (choose == 10)
		{
			for (int i = 0; i < m_ThucTapSinh.size(); i++)
				m_ThucTapSinh[i]->Xuat();
		}
		else if (choose == 11)
			cout << "\nTong luong can tra la: " << luong << endl;
		else if (choose == 12)
			cout << "\Muc luong cao nhat la: " << luong_max << endl;
		else if (choose == 13)
			break;
	}
}