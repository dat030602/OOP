#include "ChuyenVien.h"

ChuyenVien::~ChuyenVien()
{
	SoNamLamViec = -1;
};
double ChuyenVien::TinhLuong()
{
	int len = 0;
	vector<string> temp = TruongDaiHoc::DanhSach();
	for (int i = 0; i < length(); i++)
		if (temp[i][0] == 'T')
			len++;
	return (SoNamLamViec * 4 + len) * 18000;
}

void ChuyenVien::Nhap()
{
	TruongDaiHoc::Nhap();
	cout << "Nhap So Nam Kinh Nghiem Lam Viec: ";
	cin >> SoNamLamViec;
	int size;
	cout << "Nhap So Du An Giao Duc: ";
	cin >> size;
	cout << "Nhap Du An Giao Duc:\n";
	TruongDaiHoc::NhapDanhSach(size);
}
void ChuyenVien::Xuat()
{
	TruongDaiHoc::Xuat();
	cout << "So Nam Kinh Nghiem Lam Viec: " << SoNamLamViec << endl;
	cout << "Danh Sach Du An Giao Duc: " << endl;
	TruongDaiHoc::XuatDanhSach();
}