#include "PhanSo.h"

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}
void PhanSo::input()
{
	cout << "Nhap tu so: ";
	cin >> tu;
	cout << "Nhap mau so: ";
	cin >> mau;
	while (!mau)
	{
		cout << "Nhap lai mau so: ";
		cin >> mau;
	}
}
void PhanSo::output()
{
	if (tu == 0)
		cout << 0 << endl;
	else if (mau == 1)
		cout << tu << endl;
	else
		cout << tu << " / " << mau << endl;
}
void PhanSo::reduce()
{
	int GCD1 = gcd(tu, mau);
	tu /= GCD1;
	mau /= GCD1;
}
void PhanSo::cong(PhanSo a)
{
	if (a.mau == mau)
		tu += a.tu;
	else
	{
		tu = tu * a.mau + a.tu * mau;
		mau *= a.mau;
	}
	reduce();
}
void PhanSo::tru(PhanSo a)
{
	if (a.mau == mau)
		tu -= a.tu;
	else
	{
		tu = tu * a.mau - a.tu * mau;
		mau *= a.mau;
	}
	reduce();
}
void PhanSo::nhan(PhanSo a)
{
	tu = tu * a.tu;
	mau *= a.mau;
	reduce();
}
void PhanSo::chia(PhanSo a)
{
	tu *= a.mau;
	mau *= a.tu;
	reduce();
}