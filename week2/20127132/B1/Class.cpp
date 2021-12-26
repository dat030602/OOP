#include "MainHeader.h"
#include "Class.h"
#include "Student.h"

Class::Class(int& n)
{
	cout << "Nhap so luong hoc sinh: ";
	cin >> n;
}
void Class::set(int n)
{
	Student tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		lophoc.push_back(tmp);
	}
}
void Class::display(int n)
{
	for (int i = 0; i < n; i++)
		cout << lophoc[i];
}