#include "MangSoNguyen.h"

int main()
{
	int arr[] = { 1, 2, 3, 4, 5 };
	int arr1[] = { 7, 9, 12, 66 };
	int size = 5;
	MangSoNguyen b(size, arr);
	MangSoNguyen a;
	cin >> a;
	cout << "Mang A sau khi nhap: ";
	cout << a;
	cout << "Mang A sau khi ++ tien to: ";
	cout << ++a;
	cout << "Mang A sau khi ++ hau to: ";
	a--;
	cout << a++;
	cout << "Mang A sau khi -- tien to: ";
	a--;
	cout << --a;
	cout << "Mang A sau khi -- hau to: ";
	a++;
	cout << a--;
	cout << "Mang A sau khi + Mang B: ";
	cout << a + b;
	cout << "Mang A sau khi gan Mang B: ";
	a = arr1;
	cout << a;
	return 0;
}