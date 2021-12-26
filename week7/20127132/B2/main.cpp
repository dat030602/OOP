#include "HinhChuNhat.h"
#include "HinhVuong.h"
#include "ThuVien.h"
#include "Sach.h"

int main()
{
	HinhChuNhat a(10, 20);
	cout << "Chu vi Hinh Chu Nhat: " << a.chuvi() << endl;
	HinhVuong b(10);
	cout << "Chu vi Hinh Vuong: " << b.dientich() << endl;
	ThuVien c;
	cin >> c;
	cout << c;
}