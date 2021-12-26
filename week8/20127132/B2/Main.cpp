#include "BaiHat.h"
#include "NhacBanQuyen.h"
#include "NhacPhoThong.h"
#include "TaiKhoan.h"
#include "TaiKhoanThuong.h"
#include "TaiKhoanVip.h"

int main()
{
	SetConsoleOutputCP(65001);
	vector<BaiHat*> PlayList;
	vector<BaiHat*> DanhSachNhac;
	InitMusic(DanhSachNhac);
	TaiKhoan* NguoiDung = new TaiKhoan;
	int choose;
	while (1)
	{
		cout << "1. Dang Nhap\n2. Tao Tai Khoan\nNhap Lua Chon: ";
		cin >> choose;
		if (choose == 1)
		{
			cout << "Dang Nhap:\n";
			NguoiDung->NhapTaiKhoan();
			while (NguoiDung->KiemTraTaiKhoan() == "")
			{
				cout << "Tai Khoan Hoac Mat Khau Cua Ban Da Sai !\n";
				NguoiDung->NhapTaiKhoan();
			}
			if (NguoiDung->KiemTraTaiKhoan() == "Tai Khoan VIP")
				NguoiDung = new TaiKhoanVip(NguoiDung->LayTaiKhoan(), NguoiDung->LayMatKhau(), NguoiDung->LaySoDuTaiKhoan());
			else
				NguoiDung = new TaiKhoanThuong(NguoiDung->LayTaiKhoan(), NguoiDung->LayMatKhau(), NguoiDung->LaySoDuTaiKhoan());
		}
		else if (choose == 2)
		{
			NguoiDung->TaoTaiKhoan();
			cout << "Ban Co Muon Tro Thanh VIP (49000/Thang) (Y/N): ";
			char temp = toupper(_getch());
			while (temp!= 'Y' && temp!= 'N')
				temp = toupper(_getch());
			if (temp == 'Y')
			{
				NguoiDung->SuaSoDuTaiKhoan(NguoiDung->LaySoDuTaiKhoan() - 49000);
				NguoiDung = new TaiKhoanVip(NguoiDung->LayTaiKhoan(), NguoiDung->LayMatKhau(), NguoiDung->LaySoDuTaiKhoan());
			}
			else
				NguoiDung = new TaiKhoanThuong(NguoiDung->LayTaiKhoan(), NguoiDung->LayMatKhau(), NguoiDung->LaySoDuTaiKhoan());
		}
		while (1)
		{
			cout << "\n1. Top 5 Bai Hat Co Luot Nghe Nhieu Nhat\n";
			cout << "2. Nghe Nhac\n";
			cout << "3. Tao PlayList\n";
			cout << "4. Xoa PlayList\n";
			cout << "5. Developer Mode\n";
			cout << "6. Thoat\n";
			cout << "Nhap Lua Chon: ";
			cin >> choose;
			if (choose == 1)
			{
				quicksort(DanhSachNhac, 0, DanhSachNhac.size() - 1);
				cout << endl;
				for (int i = 0; i < DanhSachNhac.size(); i++)
					cout << i + 1 << ". " << DanhSachNhac[i]->LayTenBaiHat() << endl;
				cout << "Ban Co Muon Xuat Thong Tin Bai Hat Khong (Y/N): ";
				char temp = toupper(_getch());
				if (temp == 'Y')
				{
					while (1)
					{
						cout << "\nNhap Vi Tri Bai Hat Muon Xuat (0 : Stop) : ";
						cin >> choose;
						if (choose <= 0)
							break;
						DanhSachNhac[choose - 1]->XuatThongTin();
					}
				}
			}
			else if (choose == 2)
			{
				cout << "\n1. Nghe Tu Thu Danh Sach\n2. Nghe Tu PlayList Ca Nhan:\n";
				cout << "Hay Chon: ";
				cin >> choose;
				if (choose == 1)
				{
					for (int i = 0; i < DanhSachNhac.size(); i++)
						cout << i + 1 << ". " << DanhSachNhac[i]->LayTenBaiHat() << endl;
					cout << "\nNhap Vi Tri Bai Hat Muon Nghe: ";
					cin >> choose;
					while (choose < 1 && choose >= DanhSachNhac.size())
					{
						cout << "\nNhap Lai Vi Tri Bai Hat Muon Nghe: ";
						cin >> choose;
					}
					bool KiemTraBanQuyen;
					DanhSachNhac[choose - 1]->BanQuyen(KiemTraBanQuyen);
					if (KiemTraBanQuyen)
					{
						bool checkVIP;
						NguoiDung->IsNormal(checkVIP);
						if (checkVIP)
						{
							NguoiDung->SuaSoDuTaiKhoan((NguoiDung->LaySoDuTaiKhoan() - DanhSachNhac[choose - 1]->LayGiaTriBanQuyen() / 2));
							cout << "Ban Da Bi Tru: " << DanhSachNhac[choose - 1]->LayGiaTriBanQuyen() / 2 << endl;
						}
						else
						{
							NguoiDung->SuaSoDuTaiKhoan((NguoiDung->LaySoDuTaiKhoan() - DanhSachNhac[choose - 1]->LayGiaTriBanQuyen()));
							cout << "Ban Da Bi Tru: " << DanhSachNhac[choose - 1]->LayGiaTriBanQuyen() << endl;
						}
						DanhSachNhac[choose - 1]->PlayMusic();
					}
					else
						DanhSachNhac[choose - 1]->PlayMusic();
				}
				else if (choose == 2)
				{
					for (int i = 0; i < PlayList.size(); i++)
						cout << i + 1 << ". " << PlayList[i]->LayTenBaiHat() << endl;
					cout << "\nNhap Vi Tri Bai Hat Muon Nghe: ";
					cin >> choose;
					while (choose < 1 && choose >= PlayList.size())
					{
						cout << "\nNhap Lai Vi Tri Bai Hat Muon Nghe: ";
						cin >> choose;
					}
					bool KiemTraBanQuyen;
					PlayList[choose - 1]->BanQuyen(KiemTraBanQuyen);
					if (KiemTraBanQuyen)
					{
						bool checkNormal;
						NguoiDung->IsNormal(checkNormal);
						if (checkNormal)
						{
							NguoiDung->SuaSoDuTaiKhoan((NguoiDung->LaySoDuTaiKhoan() - PlayList[choose - 1]->LayGiaTriBanQuyen()));
							cout << "Ban Da Bi Tru: " << PlayList[choose - 1]->LayGiaTriBanQuyen() << endl;
						}
						else
						{
							NguoiDung->SuaSoDuTaiKhoan((NguoiDung->LaySoDuTaiKhoan() - PlayList[choose - 1]->LayGiaTriBanQuyen() / 2));
							cout << "Ban Da Bi Tru: " << PlayList[choose - 1]->LayGiaTriBanQuyen() / 2 << endl;
						}
						PlayList[choose - 1]->PlayMusic();
					}
					else
						PlayList[choose - 1]->PlayMusic();
				}
			}
			else if (choose == 3)
			{
				for (int i = 0; i < DanhSachNhac.size(); i++)
					cout << i + 1 << ". " << DanhSachNhac[i]->LayTenBaiHat() << endl;
				vector<int> pos;
				cout << "Nhap So Thu Tu Bai Hat Muon Them Vao PlayList (-1 : Stop): ";
				while (1)
				{
					int x;
					cin >> x;
					if (x == -1)
						break;
					pos.push_back(x);
				}
				for (int c : pos)
					PlayList.push_back(DanhSachNhac[c - 1]);
				for (int i = 0; i < PlayList.size(); i++)
					cout << i + 1 << ". " << PlayList[i]->LayTenBaiHat() << endl;
			}
			else if (choose == 4)
			{
				if (PlayList.size() > 0)
				{
					cout << endl;
					for (int i = 0; i < PlayList.size(); i++)
						cout << i + 1 << ". " << PlayList[i]->LayTenBaiHat() << endl;
					vector<int> pos;
					cout << "Nhap So Thu Tu Bai Hat Muon Xoa Khoi PlayList (-1 : Stop): ";
					while (1)
					{
						int x;
						cin >> x;
						if (x == -1)
							break;
						pos.push_back(x);
					}
					for (int c : pos)
						PlayList.erase(PlayList.begin() + c - 1);
					for (int i = 0; i < PlayList.size(); i++)
						cout << i + 1 << ". " << PlayList[i]->LayTenBaiHat() << endl;
				}
				else
					cout << "Khong Co Bai Hat Nao Trong PlayList\n";
			}
			else if (choose == 5)
			{
				cout << "\n1. Them Bai Hat\n2. Xuat Thong Tin Bai Hat\n";
				cout << "Nhap Lua Chon: ";
				cin >> choose;
				if (choose == 1)
				{
					cout << "1. Nhac Pho Thuong\n2.Nhac Ban Quyen\n";
					cout << "Nhap Lua Chon: ";
					cin >> choose;
					if (choose == 1)
					{
						NhacPhoThong* temp = new NhacPhoThong;
						temp->TaoBaiHat();
						DanhSachNhac.push_back(temp);
					}
					else if (choose == 2)
					{
						NhacBanQuyen* temp = new NhacBanQuyen;
						temp->TaoBaiHat();
						DanhSachNhac.push_back(temp);
					}
				}
				else if (choose == 2)
				{
					cout << endl;
					for (int i = 0; i < DanhSachNhac.size(); i++)
						cout << i + 1 << ". " << DanhSachNhac[i]->LayTenBaiHat() << endl;
					cout << "Ban Co Muon Xuat Thong Tin Bai Hat Khong (Y/N): ";
					char temp = toupper(_getch());
					if (temp == 'Y')
					{
						while (1)
						{
							cout << "Nhap Vi Tri Bai Hat Muon Xuat (0 : Stop) : ";
							cin >> choose;
							if (choose <= 0)
								break;
							DanhSachNhac[choose - 1]->XuatThongTin();
						}
					}
				}
			}
			else if (choose == 6)
				break;
			cout << endl;
		}
		cout << "Ban Co Muon Thoat Ung Dung Khong(Y/N);";
		char temp = toupper(_getch());
		if (temp == 'Y')
			break;
		else
			system("cls");
	}
}