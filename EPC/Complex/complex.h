#include <ostream>

class Complex
{
public:
    Complex(double real, double imaginary = 0)
        : _real(real), _imaginary(imaginary)
    {}

    void operator+(Complex other) // Complex return, not const, changes this not temp
    {
        _real = _real + other._real;
        _imaginary = _imaginary + other._imaginary;
    }

    void operator << (std::ostream os) // return std::ostream&, std::ostream& param, friend, const Complex& param, implementation outside of class
    {
        os << "(" << _real << "." << _imaginary << ")";
    }

    Complex operator++() // return Complex&
    {
        ++_real;
        return *this;
    }


    Complex operator++(int)
    {
        Complex temp = *this; // copy asignment
        ++_real;
        return temp;
    }

private:
    double _real, _imaginary;
};