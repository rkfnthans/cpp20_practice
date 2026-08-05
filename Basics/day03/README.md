# Day 03 — Arrays, Smart Pointers, and `std::vector`

## Date

2026-08-05

## Topic

Practicing element-wise array operations, array parameters, dynamic memory, smart pointers, and basic `std::vector` usage.

## What I Studied

- Element-wise calculations with built-in arrays
- Array-size inference from initializer values
- Passing input and output arrays to a function
- Using `const` to protect input arrays
- Passing array size separately
- Dynamic arrays created with `new[]`
- Releasing dynamic arrays with `delete[]`
- Memory-leak and out-of-bounds risks
- Managing one object with `std::unique_ptr`
- Returning `std::unique_ptr` from a function
- Transferring unique ownership
- Sharing ownership with `std::shared_ptr`
- Checking shared ownership with `use_count()`
- Creating vectors with `std::vector`
- Passing vectors by reference
- Checking vector sizes with `assert()`

## Practice Method

The examples were written and modified in `practice.cpp`.

The session focused on understanding how arrays, pointers, smart pointers, and vectors manage data and memory. Several examples were tested separately, so a standalone `main.cpp` application was not created during this session.

## Element-Wise Array Calculation

```cpp
#include <iostream>

int main()
{
    float x[3]{};
    float v[]{1.0f, 2.0f, 3.0f};
    float w[]{7.0f, 8.0f, 9.0f};

    for (int i = 0; i < 3; ++i)
    {
        x[i] = v[i] - 3.0f * w[i];

        std::cout << "x[" << i << "] = "
                  << x[i] << '\n';
    }
}
```

### Notes

- The sizes of `v` and `w` are inferred from their initializer values.
- Each loop iteration calculates and prints one element.
- The `f` suffix makes floating-point literals such as `3.0f` explicitly use type `float`.

## Passing Arrays to a Function

```cpp
void vector_add(
    unsigned size,
    const double v1[],
    const double v2[],
    double s[]
)
{
    for (unsigned i = 0; i < size; ++i)
    {
        s[i] = v1[i] + v2[i];
    }
}
```

### Notes

- `v1` and `v2` are input arrays.
- `s` is the output array.
- `const` prevents the function from modifying the input arrays.
- The array size must be passed separately.
- Passing an incorrect size can cause out-of-bounds access.

## Dynamic Arrays

```cpp
constexpr unsigned size{3};

double* x = new double[size];
double* y = new double[size];
double* sum = new double[size];
```

The pointers `x`, `y`, and `sum` store the starting addresses of their dynamically allocated arrays.

```cpp
for (unsigned i = 0; i < size; ++i)
{
    x[i] = i + 2.0;
    y[i] = 4.0 - 2.0 * i;
}
```

This produces:

```text
x = {2, 3, 4}
y = {4, 2, 0}
```

After calling:

```cpp
vector_add(size, x, y, sum);
```

the result is:

```text
sum = {6, 5, 4}
```

### Releasing Dynamic Memory

```cpp
delete[] x;
delete[] y;
delete[] sum;
```

- Memory created with `new[]` must be released with `delete[]`.
- `new[]` and `delete[]` are a pair.
- `delete x[]` is invalid C++ syntax.
- Missing `delete[]` can cause a memory leak.
- All arrays should use the same `size` variable to avoid size mismatches.

## Managing One Object with `std::unique_ptr`

```cpp
#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<double> dp{new double};

    *dp = 7.0;

    std::cout << "The value of *dp is "
              << *dp << '\n';
}
```

### Notes

- `std::unique_ptr<double>` manages one dynamically allocated `double`.
- `<double>` specifies the managed type.
- `dp` owns and manages the allocated object.
- `*dp` accesses the managed value.
- The object is released automatically when `dp` goes out of scope.
- Manual `delete` is not required.

### Required Headers

```cpp
#include <iostream>  // std::cout
#include <memory>    // std::unique_ptr, std::shared_ptr
```

The original example used `std::cout` without including `<iostream>`. Adding the correct header fixed the compilation error.

## The `std` Namespace

The following names belong to the C++ standard library:

```cpp
std::cout
std::unique_ptr
std::shared_ptr
std::vector
```

Built-in types such as `int` and `double` do not require the `std::` prefix.

## Returning `std::unique_ptr` from a Function

```cpp
#include <memory>

std::unique_ptr<double> f()
{
    return std::make_unique<double>(7.0);
}

int main()
{
    auto dp3 = f();
}
```

### Execution Order

```text
Create dp3 from the result of f()
→ f() creates a managed double
→ f() returns a unique_ptr
→ dp3 receives ownership
→ main() ends
→ the managed memory is released automatically
```

### Notes

