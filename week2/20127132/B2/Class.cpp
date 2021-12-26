#include "MainHeader.h"
#include "Class.h"
#include "Student.h"

Class::Class(int& n)
{
	Student tmp;
	fstream fi;
	string m, q;
	float k;
	fi.open("LopHoc.txt");
	fi >> n;
	getline(fi, m);
	for (int i = 0; i < n; i++)
	{
		getline(fi, m, '\n');
		getline(fi, q, '\n');
		fi >> k;
		tmp.set(m, q, k);
		lophoc.push_back(tmp);
		getline(fi, m, '\n');
	}
	fi.close();
}
void Class::add(int& n)
{
	Student tmp;
	cin >> tmp;
	if (checkExist(tmp.Name(), lophoc, n) != -1)
		cout << "Da co hoc sinh trong lop\n";
	else
	{
		lophoc.push_back(tmp);
		n++;
		cout << "Da them hoc sinh " << tmp.Name() << " vao trong lop\n";
	}
}
void Class::deleteStudent(int& n)
{
	string s;
	cout << "Nhap ten hoc sinh muon xoa: ";
	cin.ignore();
	getline(cin, s);
	int pos = checkExist(s, lophoc, n);
	if (pos != -1)
	{
		lophoc.erase(lophoc.begin() + pos);
		n--;
		cout << "Da xoa hoc sinh " << s << " ra khoi lop\n";
	}
	else
		cout << "Khong co hoc sinh trong lop";
}
void Class::sortMean(int& n)
{
	cout << endl;
	quicksort(lophoc, 0, n - 1);
}
void Class::display(int& n)
{
	for (int i = 0; i < n; i++)
		cout << i + 1 << "." << lophoc[i];
}