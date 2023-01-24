#include <iostream>
#include <math.h>
#include <complex>
#include "Complex.h"

// Constructors and Destructor
//constructor accepting two doubles
Complex::Complex(double a, double b)
{
    real = a;
    imag = b;
}
//constructor accepting a complex object
Complex::Complex(const Complex &obj)
{
    real = obj.real;
    imag = obj.imag;
}
//deconstructor
Complex::~Complex()
{
    real = 0;
    imag = 0;
}

// Acessors and Mutators
//set the real value
void Complex::setReal(double re)
{
    real = re;
}
//access the real value
double Complex::getReal()
{
    return real;
}
//set the imag value
void Complex::setImag(double im)
{
    imag = im;
}
//access the imag value
double Complex::getImag()
{
    return imag;
}
//set the real and imag value
void Complex::set(double re, double im)
{
    real = re;
    imag = im;
}

// Overloaded operator functions
//overload the + function accepting a complex number
Complex Complex::operator + (const Complex &num)
{
    Complex c;
    c.real = real + num.real;
    c.imag = imag + num.imag;
    return c;
}
//overload the + function accepting a double
Complex Complex::operator + (double num)
{
    Complex c;
    c.real = real + num;
    c.imag = imag;
    return c;
}
//overload the + function accepting a double and another complex number
Complex operator + (double num1, const Complex &num2)
{
    Complex c;
    c.real = num1 + num2.real;
    c.imag = num2.imag;
    return c;
}

//overload the - function accepting a complex number
Complex Complex::operator - (const Complex &num)
{
    Complex c;
    c.real = real - num.real;
    c.imag = imag - num.imag;
    return c;
}
//overload the - function accepting a double
Complex Complex::operator - (double num)
{
    Complex c;
    c.real = real - num;
    c.imag = imag;
    return c;
}
//overload the - function accepting a double and another complex number
Complex operator - (double num1, const Complex &num2)
{
    Complex c;
    c.real = num1 - num2.real;
    c.imag = num2.imag;
    return c;
}

//overload the * function accepting a complex number
Complex Complex::operator * (const Complex &num)
{
    Complex c;
    c.real = (real * num.real) - (imag * num.imag);
    c.imag = (real * num.imag) + (num.real * imag);
    return c;
}
//overload the * function accepting a double
Complex Complex::operator * (double num)
{
    Complex c;
    c.real = real * num;
    c.imag = imag * num;
    return c;
}
//overload the - function accepting a double and another complex number
Complex operator * (double num1, const Complex &num2)
{
    Complex c;
    c.real = num1 * num2.real;
    c.imag = num1 * num2.imag;
    return c;
}

//overload the / function accepting a complex number
Complex Complex::operator / (const Complex &num)
{
    double denom = 0;
    denom = (num.real * num.real) + (num.imag * num.imag);
    Complex c;
    c.real = ((real * num.real) + (imag * num.imag)) / denom;
    c.imag = ((real * num.imag * -1) + (imag * num.real)) / denom;
    return c;
}
//overload the / function accepting a double
Complex Complex::operator / (double num)
{
    Complex c;
    c.real = real / num;
    c.imag = imag / num;
    return c;
}
//overload the / function accepting a double and another complex number
Complex operator / (double num1, const Complex &num2)
{
    double denom = 0;
    denom = (num2.real * num2.real) + (num2.imag * num2.imag);
    Complex c;
    c.real = num1 * num2.real / denom;
    c.imag = num1 * (num2.imag * -1) / denom;
    return c;
}

//add the real and imag of another complex number to the current
void Complex::operator += (const Complex &num)
{
    real = real + num.real;
    imag = imag + num.imag;
}
//subtract the real and imag of another complex number to the current
void Complex::operator -= (const Complex &num)
{
    real = real - num.real;
    imag = imag - num.imag;
}
//multiply the current complex number by itself num amount of times
Complex Complex::operator ^ (int num)
{
    std::complex<double> complexNumber(real, imag);
    complexNumber = pow(complexNumber, num);
    Complex com;
    com.real = std::real(complexNumber);
    com.imag = std::imag(complexNumber);
    return com;
}

//returns true if the two complex numbers are the same
bool Complex::operator == (const Complex &num)
{
    if (real == num.real && imag == num.imag) {return true;}
    else {return false;}
}
//returns false if the two complex numbers are the same
bool Complex::operator != (const Complex &num)
{
    if (real == num.real && imag == num.imag) {return false;}
    else {return true;}
}

//sets the current complex number to equal the inputted complex number
const Complex Complex::operator=(const Complex &right)
{
    Complex c;
    c.real = right.real;
    c.imag = right.imag;
    real = right.real;
    imag = right.imag;
    return c;
}

// Functions
//returns the modulus of the complex number
double Complex::mod()
{
    double num = pow(real, 2) + pow(imag, 2);
    num = sqrt(num);
    return num;
}

// Friend functions for streaming.
ostream &operator << (ostream &out, const Complex &c)
{
    if (c.real != 0) {out << c.real;}
    if (c.real == 0 && c.imag == 0) {out << "0";}
    out << " ";
    if (c.imag > 0) {out << "+ " << c.imag << "i";}
    if (c.imag < 0) {out << c.imag << "i";}
    return out;
}
istream &operator >> (istream &in, Complex &c)
{
    in >> c.real >> c.imag;
    return in;
}