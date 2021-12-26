#pragma once
#include "Sach.h"

class ThuVien
{
	vector<Sach> m_thuvien;
public:
	ThuVien() {};
	~ThuVien();
	friend istream& operator>> (istream& is, ThuVien& ps);
	friend ostream& operator<< (ostream& os, ThuVien& ps);
};