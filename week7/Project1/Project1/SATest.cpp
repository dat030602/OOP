#include "SATest.h"
#include "SortArray.h"
#include <algorithm>

istream& operator>>(istream& is, vector<float>& a)
{
	int n;
	float x;
	cout << "Nhap So Luong Phan Tu: ";
	cin >> n;
	cout << "Nhap Mang: ";
	for (int i = 0; i < n; i++)
	{
		is >> x;
		a.push_back(x);
	}
	return is;
}

ostream& operator<<(ostream& os, vector<float>& a)
{
	for (int i = 0; i < a.size(); i++)
		os << a[i] << " ";
	return os;
}

bool SATest::Check()
{
	return Data.size() > 0;
}

void SATest::Output(ostream& os)
{
	os << "Result after sorting: ";
	os << Data;
}

void SATest::startMessage(ostream& os)
{
	os << "Enter n, then a[0], ..., a[n - 1]:\n";
}

void SATest::Process() {
	if (mAlg != NULL)
		mAlg->Process(Data);
}

void SATest::Input(istream& is)
{
	is >> Data;
}