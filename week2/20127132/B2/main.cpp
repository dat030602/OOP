#include "MainHeader.h"
#include "Student.h"
#include "Class.h"

int main()
{
	int n;
	Class LopHoc(n);
	int choice;
	while (1)
	{
		cout << "\nHay chon:";
		cout << "\n1. Them 1 hoc sinh";
		cout << "\n2. Xoa 1 hoc sinh";
		cout << "\n3. Sap xep diem trung binh giam dan";
		cout << "\n4. In ra thong tin hoc sinh cua lop";
		cout << "\n5. Thoat";
		cout << "\nNhap lua chon: ";
		cin >> choice;
		if (choice == 1)
			LopHoc.add(n);
		else if (choice == 2)
			LopHoc.deleteStudent(n);
		else if (choice == 3)
			LopHoc.sortMean(n);
		else if (choice == 4)
			LopHoc.display(n);
		else if (choice == 5)
			return 0;
	}
}