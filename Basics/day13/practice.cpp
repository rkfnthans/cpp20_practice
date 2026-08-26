#include <iostream>
#include <numeric>
#include <stdexcept>

using namespace std;

class Rational
{
    private:
        int numerator;
        int denominator;

        void normalize()
        {
            if (denominator<0)
            {
                numerator=-numerator;
                denominator=-denominator;
            }

            int g = gcd(numerator,denominator);

            numerator=numerator/g;
            denominator=denominator/g;
        }
    public:
        Rational(int n, int d=1)
            :numerator{n}, denominator{d}
        {
            if (denominator==0)
            {
                throw std::invalid_argument{"denominator cannot be zero"};
            }
            
            normalize();
        }

        Rational operator+(const Rational& other) const
        {
            int new_numerator=numerator*other.denominator+other.numerator * denominator;
            int new_denominator=denominator*other.denominator;

            return Rational(new_numerator,new_denominator);
        }
        Rational operator-(const Rational& other) const
        {
            int new_numerator=numerator*other.denominator-other.numerator * denominator;
            int new_denominator=denominator*other.denominator;

            return Rational(new_numerator, new_denominator);
        }
        Rational operator*(const Rational& other) const
        {
            int new_numerator=numerator*other.numerator;
            int new_denominator=denominator*other.denominator;

            return Rational(new_numerator,new_denominator);
        }
        Rational operator/(const Rational& other) const
        {
            if (other.numerator==0)
            {
                throw std::invalid_argument{"cannot divide by 0"};
            }
            
            int new_numerator=numerator*other.denominator;
            int new_denominator=denominator*other.numerator;

            return Rational(new_numerator,new_denominator);
        }
        Rational& operator+=(const Rational& other)
        {
            *this=*this+other;

            return *this;
        }
        Rational& operator-=(const Rational& other) 
        {
            *this=*this-other;

            return *this;
        }
        Rational& operator*=(const Rational& other)
        {
            *this=*this * other;

            return *this;
        }
        Rational& operator/=(const Rational& other)
        {
            *this=*this / other;

            return *this;
        }

        friend ostream& operator<<(ostream& os, const Rational& r);
};

ostream& operator<<(ostream& os, const Rational& r)
{
    os<<r.numerator<<"/"<<r.denominator;
    return os;
}

int main()
{
    Rational a{1, 2};
    Rational b{1, 3};
    Rational c{2};   // int -> Rational 암묵적 변환 확인

    cout << "a = " << a << '\n';
    cout << "b = " << b << '\n';
    cout << "c = " << c << '\n';

    cout << "a + b = " << a + b << '\n';
    cout << "a - b = " << a - b << '\n';
    cout << "a * b = " << a * b << '\n';
    cout << "a / b = " << a / b << '\n';

    a += b;
    cout << "after a += b, a = " << a << '\n';

    a -= b;
    cout << "after a -= b, a = " << a << '\n';

    a *= b;
    cout << "after a *= b, a = " << a << '\n';

    a /= b;
    cout << "after a /= b, a = " << a << '\n';
}





/*
[DAY 13 NOTES]

1)
- TOPIC: Polynomial class practice

- Store the polynomial degree and coefficients.

int degree;
double* coefficients;

- The number of coefficients is degree + 1.

explicit Polynomial(int d)
    : degree{d},
      coefficients{new double[d + 1]{}}
{
}

- explicit prevents unintended int -> Polynomial conversion.

- Set each coefficient by index.

void set_coefficient(int power, double value)
{
    coefficients[power] = value;
}

- Dynamic arrays created with new[] must be released with delete[].

~Polynomial()
{
    delete[] coefficients;
}

- operator<< allows natural output with cout.

std::cout << p;

- friend allows operator<< to access private members.

- Print from the highest degree down to 0.

Example:
3x^2 + 2x + 1

2)

*/