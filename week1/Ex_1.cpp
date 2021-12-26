#include <iostream>
using namespace std;
typedef struct fraction
{
    int numerator;
    int denominator;
} fractionNumber;
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
fractionNumber reducdeFraction(fraction num)
{
    int gcd1 = gcd(num.numerator, num.denominator);
    num.numerator /= gcd1;
    num.denominator /= gcd1;
    return num;
}
fractionNumber addFractionNumber(fraction num1, fraction num2)
{
    fraction temp;
    if (num1.denominator == num2.denominator)
    {
        temp.numerator = num1.numerator + num2.numerator;
        temp.denominator = num1.denominator;
    }
    else
    {
        temp.numerator = num1.numerator * num2.denominator + num2.numerator * num1.denominator;
        temp.denominator = num1.denominator * num2.denominator;
    }

    int gcd1 = gcd(temp.numerator, temp.denominator);
    temp.numerator /= gcd1;
    temp.denominator /= gcd1;

    return reducdeFraction(temp);
}
fractionNumber subFractionNumber(fraction num1, fraction num2)
{
    fraction temp;
    if (num1.denominator == num2.denominator)
    {
        temp.numerator = num1.numerator - num2.numerator;
        temp.denominator = num1.denominator;
    }
    else
    {
        temp.numerator = num1.numerator * num2.denominator - num2.numerator * num1.denominator;
        temp.denominator = num1.denominator * num2.denominator;
    }

    return reducdeFraction(temp);
}
fractionNumber mulFractionNumber(fraction num1, fraction num2)
{
    fraction temp;
    temp.numerator = num1.numerator * num2.numerator;
    temp.denominator = num1.denominator * num2.denominator;

    return reducdeFraction(temp);
}
fractionNumber divFractionNumber(fraction num1, fraction num2)
{
    fraction temp;
    temp.numerator = num1.numerator * num2.denominator;
    temp.denominator = num2.numerator * num1.denominator;

    return reducdeFraction(temp);
}
void output(fraction num, string operatorKey)
{
    cout << operatorKey << " Fraction Number: " << num.numerator << " / " << num.denominator << endl;
}
int main()
{
    fractionNumber num1, num2;
    char signOfImag;
    cout << "First Fraction Number" << endl;
    cout << "Enter Numerator parts: ";
    cin >> num1.numerator;
    cout << "Enter Denominator parts: ";
    cin >> num1.denominator;
    cout << "Second Fraction Number" << endl;
    cout << "Enter Numerator parts: ";
    cin >> num2.numerator;
    cout << "Enter Denominator parts: ";
    cin >> num2.denominator;

    fractionNumber sum = addFractionNumber(num1, num2);
    fractionNumber sub = subFractionNumber(num1, num2);
    fractionNumber mul = mulFractionNumber(num1, num2);
    fractionNumber div = divFractionNumber(num1, num2);
    output(sum, "Addition Two");
    output(sub, "Subtraction Two");
    output(mul, "Multiplication Two");
    output(div, "Division Two");
}