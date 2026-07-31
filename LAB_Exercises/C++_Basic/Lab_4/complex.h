#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
private:
    double real, imaginary;

public:
    Complex();
    Complex(double, double);

    // ---------- Arithmetic (binary) ----------
    Complex operator+(Complex);
    Complex operator-(Complex);
    Complex operator*(Complex);
    Complex operator/(Complex);

    // ---------- Comparison ----------
    bool operator==(Complex);
    bool operator!=(Complex);
    bool operator<(Complex); // compares magnitude
    bool operator>(Complex);
    bool operator<=(Complex);
    bool operator>=(Complex);

    void Print();
};

#endif // COMPLEX_H