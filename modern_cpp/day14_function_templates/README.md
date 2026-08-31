# Day 14 — Function Templates and Forwarding References

## Date

2026-08-31

## Topic

Function templates, parameter deduction, forwarding references, perfect forwarding, and ordinary rvalue references.

## What I Studied

- Function templates with one or multiple type parameters
- Template parameter deduction
- Value, lvalue-reference, and const-reference parameters
- Lvalues and rvalues
- Forwarding references
- Reference collapsing
- Perfect forwarding with `std::forward`
- Ordinary rvalue references

## Key Notes

### 1. Function Templates

```cpp
template <typename T>
```

- `T` is a type parameter.
- One `T` means the related arguments use the same deduced type.
- Different types can use multiple parameters such as `T` and `U`.
- `auto` can deduce a return type.
- Number notation does not determine type: `10`, `0xA`, and `0b1010` can all be `int`.
- Generic templates may accept unintended types; constraints such as concepts / `requires` can be used later.

### 2. Function-Template Parameter Deduction

- `TPara`: type deduced by the compiler.
- `FPara`: book notation for the whole parameter-type pattern.

```text
T p
-> copies the argument into a new parameter

T& p
-> refers to the original object
-> can modify the original
-> cannot bind to ordinary rvalues

const T& p
-> refers without copying
-> cannot modify through p
-> can bind to lvalues, const lvalues, and rvalues
```

Example:

```cpp
int x = 10;
f(x);

void f(int p)
{
    p = 20;
}
```

```text
p is first initialized with 10
-> p becomes 20
-> x remains 10
```

### 3. Forwarding References and Value Categories

- lvalue: an identifiable object that can be accessed again.
- rvalue: a temporary value or expression result.

```cpp
template <typename T>
void f(T&& p);
```

```text
lvalue passed
-> T = int&
-> p = int&

rvalue passed
-> T = int
-> p = int&&
```

Reference collapsing:

```text
&  + &   -> &
&  + &&  -> &
&& + &   -> &
&& + &&  -> &&
```

### 4. Perfect Forwarding

```cpp
template <typename T>
void f(T&& p)
{
    g(std::forward<T>(p));
}
```

- `g(p)`: named `p` is treated as an lvalue expression.
- `std::forward<T>(p)` preserves the original value category.
  - lvalue stays lvalue.
  - rvalue stays rvalue.
- `std::move(p)` forces `p` to be treated as an rvalue.

### 5. Ordinary Rvalue References

```cpp
void f(int&& p);
```

- Binds to rvalues only.
- Cannot bind to ordinary lvalues.
- Inside the function, the named variable `p` is an lvalue expression.
- `T&&` is a forwarding reference only when `T` is deduced for that function call.
- If `T` is already fixed, `T&&` is an ordinary rvalue reference.

## What I Can Explain Now

- Why a value parameter creates a separate parameter object
- How `T&` differs from `const T&`
- The basic difference between lvalues and rvalues
- Why a deduced `T&&` can accept both lvalues and rvalues
- How reference collapsing works
- Why `std::forward` is used for perfect forwarding
- How an ordinary rvalue reference differs from a forwarding reference

## Next Topic

Continue function-template deduction and related template rules.
