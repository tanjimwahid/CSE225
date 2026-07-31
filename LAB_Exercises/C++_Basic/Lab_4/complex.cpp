#include "complex.h"
#include <iostream>
#include <cmath>
using namespace std;

Complex::Complex()
{
    real = 0;
    imaginary = 0;
}

Complex::Complex(double r, double i)
{
    real = r;
    imaginary = i;
}

// ---------- Arithmetic ----------

Complex Complex::operator+(Complex a)
{
    Complex t;
    t.real = real + a.real;
    t.imaginary = imaginary + a.imaginary;
    return t;
}

Complex Complex::operator-(Complex a)
{
    Complex t;
    t.real = real - a.real;
    t.imaginary = imaginary - a.imaginary;
    return t;
}

// (a+bi)(c+di) = (ac - bd) + (ad + bc)i
Complex Complex::operator*(Complex a)
{
    Complex t;
    t.real = real * a.real - imaginary * a.imaginary;
    t.imaginary = real * a.imaginary + imaginary * a.real;
    return t;
}

// (a+bi)/(c+di) = [(ac+bd) + (bc-ad)i] / (c*c + d*d)
Complex Complex::operator/(Complex a)
{
    Complex t;
    double d = a.real * a.real + a.imaginary * a.imaginary;

    if (d == 0)
    {
        cout << "Error: division by zero." << endl;
        return t;
    }

    t.real = (real * a.real + imaginary * a.imaginary) / d;
    t.imaginary = (imaginary * a.real - real * a.imaginary) / d;
    return t;
}

// ---------- Comparison ----------

bool Complex::operator==(Complex a)
{
    return (real == a.real && imaginary == a.imaginary);
}

bool Complex::operator!=(Complex a)
{
    return (real != a.real || imaginary != a.imaginary);
}

bool Complex::operator<(Complex a)
{
    double m1 = sqrt(real * real + imaginary * imaginary);
    double m2 = sqrt(a.real * a.real + a.imaginary * a.imaginary);
    return (m1 < m2);
}

bool Complex::operator>(Complex a)
{
    double m1 = sqrt(real * real + imaginary * imaginary);
    double m2 = sqrt(a.real * a.real + a.imaginary * a.imaginary);
    return (m1 > m2);
}

bool Complex::operator<=(Complex a)
{
    double m1 = sqrt(real * real + imaginary * imaginary);
    double m2 = sqrt(a.real * a.real + a.imaginary * a.imaginary);
    return (m1 <= m2);
}

bool Complex::operator>=(Complex a)
{
    double m1 = sqrt(real * real + imaginary * imaginary);
    double m2 = sqrt(a.real * a.real + a.imaginary * a.imaginary);
    return (m1 >= m2);
}

void Complex::Print()
{
    cout << "Real: " << real << ", Imaginary: " << imaginary << endl;
}