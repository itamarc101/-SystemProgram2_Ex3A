#include "doctest.h"
#include "sources/Fraction.hpp"
#include <sstream>

using namespace std;
using namespace ariel;

TEST_CASE("Test 1 - constructor")
{
    CHECK_NOTHROW(Fraction());
    CHECK_NOTHROW(Fraction(0, 1));
    CHECK_NOTHROW(Fraction(7,2));
    CHECK_THROWS(Fraction(72,0));
}

TEST_CASE("Test 2 - normal operators")
{
    Fraction a(3,4);
    Fraction b(1,3);
    float f = 0.5;
    CHECK(a + b == Fraction(13,12));
    CHECK(a - b == Fraction(5, 12));
    CHECK(a * b == Fraction(1, 4));
    CHECK(a / b == Fraction(9, 4));
    CHECK_NOTHROW(a + f);
    CHECK_NOTHROW(a - f);
    CHECK_NOTHROW(a * f);
    CHECK_NOTHROW(a / f);
}

TEST_CASE("Test 3 - bool compare")
{
    Fraction a(1,2);
    Fraction b(3,4);
    Fraction c(2,4);
    CHECK(a < b);
    CHECK_FALSE(a > b);
    CHECK(a <= b);
    CHECK_FALSE(a >= b);
    CHECK(a == c);
    CHECK(b != c);
}

TEST_CASE("Test 4 - inc dec")
{
    Fraction a(1,2);
    Fraction preInc = ++a;
    CHECK(preInc == Fraction(3,2));
    CHECK(a == Fraction(3,2));

    Fraction postInc = a++;
    CHECK(postInc == Fraction(3,2));
    CHECK(a == Fraction(5,2));

    Fraction preDec = --a;
    CHECK(preDec == Fraction(3,2));
    CHECK(a == Fraction(3,2));

    Fraction postDec = a--;
    CHECK(postDec == Fraction(3,2));
    CHECK(a == Fraction(1,2));
}

TEST_CASE("Test 5 - ostream")
{
    Fraction a(1,2);
    std::stringstream ss;
    ss << a;
    CHECK(ss.str() == "1/2");

    Fraction b(5,10);
    std::stringstream ss1;
    ss1 << b;
    CHECK(ss1.str() == "1/2");

    Fraction c(0.5);
    std::stringstream ss2;
    ss2 << c;
    CHECK(ss2.str() == "1/2");


}

TEST_CASE("Test 6 - istream")
{
    Fraction a;
    std::stringstream ss("1/2");
    ss >> a;
    CHECK(a == Fraction(1,2));

    Fraction b;
    std::stringstream ss1("5/10");
    ss1 >> b;
    CHECK(b == Fraction(1,2));

}
