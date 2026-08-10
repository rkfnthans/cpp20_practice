# Day 06 — C++ Fundamentals Review and Exercises

## Date

2026-08-10

## Topic

Reviewing fundamental C++ concepts through textbook exercises:
integer types, literals, operators, branching, loops, arrays, pointers,
dynamic memory, functions, and basic testing.

## What I Studied

### 1. Narrowing Conversions

Tested how brace initialization handles integer values that cannot be safely
represented by the destination type.

Examples included:

```cpp
const unsigned c1{4000000000};
const int c1{4000000000};
const long c1{4000000000};
```

I also tested negative values with unsigned integer types.

### What I Learned

- Brace initialization `{}` detects narrowing conversions.
- A value must be representable by the destination type.
- Unsigned integer types cannot represent negative values.
- The range of an integer type matters when choosing a type.

---

### 2. Integer Literals

Tested integer literal suffixes such as:

```cpp
4000000000u
```

and used `auto` to let the compiler infer the type.

Example:

```cpp
const auto c1{4000000000u};
```

### What I Learned

- A suffix such as `u` affects the type of the literal itself.
- `auto` can infer a variable type from the initializer.
- The type of the literal and the type of the destination variable are separate concepts.

---

### 3. Operators and Intermediate Expressions

Practiced translating mathematical formulas into C++ expressions.

Used intermediate variables to avoid repeating calculations.

Example:

```cpp
double a_squared{a * a};
double a_cube{a_squared * a};
double circle_area{std::numbers::pi * a_squared};
double cone_volume{circle_area * h / 3.0};
```

### What I Learned

- `<numbers>` provides `std::numbers::pi` in C++20.
- Repeated expressions can be calculated once and reused.
- Meaningful intermediate variable names make mathematical code easier to read.
- `/ 3.0` clearly expresses floating-point division.

---

### 4. Branching — Median of Three Values

First implemented the median of three `double` values using nested
`if` / `else` statements.

Correct chained input:

```cpp
std::cin >> a >> b >> c;
```

I then rewrote the same logic using the conditional operator `?:`.

```cpp
double median
{
    a >= b
    ? (
        a >= c
        ? (b >= c ? b : c)
        : a
    )
    : (
        b >= c
        ? (a >= c ? a : c)
        : b
    )
};
```

### What I Learned

- `condition ? value1 : value2` selects and produces a value.
- A comparison such as `b >= c` produces only `true` or `false`.
- Nested conditional operators are possible but can quickly become difficult to read.
- `if` / `else` is generally clearer for complicated branching.
- `?:` is useful for simple value selection.

---

### 5. Loops — Bisection Method

Implemented a basic bisection method for:

```cpp
double f(double x)
{
    return std::sin(5 * x) + std::cos(x);
}
```

The interval is repeatedly divided in half.

```cpp
while (std::abs(right - left) >= 1e-12)
{
    double middle{
        (left + right) / 2.0
    };

    if (std::signbit(f(left)) != std::signbit(f(middle)))
    {
        right = middle;
    }
    else
    {
        left = middle;
    }
}
```

After the loop:

```cpp
double root{
    (left + right) / 2.0
};
```

### What I Learned

- `std::signbit()` can be used to compare signs of floating-point values.
- The midpoint must be recalculated every time the interval changes.
- The loop stops when the interval is sufficiently small.
- `1e-12` represents \(10^{-12}\).
- `^` is not exponentiation in C++; it is the bitwise XOR operator.
- The initial bisection interval should bracket a root for the standard method to work.
- Numerical algorithms often repeat calculations until an error tolerance is reached.

---

### 6. Arrays, Pointers, and Dynamic Memory

Created fixed-size arrays:

```cpp
int fixed1[5]{1, 2, 3, 4, 5};
double fixed2[3]{1.1, 2.2, 3.3};
```

Created dynamically allocated arrays:

```cpp
int* dynamic1{new int[5]{1, 2, 3, 4, 5}};
double* dynamic2{new double[3]{1.1, 2.2, 3.3}};
```

Correctly released them with:

```cpp
delete[] dynamic1;
delete[] dynamic2;
```

### Memory Leak Experiment

I intentionally omitted:

```cpp
delete[] dynamic2;
```

and checked the program with the macOS `leaks` tool:

```bash
leaks --atExit -- ./practice
```

The tool reported:

```text
1 leak for 32 total leaked bytes
```

After restoring:

```cpp
delete[] dynamic2;
```

the result became:

```text
0 leaks for 0 total leaked bytes
```

### Mismatched `new[]` / `delete` Experiment

I intentionally wrote:

```cpp
delete dynamic1;
```

for memory allocated using:

