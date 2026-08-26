#include <iostream>
#include <initializer_list>

class Polynomial
{
    private:
        int degree;
        double* coefficients;

    public:
        explicit Polynomial(int d)
            :degree{d}, coefficients{new double[d+1]{}}{}

        Polynomial(const Polynomial&)=default;

        Polynomial(std::initializer_list<double> values)
        {
            degree=static_cast<int>(values.size())-1;

            coefficients=new double[values.size()];

            int i{0};

            for (double value : values)
            {
                coefficients[i]=value;

                ++i;

            }

        }

        Polynomial& operator=(Polynomial&& other) noexcept
        {
            std::cout << "Move assignment called\n";

            if (this != &other)
            {
                delete[] coefficients;

                degree=other.degree;
                coefficients=other.coefficients;

                other.coefficients=nullptr;
                other.degree=0;
            }
            return *this;
        }
        
        void set_coefficient(int power, double value)
        {
            coefficients[power]=value;
        }
        ~Polynomial()
        {
            delete[] coefficients;
        }

        friend std::ostream& operator<<(std::ostream& os, const Polynomial& p);
};

std::ostream& operator<<(std::ostream& os, const Polynomial& p)
{
    for (int i=p.degree; i>=0;--i)
    {
        if (i==0)
        {
            os<<p.coefficients[i];
        }
        else if (i==1)
        {
            os<<p.coefficients[i]<<"x";
        }
        else
        {
            os<<p.coefficients[i]<<"x^"<<i;
        }

        if(i>0)
        {
            os<<"+";
        }
        
    }

    return os;
}

Polynomial f(double c2, double c1, double c0)
{
    Polynomial p{2};

    p.set_coefficient(2,c2);
    p.set_coefficient(1,c1);
    p.set_coefficient(0,c0);

    return p;
}

int main()
{
    Polynomial p{2};

    p=f(3.0,2.0,1.0);

    std::cout<<p<<'\n';
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
- TOPIC: Rational class practice

- Store numerator and denominator as int.

int numerator;
int denominator;

- One int can be implicitly converted to Rational.

Rational(int n, int d = 1);

Rational r{3};
-> 3/1


- normalize() keeps Rational values in canonical form.

Rules:
- denominator > 0
- numerator and denominator are reduced by gcd

Example:
6/8
-> 3/4

1/-2
-> -1/2


- Arithmetic operators return a new Rational.

operator+
operator-
operator*
operator/

Example:
a + b
-> create new Rational
-> constructor calls normalize()


- Compound assignment operators modify the current object.

Rational& operator+=(const Rational& other)
{
    *this = *this + other;
    return *this;
}

Same pattern:
-=, *=, /=


- *this means the current Rational object.

*this = *this + other;
-> reuse operator+
-> store the result back into the current object


- Division by zero should throw an exception.

if (other.numerator == 0)
{
    throw std::invalid_argument{"cannot divide by 0"};
}


- operator<< allows Rational objects to be printed.

friend ostream& operator<<(ostream& os,
                           const Rational& r);

Example:
cout << r;

Output:
1/2


KEY IDEA:

Rational
-> always stored in normalized form

basic operators
-> return a new Rational

compound assignment
-> modify *this by reusing basic operators


3)
- TOPIC: Move assignment

Polynomial& operator=(Polynomial&& other) noexcept
{
    if (this != &other)
    {
        delete[] coefficients;

        degree = other.degree;
        coefficients = other.coefficients;

        other.degree = 0;
        other.coefficients = nullptr;
    }

    return *this;
}

- Move assignment transfers ownership
  of the dynamic array instead of copying it.

- nullptr prevents double deletion.

- A message can confirm that move assignment was called.


4)
- TOPIC: initializer_list constructor

Polynomial(std::initializer_list<double> values)
{
    degree = static_cast<int>(values.size()) - 1;

    coefficients = new double[values.size()];

    int i{0};

    for (double value : values)
    {
        coefficients[i] = value;
        ++i;
    }
}

- initializer_list receives multiple coefficients.

Example:
Polynomial p{1.0, 2.0, 3.0};

-> 3 coefficients
-> degree = 2

- values.size() gives the number of values.
- Each value is copied into coefficients[].


KEY IDEA:

move assignment
-> transfer resource ownership

initializer_list
-> initialize an object from multiple values
*/