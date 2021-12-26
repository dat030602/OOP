#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

class MangSoNguyen
{
	int* dulieu;
	int kichthuoc;
public:
	MangSoNguyen();
	MangSoNguyen(int, int[]);
	MangSoNguyen(const MangSoNguyen&);
	~MangSoNguyen();
	friend istream& operator>> (istream&, MangSoNguyen&);
	friend ostream& operator<< (ostream&, MangSoNguyen&);
	MangSoNguyen& operator++(int);
	MangSoNguyen& operator++();
	MangSoNguyen& operator--(int);
	MangSoNguyen& operator--();
	friend istream& operator>> (istream& is, MangSoNguyen& ps);
	friend ostream& operator<< (ostream& os, MangSoNguyen& ps);
	MangSoNguyen& operator=(int[]);
	MangSoNguyen& operator+(const MangSoNguyen& ps);
};