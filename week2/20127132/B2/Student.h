#pragma once

#include "MainHeader.h"

class Student
{
	string name;
	string phoneNumber;
	float mean;
	friend istream& operator>>(istream& inDev, Student& ms);
	friend ostream& operator<<(ostream& outDev, const Student& ms);
public:
	void set(string, string, float);
	string Name() { return name; }
	float Mean() { return mean; }
};
bool checkName(string s);
bool checkPhone(string s);
int checkExist(string s, vector<Student> a, int n);
void quicksort(vector<Student>& a, int l, int r);