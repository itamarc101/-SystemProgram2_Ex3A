#include <iostream>
using namespace std;

namespace ariel
{
    class Fraction
    {
        private:
        int _numerator;      // mone
        int _denominator;    // shever

        void reduce() ;  // reduce the fraction as much as possible
        int gcd(int a, int b);  // greatest common divisor

        public:
        Fraction();
        Fraction(float num);
        Fraction(int numerator, int denominator);

        const Fraction operator+(const Fraction& other) const;                      // Fraction + Fraction
        const Fraction operator+(const float& num) const;                           // Fraction + flaot
        friend const Fraction operator+(const float& num, const Fraction& other);   // float + Fraction
        // friend - non-member function and need to be declared as friend inside Fraction.
        // to allow access to private members of Fraction to perform operations

        const Fraction operator-(const Fraction& other) const;                      // Fraction - Fraction
        const Fraction operator-(const float& num) const;                           // Fraction - flaot
        friend const Fraction operator-(const float& num, const Fraction& other);   // float - Fraction

        const Fraction operator*(const Fraction& other) const;                      // Fraction * Fraction
        const Fraction operator*(const float& num) const;                           // Fraction * flaot
        friend const Fraction operator*(const float& num, const Fraction& other);   // float * Fraction

        const Fraction operator/(const Fraction& other) const;                      // Fraction / Fraction
        const Fraction operator/(const float& num) const;                           // Fraction / flaot
        friend const Fraction operator/(const float& num, const Fraction& other);   // float / Fraction

        Fraction& operator=(const Fraction& fr);                                    // = to set frac val as frac

        // BOOL OPERATIONS
        bool operator==(const Fraction& other) const;
        bool operator!=(const Fraction& other) const;
        bool operator>(const Fraction& other) const;
        bool operator<(const Fraction& other) const;
        bool operator>=(const Fraction& other) const;
        bool operator<=(const Fraction& other) const;

        // INC , DEC OPERATIONS
        Fraction& operator++();
        Fraction operator++(int);
        Fraction& operator--();
        Fraction operator--(int);

        friend std::ostream& operator<<(std::ostream& out, const Fraction& fr); // input stream
        friend std::istream& operator>>(std::istream& in, Fraction& fr);        // output stream
        
    };
}