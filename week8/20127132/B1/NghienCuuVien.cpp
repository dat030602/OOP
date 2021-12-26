#include "NghienCuuVien.h"

NghienCuuVien::~NghienCuuVien()
{
	SoNamNghienCuu = -1;
};
double NghienCuuVien::TinhLuong()
{
	int len = 0;
	vector<string> temp = TruongDaiHoc::DanhSach();
	for (int i = 0; i < length(); i++)
		if (temp[i][0] == 'D')
			len++;
	return (SoNamNghienCuu * 2 + len) * 20000;
}

void NghienCuuVien::Nhap()
{
	TruongDaiHoc::Nhap();
	cout << "Nhap So Nam Kinh Nghiem Lam Viec: ";
	cin >> SoNamNghienCuu;
	int size;
	cout << "Nhap So Du An Giao Duc: ";
	cin >> size;
	cout << "Nhap Du An Giao Duc:\n";
	TruongDaiHoc::NhapDanhSach(size);
}
void NghienCuuVien::Xuat()
{
	TruongDaiHoc::Xuat();
	cout << "So Nam Kinh Nghiem Lam Viec: " << SoNamNghienCuu << endl;
	cout << "Danh Sach Du An Giao Duc: " << endl;
	TruongDaiHoc::XuatDanhSach();
}