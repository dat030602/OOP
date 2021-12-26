#pragma once
#include <iostream>
#include <String>

using namespace std;

class HocSinh
{
	int GPA;
	string name;
public:
	HocSinh();
	HocSinh(const HocSinh&);
	~HocSinh();
	HocSinh& operator=(const HocSinh&);
	bool operator==(const HocSinh&);
	bool operator>(const HocSinh&);
	bool operator>=(const HocSinh&);
	bool operator<(const HocSinh&);
	bool operator<=(const HocSinh&);
	bool operator!=(const HocSinh&);
	operator char* () const;
	friend istream& operator>>(istream&, HocSinh&);
	friend ostream& operator<<(ostream&, HocSinh&);
};