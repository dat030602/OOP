#pragma once
#include <iostream>

using namespace std;
#include <iostream>
using namespace std;

class Array
{
private:
	//int* arr;
	int arr[100];
	int size;
public:
	Array();
	Array(const Array&);
	Array(int);
	Array(int, int[]);
	~Array();
	Array& operator=(const Array&);
	int operator[](int i);
	int getSize() { return size; }
	friend istream& operator>>(istream&, Array&);
	friend ostream& operator<<(ostream&, Array&);
	operator int* () const;
};