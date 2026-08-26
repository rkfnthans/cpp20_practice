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
    : degree{d},
      coefficients{new double[d + 1]{}}
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
```

```cpp
~Polynomial()
{
    delete[] coefficients;
}
```

- Memory created with `new[]` must be released with `delete[]`.
- `operator<<` allows natural output with `std::cout << p`.
- Coefficients are printed from the highest degree down to 0.

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

`normalize()` keeps values in canonical form.

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

Each operator returns a new `Rational`.

The constructor calls `normalize()`, so arithmetic results are normalized automatically.

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
-=, *=, /=
```

- Existing arithmetic operators are reused.
- `*this` means the current object.

### Exceptions

Division by zero should throw an exception.

```cpp
if (other.numerator == 0)
{
    throw std::invalid_argument{"cannot divide by 0"};
}
```

### Output

```cpp
friend std::ostream& operator<<(std::ostream& os,
                                const Rational& r);
```

Example:

```text
1/2
```

---

## 3. Move Assignment

```cpp
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
```

- Move assignment transfers ownership of the dynamic array instead of copying it.
- Setting the moved-from pointer to `nullptr` prevents double deletion.
- A message inside the operator can confirm that move assignment was called.

---

## 4. `initializer_list` Constructor

```cpp
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
```

- `std::initializer_list` receives multiple coefficients.
- The polynomial degree is derived from the number of coefficients.

Example:

```cpp
Polynomial p{1.0, 2.0, 3.0};
```

```text
3 coefficients
-> degree = 2
```

- `values.size()` gives the number of values.
- Each value is copied into `coefficients[]`.

## Key Idea

```text
Polynomial
-> dynamic coefficient storage
-> new[] / delete[]
-> move assignment transfers resource ownership
-> initializer_list builds the polynomial from coefficient values

Rational
-> normalized representation
-> arithmetic operator overloading
-> compound assignment by reusing basic operators
-> exception handling
```
