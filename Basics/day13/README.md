# Day 13 — Polynomial and Rational Practice

## 1. Polynomial Class Practice

```cpp
int degree;
double* coefficients;
```

- The number of coefficients is `degree + 1`.
- `double*` points to a dynamically allocated coefficient array.

```cpp
explicit Polynomial(int d)
    : degree{d}, coefficients{new double[d + 1]{}}
{
}
```

- `explicit` prevents unintended `int -> Polynomial` conversion.
- `new[]` creates the coefficient array.

```cpp
void set_coefficient(int power, double value)
{
    coefficients[power] = value;
}

~Polynomial()
{
    delete[] coefficients;
}
```

- Memory created with `new[]` must be released with `delete[]`.
- `operator<<` allows natural output with `std::cout << p`.

Example:

```text
3x^2+2x+1
```

---

## 2. Rational Class Practice

```cpp
int numerator;
int denominator;
```

A single `int` can convert implicitly to `Rational`:

```cpp
Rational(int n, int d = 1);
```

```text
Rational{3}
-> 3/1
```

### Normalization

```cpp
void normalize()
{
    if (denominator < 0)
    {
        numerator = -numerator;
        denominator = -denominator;
    }

    int g = std::gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;
}
```

Rules:

```text
denominator > 0
numerator and denominator are reduced by gcd
```

Examples:

```text
6/8  -> 3/4
1/-2 -> -1/2
```

### Arithmetic Operators

```text
operator+
operator-
operator*
operator/
```

Each operator returns a new `Rational`. The constructor calls `normalize()`, so results are automatically reduced.

### Compound Assignment

```cpp
Rational& operator+=(const Rational& other)
{
    *this = *this + other;
    return *this;
}
```

Same pattern:

```text
-=  -> *this = *this - other
*=  -> *this = *this * other
/=  -> *this = *this / other
```

- Existing arithmetic operators are reused.
- `*this` means the current object.

### Exceptions

```cpp
if (denominator == 0)
{
    throw std::invalid_argument{"denominator cannot be zero"};
}
```

Division by a zero-valued rational must also be rejected.

### Output

```cpp
friend std::ostream& operator<<(std::ostream& os,
                                const Rational& r);
```

Example:

```text
1/2
```

## Key Idea

```text
Polynomial
-> dynamic coefficient storage
-> new[] / delete[]
-> ostream output

Rational
-> normalized representation
-> arithmetic operator overloading
-> compound assignment by reusing basic operators
-> exception handling
```
