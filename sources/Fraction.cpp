#include "Fraction.hpp"
#include <math.h>

using namespace std;

namespace ariel
{
    int Fraction::gcd(int a, int b)     // gcd 
    {
        if(b ==0) return a;
        return gcd(b, a% b);
    }

    void Fraction::reduce()             // reduces the fraction the most possible
    {
        if(_denominator == 0) throw invalid_argument("Invalid: division by zero"); // denom cant be 0
        if(_numerator == 0) _denominator = 1;   // default setting if num is 0 0/1 is the most reduced form
        else    // num != 0
        {
            int gcdd = gcd(abs(_numerator), abs(_denominator));
            _numerator /= gcdd;
            _denominator /= gcdd;
        }

        if(_denominator < 0)    // if fraction is negative mention that
        {
            _numerator = -_numerator;
            _denominator = -_denominator;
        }
    }

    // constructor
    Fraction::Fraction(int num, int den): _numerator(num), _denominator(den)
    {
        if (den == 0) throw invalid_argument("Denom cant be zero");
        reduce();
    }

    // constructor of num float, supposed to be 3 numbers after dot
    Fraction::Fraction(float num)
    {
        int n = (int)num; // int
        int nume = round((num - n) * 1000); // 3 decimal
        int deno = 1000;
        if( nume == 0)
        {
            _numerator = n;
            _denominator = 1;
        } else
        {
            int gcdd = Fraction::gcd(nume, deno);
            _numerator = (n * deno + nume) / gcdd;
            _denominator = deno / gcdd;
        }
        reduce();
    }
    // constructor
    Fraction::Fraction(): _numerator(0), _denominator(1) { }


    // ALL operator+ functions
    // fraction + fraction
    const Fraction Fraction::operator+(const Fraction& other) const
    {   
        // (a/b)+(c/d) => a*d + b*c
        int num = _numerator * other._denominator + other._numerator * _denominator;
        int den = _denominator * other._denominator; // b*d
        return Fraction(num, den);
    }

    // fraction + float
    const Fraction Fraction::operator+(const float& other) const
    {
        return (*this) + Fraction(other);
    }    

    // float + fraction 
    const Fraction operator+(const float& num, const Fraction& other)
    {
        return Fraction(num) + other;
    }


    // ALL operator- functions
    // fraction - fraction
    const Fraction Fraction::operator-(const Fraction& other) const
    {
        // (a/b)-(c/d) => a*d - b*c
        int num = _numerator * other._denominator - other._numerator * _denominator;
        int den = _denominator * other._denominator; // b*d
        return Fraction(num, den);
    }

    // fraction - float
    const Fraction Fraction::operator-(const float& other) const
    {
        return (*this) - Fraction(other);
    }    

    // float - fraction
    const Fraction operator-(const float& num, const Fraction& other)
    {
        return Fraction(num) - other;
    }

    // ALL operator* functions
    // fraction * fraction
    const Fraction Fraction::operator*(const Fraction& other) const
    {
        // (a/b)*(c/d) => a*c, b*d
        int num = _numerator * other._numerator;
        int den = _denominator * other._denominator;
        return Fraction(num, den);
    }

    // fraction * float
    const Fraction Fraction::operator*(const float& num) const
    {
        return (*this) * Fraction(num);
    }

    // float * fraction
    const Fraction operator*(const float& num, const Fraction& other)
    {
        return Fraction(num) * other;
    }

    // ALL operator/ functions
    // fraction / fraction
    const Fraction Fraction::operator/(const Fraction& other) const
    {
        //(a/b) / (c/d) => (a*d)/(b*c)
        // if num is 0 then cant divide 
        if(other._numerator == 0) throw invalid_argument("Division by zero ERROR!");
        int num = _numerator * other._denominator;
        int den = _denominator * other._numerator;
        return Fraction(num, den);
    }

    // fraction / float
    const Fraction Fraction::operator/(const float& num) const
    {
        if( num == 0) throw invalid_argument("Division by zero ERROR");
        return (*this) / Fraction(num);
    }

    // float / fraction
    const Fraction operator/(const float& num, const Fraction& other)
    {
        if(other._numerator == 0) throw invalid_argument("Division by zero ERROR)");
        return Fraction(num) / other;
    }

    // = operator to set a fraction 
    Fraction& Fraction::operator=(const Fraction& fr)
    {
        if(this == &fr) return (*this);
        
        _numerator = fr._numerator;
        _denominator = fr._denominator;
    
        return (*this);
    }

    //ALL bool functions

    // fraction == fraction
    bool Fraction::operator==(const Fraction& other) const
    {
        return (_numerator == other._numerator && _denominator == other._denominator);
    }

    // fraction != fraction by using == 
    bool Fraction::operator!=(const Fraction& other) const 
    {
        return !(*this == other);
    }

    // fraction > fraction
    bool Fraction::operator>(const Fraction& other) const
    {
     return _numerator * other._denominator > other._numerator * _denominator;   
    }
    
    // fraction >= fraction
    bool Fraction::operator>=(const Fraction& other) const
    {
     return _numerator * other._denominator >= other._numerator * _denominator;   
    }

    // fraction <= fraction
    bool Fraction::operator<=(const Fraction& other) const
    {
     return _numerator * other._denominator <= other._numerator * _denominator;   
    }

    // fraction < fraction
    bool Fraction::operator<(const Fraction& other) const
    {
        return _numerator * other._denominator < other._numerator * _denominator;
    }

    // inc ++ and dec -- operations

    Fraction& Fraction::operator++()
    {
        _numerator += _denominator;
        reduce();
        return (*this);
    }

    Fraction Fraction::operator++(int)
    {
        Fraction fr = (*this);
        _numerator += _denominator;
        reduce();
        return fr;
    }

    Fraction& Fraction::operator--()
    {
        _numerator -= _denominator;
        reduce();
        return (*this);
    }

    Fraction Fraction::operator--(int)
    {
        Fraction fr = (*this);
        _numerator -= _denominator;
        reduce();
        return fr;
    }


    ostream& operator<<(ostream &os, const Fraction& fr)
    {
        os << fr._numerator << "/" << fr._denominator;
        return os;
    }

    istream& operator>>(istream &is, Fraction& fr)
    {
        int num, den;
        char ch;
        is >> num >> ch >> den;
        if(ch != '/' || den == 0) throw invalid_argument("Invalid input");
        fr = Fraction(num, den);
        return is;
    }

}