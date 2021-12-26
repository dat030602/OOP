#include "ThuVien.h"

ThuVien::~ThuVien()
{
	m_thuvien.clear();
}
istream& operator>> (istream& is, ThuVien& ps)
{
	int size;
	cout << "Nhap so luong sach muon nhap: ";
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		Sach sach;
		is >> sach;
		ps.m_thuvien.push_back(sach);
	}
	return is;
}
ostream& operator<< (ostream& os, ThuVien& ps)
{
	int size = ps.m_thuvien.size();
	for (int i = 0; i < size; i++)
		os << ps.m_thuvien[i] << endl;
	return os;
}
