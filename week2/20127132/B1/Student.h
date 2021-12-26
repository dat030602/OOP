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
	Student();
	virtual ~Student() {};
};