- `f()` returns `std::unique_ptr<double>`.
- `auto dp3 = f();` makes `dp3` a `std::unique_ptr<double>`.
- A default-constructed `unique_ptr` initially contains `nullptr`.
- `unique_ptr` cannot be copied because ownership must remain unique.
- Ownership can be moved from one `unique_ptr` to another.
- An empty `unique_ptr` must not be dereferenced.

## `new` versus `std::make_unique`

Direct construction:

```cpp
std::unique_ptr<double> dp{new double};
```

Preferred modern form:

```cpp
auto dp = std::make_unique<double>(7.0);
```

### Differences

- `new double` returns a raw pointer.
- `std::make_unique<double>()` creates the object and its `unique_ptr` together.
- `std::make_unique` is shorter and avoids directly handling the raw pointer.
- `std::make_unique<double>(7.0)` initializes the object immediately.
- `auto` lets the compiler infer that the variable type is `std::unique_ptr<double>`.

## Shared Ownership with `std::shared_ptr`

```cpp
#include <iostream>
#include <memory>

std::shared_ptr<double> f()
{
    auto p1 = std::make_shared<double>(7.0);
    auto p3 = p1;

    std::cout << "p3.use_count() = "
              << p3.use_count() << '\n';

    return p3;
}

int main()
{
    auto p = f();

    std::cout << "p.use_count() = "
              << p.use_count() << '\n';
}
```

Expected output:

```text
p3.use_count() = 2
p.use_count() = 1
```

### Notes

- `std::shared_ptr` allows several smart pointers to share ownership of one object.
- `p3 = p1` makes `p1` and `p3` own the same object.
- `use_count()` returns the current number of shared owners.
- `use_cout()` is invalid; the correct member function is `use_count()`.
- A separately created `shared_ptr` manages a different object.
- The managed object is deleted automatically when the last owner is destroyed.
- `std::make_shared<double>()` is preferred to directly writing `new double`.

## Basic `std::vector`

```cpp
#include <vector>

std::vector<float> v(3);
std::vector<float> w(3);
```

This creates two vectors with three value-initialized elements each.

```cpp
v[0] = 1.0f;
v[1] = 2.0f;
v[2] = 3.0f;

w[0] = 7.0f;
w[1] = 8.0f;
w[2] = 9.0f;
```

The same vectors can be initialized more directly:

```cpp
std::vector<float> v{1.0f, 2.0f, 3.0f};
std::vector<float> w{7.0f, 8.0f, 9.0f};
```

## Passing `std::vector` by Reference

```cpp
#include <cassert>
#include <vector>

void vector_add(
    const std::vector<float>& v1,
    const std::vector<float>& v2,
    std::vector<float>& s
)
{
    assert(v1.size() == v2.size());
    assert(v1.size() == s.size());

    for (std::size_t i = 0; i < v1.size(); ++i)
    {
        s[i] = v1[i] + v2[i];
    }
}
```

### Notes

- `const std::vector<float>&` avoids copying and prevents modification.
- `std::vector<float>& s` allows the function to modify the result vector.
- `assert()` checks that the vector sizes match.
- `<cassert>` is required when using `assert()`.
- `std::size_t` is suitable for vector sizes and indexes.
- Different vector sizes can cause out-of-bounds access.

## Mistakes and Corrections

### Invalid Array Deletion Syntax

```cpp
delete x[];    // invalid
delete[] x;    // correct
```

### Inconsistent Allocation Size

```cpp
double* sum = new double[3];
```

was changed to:

```cpp
double* sum = new double[size];
```

Using one size variable prevents mismatches when the size changes.

### Missing Namespace Prefix

```cpp
unique_ptr<double>
shared_ptr<double>
vector<float>
```

were changed to:

```cpp
std::unique_ptr<double>
std::shared_ptr<double>
std::vector<float>
```

### Missing Header

`std::cout` and `std::endl` were used without `<iostream>`.

```cpp
#include <iostream>
```

was added.

### Misspelled Member Function

```cpp
use_cout()
```

was corrected to:

```cpp
use_count()
```

## What I Can Explain Now

- How to perform an element-wise calculation with arrays
- Why array size must be passed separately to a raw-array function
- Why `const` is used for input arrays and input vectors
- How `new[]` allocates a dynamic array
- Why `delete[]` is required after `new[]`
- Why `delete x[]` is invalid syntax
- What a memory leak is
- How `std::unique_ptr` manages one object
- Why `unique_ptr` cannot be copied
- How ownership is returned from a function
- What `auto` does in `auto dp = std::make_unique<double>()`
- How `std::shared_ptr` shares ownership
- What `use_count()` reports
- Why `std::make_unique` and `std::make_shared` are preferred
- How `std::vector` stores a resizable sequence
- Why vectors are passed with references
- Why `assert()` is used to check matching vector sizes

## Next Topic

Continue practicing `std::vector`, references, and ownership concepts.

A small applied `main.cpp` will be created after the syntax is familiar enough to combine without relying heavily on the textbook examples.
