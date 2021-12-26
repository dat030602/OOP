#include <iostream>
#include <string>
using namespace std;
typedef struct complex
{
    float real;
    float imag;
} complexNumber;
complexNumber addComplexNumber(complex num1, complex num2)
{
    complex temp;
    temp.real = num1.real + num2.real;
    temp.imag = num1.imag + num2.imag;
    return temp;
}
complexNumber subComplexNumber(complex num1, complex num2)
{
    complex temp;
    temp.real = num1.real - num2.real;
    temp.imag = num1.imag - num2.imag;
    return temp;
}
complexNumber mulComplexNumber(complex num1, complex num2)
{
    complex temp;
    temp.real = num1.real * num2.real - num1.imag * num2.imag;
    temp.imag = num1.real * num2.imag + num1.imag * num2.real;
    return temp;
}
complexNumber divComplexNumber(complex num1, complex num2)
{
    complex temp;
    temp.real = (num1.real * num2.real + num1.imag * num2.imag) /
                (num2.real * num2.real + num2.imag * num2.imag);
    temp.imag = (num2.real * num1.imag - num2.imag * num1.real) /
                (num2.real * num2.real + num2.imag * num2.imag);
    return temp;
}

float moduleComplex(complex num)
{
    float i, pre = 0.00001;
    float n = num.real * num.real + num.imag * num.imag;

    //sqrt
    for (i = 1; i * i <= n; i++);
    for (--i; i * i < n; i += pre);

    return i;
}
void output(complex num, string operatorKey)
{
    cout << operatorKey << " Complex Number: " << num.real << " + " << num.imag << "i" << endl;
}
int main()
{
    complexNumber num1, num2;
    char signOfImag;
    cout << "First Complex Number" << endl;
    cout << "Enter real parts: ";
    cin >> num1.real;
    cout << "Enter imaginary parts: ";
    cin >> num1.imag;
    cout << "Second Complex Number" << endl;
    cout << "Enter real parts: ";
    cin >> num2.real;
    cout << "Enter imaginary parts: ";
    cin >> num2.imag;

    complexNumber sum = addComplexNumber(num1, num2);
    complexNumber sub = subComplexNumber(num1, num2);
    complexNumber mul = mulComplexNumber(num1, num2);
    complexNumber div = divComplexNumber(num1, num2);
    output(sum, "Addition Two");
    output(sub, "Subtraction Two");
    output(mul, "Multiplication Two");
    output(div, "Division Two");
    cout << "Module of first Complex Number: " << moduleComplex(num1) << endl;
    cout << "Module of second Complex Number: " << moduleComplex(num2) << endl;
}