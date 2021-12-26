#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sach
{
	string tensach;
	int soluong;
	bool tinhtrang;
public:
	Sach();
	Sach(string, int, bool);
	~Sach();
	friend istream& operator>> (istream& is, Sach& ps);
	friend ostream& operator<< (ostream& os, Sach& ps);
};