```cpp
new int[5]
```

Clang produced a warning indicating that `delete` was applied to a pointer
allocated with `new[]` and suggested `delete[]`.

### What I Learned

The required allocation/deallocation pairs are:

```text
new      <-> delete
new[]    <-> delete[]
```

- Failing to release dynamically allocated memory can cause a memory leak.
- A memory leak may not immediately crash the program.
- `leaks` can detect memory that remains allocated when the program exits.
- `new[]` combined with `delete` is invalid even if a leak checker reports zero leaks.
- Compiler warnings and memory-leak reports detect different kinds of problems.

---

### 7. Functions and Assertions

Created unit-conversion functions.

```cpp
double meter2yard(double meter)
{
    return meter / 0.9144;
}

double yard2meter(double yard)
{
    return yard * 0.9144;
}
```

Tested the functions using `assert()` and a floating-point tolerance.

```cpp
const double epsilon{1e-12};

assert(
    std::abs(meter2yard(0.9144) - 1.0) < epsilon
);

assert(
    std::abs(yard2meter(1.0) - 0.9144) < epsilon
);
```

### What I Learned

- A function definition does not require a semicolon after its closing `}`.
- Statements such as variable declarations and `return` statements require `;`.
- Floating-point calculations should often be compared using a tolerance rather than exact equality.
- `assert()` is useful for checking assumptions and simple function results.
- A successful `assert()` produces no output.

---

## Mistakes and Corrections

### Mistake 1 — Compilation and Execution in One Command

Incorrect:

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic practice.cpp -o practice ./practice
```

This caused Clang to interpret `./practice` as another input file.

### Correction

Use two commands:

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic practice.cpp -o practice
./practice
```

or:

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic practice.cpp -o practice && ./practice
```

---

### Mistake 2 — Incorrect `std::cin` Chaining

Incorrect:

```cpp
std::cin >> a, b, c;
```

Correct:

```cpp
std::cin >> a >> b >> c;
```

---

### Mistake 3 — Missing Final Newline

Output such as:

```text
8.37758%
```

was caused by the zsh `%` prompt appearing immediately after program output.

### Correction

```cpp
std::cout << result << '\n';
```

---

### Mistake 4 — Calculating Before Input

The midpoint was initially calculated before values were read into `left`
and `right`.

Incorrect order:

```cpp
double middle{(left + right) / 2.0};
std::cin >> left >> right;
```

Correct order:

```cpp
std::cin >> left >> right;
double middle{(left + right) / 2.0};
```

---

### Mistake 5 — Incorrect Exponent Syntax

Incorrect:

```cpp
10^-12
```

In C++, `^` means bitwise XOR.

Correct:

```cpp
1e-12
```

---

### Mistake 6 — `new[]` / `delete` Mismatch

Incorrect:

```cpp
int* values{new int[5]};
delete values;
```

Correct:

```cpp
int* values{new int[5]};
delete[] values;
```

---

### Mistake 7 — Extra Semicolon After Function Definition

Initial form:

```cpp
double meter2yard(double meter)
{
    return meter / 0.9144;
};
```

Preferred form:

```cpp
double meter2yard(double meter)
{
    return meter / 0.9144;
}
```

The return type `double` does not determine whether a semicolon is required;
the syntactic construct determines it.

---

## Compiler and Memory Tools Used

Normal compilation:

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic practice.cpp -o practice
```

Compile and execute:

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic practice.cpp -o practice && ./practice
```

Memory-leak experiment on macOS:

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic -g practice.cpp -o practice
leaks --atExit -- ./practice
```

`ASAN_OPTIONS=detect_leaks=1` was not supported by the current macOS
AddressSanitizer runtime, so the macOS `leaks` tool was used for the leak
experiment.

---

## What I Can Explain Now

- Why brace initialization can reject narrowing conversions
- The purpose of integer literal suffixes such as `u`
- How to reuse intermediate expressions in mathematical calculations
- How nested `if` statements and conditional operators differ
- How `?:` produces a value
- How a bisection loop repeatedly reduces an interval
- Why `1e-12` is used instead of `10^-12`
- Why a bisection interval should bracket a root
- The difference between fixed arrays and dynamically allocated arrays
- Why `new[]` must be paired with `delete[]`
- What a memory leak is
- Why zero reported leaks does not prove that all memory operations were valid
- How compiler warnings can detect mismatched `new[]` and `delete`
- How to write simple conversion functions
- Why floating-point tests use an epsilon tolerance
- How `assert()` can be used for basic correctness checks

## Next Topic

Continue the function exercises and complete the remaining unit-conversion
functions, then move on to the next C++ fundamentals section.
