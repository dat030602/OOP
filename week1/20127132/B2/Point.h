#pragma once
#include <iostream>
#include <math.h>
using namespace std;
class Point
{
public:
	double x, y;
public:
	void input();
	void output();
	double module(Point a);
};