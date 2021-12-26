#include "BaiHat.h"
#include "NhacBanQuyen.h"
#include "NhacPhoThong.h"
#include "TaiKhoan.h"
#include "TaiKhoanThuong.h"
#include "TaiKhoanVip.h"

void InitMusic(vector<BaiHat*>& DanhsachNhac)
{
	fstream fi;
	fi.open("data.txt");
	while (!fi.eof())
	{
		string TenBaiHat;
		vector<string> LoiBaiHat;
		string TenCaSi;
		string TheLoaiNhac;
		unsigned int NamSangTac;
		unsigned int LuotNghe;
		string nhacBanQuyen;
		unsigned int GiaTriBanQuyen;
		string temp;
		int size;
		getline(fi, nhacBanQuyen, '\n');
		getline(fi, TenBaiHat, '\n');
		getline(fi, TenCaSi, '\n');
		getline(fi, TheLoaiNhac, '\n');
		fi >> NamSangTac >> LuotNghe >> size;
		if (nhacBanQuyen == "Nhac Ban Quyen")
			fi >> GiaTriBanQuyen;
		getline(fi, temp, '\n');
		for (int i = 0; i < size; i++)
		{
			getline(fi, temp, '\n');
			LoiBaiHat.push_back(temp);
		}
		if (nhacBanQuyen == "Nhac Ban Quyen")
			DanhsachNhac.push_back(new NhacBanQuyen(TenBaiHat, LoiBaiHat, TenCaSi, TheLoaiNhac, NamSangTac, LuotNghe, GiaTriBanQuyen));
		else
			DanhsachNhac.push_back(new NhacPhoThong(TenBaiHat, LoiBaiHat, TenCaSi, TheLoaiNhac, NamSangTac, LuotNghe, 0));
	}
}

int partition(vector<BaiHat*>& DanhSachNhac, int l, int r)
{
	int i = l - 1, j = r;
	unsigned int v = DanhSachNhac[r]->LayLuotNghe();
	for (;;)
	{
		while (DanhSachNhac[++i]->LayLuotNghe() < v)
			;
		while (v < DanhSachNhac[--j]->LayLuotNghe())
			if (j == l)
				break;
		if (i >= j)
			break;
		swap(DanhSachNhac[i], DanhSachNhac[j]);
	}
	swap(DanhSachNhac[i], DanhSachNhac[r]);
	return i;
}
void quicksort(vector<BaiHat*>& DanhSachNhac, int l, int r)
{
	if (r <= l)
		return;
	int i = partition(DanhSachNhac, l, r);
	quicksort(DanhSachNhac, l, i - 1);
	quicksort(DanhSachNhac, i + 1, r);
}