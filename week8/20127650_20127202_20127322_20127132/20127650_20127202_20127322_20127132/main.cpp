#include "SortAlgorithm.h"
#include "Student.h"

int main()
{
    float a[] = { 1.4F, -5.2F, 3.3F, 0 };
    int n = sizeof(a) / sizeof(a[0]);
    SortAlgorithm<float>* alg = SortAlgorithm<float>::getObject(SortAlgorithm<float>::SelectionSort);
    alg->Sort(a, n);
    cout << "Mang sau khi sap tang tang dan: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << "  ";
    cout << endl;

    char b[] = { 'B', 'A', 'D', 'C' };
    n = sizeof(b) / sizeof(b[0]);
    SortAlgorithm<char>* algg = SortAlgorithm<char>::getObject(SortAlgorithm<char>::InterchangeSort);
    algg->Sort(b, n);
    cout << "Mang sau khi sap tang tang dan: ";
    for (int i = 0; i < n; i++)
        cout << b[i] << "  ";
    cout << endl;

    Student c[] = { Student("abc", 9.5), Student("def", 8.5), Student("ab", 1.0) };
    n = sizeof(c) / sizeof(c[0]);
    SortAlgorithm<Student>* alggg = SortAlgorithm<Student>::getObject(SortAlgorithm<Student>::InsertionSort);
    alggg->Sort(c, n);
    cout << "Mang sau khi sap tang tang dan:\n";
    for (int i = 0; i < n; i++)
        cout << c[i];
    cout << endl;
    return 0;
}