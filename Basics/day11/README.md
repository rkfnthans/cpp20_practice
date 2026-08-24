# Day 11 — Member Access and Reference-Qualified Operators

## Topic

Member access, subscript operators, const member functions, temporary-object safety, and reference-qualified member functions.

## What I Studied

- A member function can return a member variable by value or by reference.
- Returning by value creates a copy.
- Returning by non-const reference provides access to the original member.
- Returning by const reference provides read-only access to the original member.
- Non-member access functions can call public member functions.
- `friend` functions can directly access private members.
- References to members are valid only while the original object remains alive.
- Temporary objects are destroyed at the end of their full expression.
- `operator[]` lets class objects use indexed access syntax.
- A non-const subscript operator can return a modifiable reference.
- A const subscript operator can return a read-only reference.
- `at()` represents checked indexed access.
- Const member functions promise not to modify the current object.
- Ref-qualifiers `&` and `&&` restrict member functions to lvalue or rvalue objects.
- Returning by value from temporary objects can avoid dangling references.

## 1. Access Methods

```cpp
double real() const
{
    return r;
}
```

Returning by value gives a copy of the member.

```cpp
double& real()
{
    return r;
}
```

Returning by non-const reference gives access to the original member.

```cpp
c.real() += 5;
```

This changes the actual value of `c.r`.

A reference is an alias for the original variable.

```cpp
double& rr = real(c);
```

`rr` refers to `c.r`, not to the entire `complex` object.

If `c.r = 3.0`, then:

```cpp
rr = 10.0;
```

changes `c.r` to `10.0`.

## 2. Non-Member Access Function

```cpp
inline double& real(complex& c)
{
    return c.real();
}
```

`real(c)` calls the public member function `c.real()` and returns a reference to `c.r`.

## 3. Friend Function

```cpp
class complex
{
private:
    double r;

    friend double& real(complex& c);
};

double& real(complex& c)
{
    return c.r;
}
```

A friend function is not a member function, but it can directly access private members.

## 4. Temporary Objects and References

```cpp
complex c{3.0, 7.0};
double& rr = real(c);
```

`rr` is safe while `c` remains alive.

A temporary object is destroyed at the end of its full expression.

```cpp
double r2 = real(complex{3.0, 7.0}) * 2.0;
```

Flow:

```text
temporary complex object
-> access its real member
-> use the value in the expression
-> store the result in r2
-> expression ends
-> temporary object is destroyed
```

Keeping a reference to a destroyed temporary object creates a dangling reference.

## 5. Subscript Operator

```cpp
int& operator[](int index)
{
    return data[index];
}
```

Conceptually:

```cpp
goblin[0];
goblin.operator[](0);
```

Returning `int&` gives access to the actual array element.

```cpp
goblin[0] = 80;
```

This changes the original `data[0]`.

## 6. Const Subscript Operator

```cpp
const int& operator[](int index) const
{
    return data[index];
}
```

The first `const` prevents modification through the returned reference.

The final `const` means the member function does not modify the object.

```cpp
const Stats boss;

boss[0];       // allowed
boss[0] = 80;  // not allowed
```

## 7. `at()`

```text
operator[]
-> direct access

at()
-> checked access
```

`at()` can check whether an index is in range. An invalid index can cause an `out_of_range` exception.

## 8. Const Member Functions

```cpp
double real() const
{
    return r;
}
```

A const member function promises not to modify the current object.

Const objects can call const member functions.

## 9. Reference-Qualified Member Functions

```cpp
double& operator[](int i) &
{
    return data[i];
}
```

The final `&` means the function can be called on an lvalue object.

The returned `double&` refers to the original element and allows modification.

## 10. Const Lvalue Version

```cpp
const double& operator[](int i) const &
{
    return data[i];
}
```

Meaning:

```text
const double&
-> read-only reference

const
-> do not modify the current object

&
-> callable on an lvalue object
```

## 11. Rvalue / Temporary-Object Version

```cpp
double operator[](int i) &&
{
    return data[i];
}
```

The final `&&` means the function is called on an rvalue or temporary object.

```cpp
double x = vector{}[0];
```

Flow:

```text
temporary vector
-> operator[]() &&
-> copy the element value
-> store it in x
-> temporary vector is destroyed
-> x remains valid
```

Returning by value is safer than returning a reference to a member of a temporary object.

## 12. Important Differences

```text
double& operator[](int i) &
-> lvalue object
-> original element by reference
-> modification allowed

double operator[](int i) &
-> lvalue object
-> copied value
-> original element cannot be modified through the result

const double& operator[](int i) const &
-> const lvalue object
-> read-only reference

double operator[](int i) &&
-> temporary/rvalue object
-> copied value
```

## Key Idea

```text
Return type:

double
-> copy

double&
-> modifiable reference to original value

const double&
-> read-only reference to original value


Ref-qualifier:

&
-> lvalue object

&&
-> rvalue / temporary object


Function const:

...() const
-> member function does not modify the current object
```
