#pragma once
#include <iostream>
#include <math.h>

using namespace std;

class HCN
{
public:
	int x, y;
public:
	void input();
	void output();
	bool checkHCN(HCN, HCN, HCN);
	int module1(HCN, HCN);
	int Perimeter(HCN, HCN, HCN);
	int Area(HCN, HCN, HCN);
};