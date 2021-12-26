#include "Array.h"

Array::Array()
{
	size = 1;
	arr[0] = 0;
}
Array::Array(int s)
{
	size = s;
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}


Array::Array(const Array& b)
{
	size = b.size;
	for (int i = 0; i < size; i++)
		arr[i] = b.arr[i];
}

Array::Array(int size, int b[])
{
	this->size = size;
	for (int i = 0; i < size; i++)
		this->arr[i] = b[i];
}

Array::~Array()
{
	for (int i = 0; i < size; i++)
		arr[i] = 0;
	size = 0;
}

istream& operator>>(istream& is, Array& arr)
{
	while (true) {
		cout << "Nhap Kich Thuoc Cua Mang So Nguyen: ";
		is >> arr.size;
		if (arr.size > 0)
			break;
		else
			cout << "Sai! Kich thuoc cua mang phai lon hon 0." << endl;
	}
	cout << "Nhap Cac Phan Tu Cua Mang: " << endl;
	for (int i = 0; i < arr.size; i++) {
		cout << "+ arr[" << i << "]= ";
		is >> arr.arr[i];
	}
	return is;
}

ostream& operator<<(ostream& os, Array& arr)
{
	os << "Kich Thuoc Cua Mang So Nguyen La: " << arr.size << endl;
	os << "Cac Phan Tu Cua Mang La: ";
	for (int i = 0; i < arr.size; i++)
		os << arr.arr[i] << " ";
	cout << endl;
	return os;
}

Array& Array::operator=(const Array& ps)
{
	for (int i = 0; i < ps.size; i++)
		this->arr[i] = ps.arr[i];
	if (size > ps.size)
		for (int i = ps.size; i < this->size; i++)
			this->arr[i] = 0;
	this->size = ps.size;
	return *this;
}
int Array::operator[](int i)
{
	return arr[i];
}
Array::operator int* () const
{
	int* result = new int[size];
	for (int i = 0; i < size; ++i)
		result[i] = arr[i];
	return result;
}
