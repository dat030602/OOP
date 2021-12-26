#pragma once
#include "MainHeader.h"
#include "Student.h"

class Class
{
	vector<Student> lophoc;
public:
	Class(int& n);
	void set(int n);
	void display(int n);
};