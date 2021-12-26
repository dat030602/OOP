#include "Array.h"
#include "HocSinh.h"

int main()
{
    cout << "ARRAY\n\n";
    int w[100];
    int size;
    cout << "Nhap So Luong Phan Tu Mang Muon Tao: ";
    cin >> size;
    cout << "Nhap Mang Muon Tao:\n";
    for (int i = 0; i < size; i++)
    {
        cout << "a[" << i << "] = ";
        cin >> w[i];
    }
    Array a;
    Array b(size);
    Array c(size, w);
    Array d(c);
    Array e;
    e = c;
    cout << "Array A (khoi tao mac dinh): " << a;
    cout << "Array B (khoi tao co size): " << b;
    cout << "Array C (khoi tao co mang va size): " << c;
    cout << "Array D (khoi tao sao chep): " << d;
    cout << "Array E (gan): " << d;
    cout << "Operator[]:  c[1] = " << c[1] << endl;
    int* test = static_cast<int*>(c);
    cout << "Ep kieu:\n";
    for (int i = 0; i < c.getSize(); ++i)
        cout << "a[" << i << "] = " << c[i] << endl;

    cout << "\n\nHOC SINH\n\n";
    HocSinh a1;
    HocSinh b1;
    cout << "Nhap Hoc Sinh B: \n";
    cin >> b1;
    cout << "Nhap Hoc Sinh C: \n";
    HocSinh c1;
    cin >> c1;
    HocSinh d1(b1);
    cout << "\nSao chep Hoc Sinh B\n" << d1;
    HocSinh e1;
    e1 = c1;
    cout << "\nGan Hoc Sinh C\n" << e1;
    cout << "\nEp Kieu: ";
    char* test1 = static_cast<char*>(e1);
    int i = 0;
    while (test1[i] != '\0')
        cout << test1[i++];
    cout << endl;
}