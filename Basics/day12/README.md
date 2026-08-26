# Day 12 — Operator Overloading Design

## 1. Operator Overloading Design

`operator+` usually creates and returns a new result.
It should not modify the original objects.

```cpp
Energy operator+(const Energy& other) const
{
    return Energy{value + other.value};
}
```

```text
a + b
-> a unchanged
-> b unchanged
-> new result returned
```

`operator+=` modifies the left object itself.

```cpp
Energy& operator+=(const Energy& other)
{
    value += other.value;
    return *this;
}
```

```text
a += b
-> a = a + b
-> a is modified
-> b unchanged
```

For a member operator:

```text
a + b
-> a.operator+(b)

value
-> a.value

other.value
-> b.value
```

`*this` means the current object itself.

```cpp
return *this;
```

### Key Idea

```text
a + b
-> create a new result

a += b
-> modify a itself
```

Good operator overloading should match the normal meaning of the operator.

---

## 2. `explicit` Constructor and Member `operator+`

`explicit` prevents unintended implicit conversion.

```cpp
explicit complex(double rn = 0.0, double in = 0.0)
    : r{rn}, i{in} {}
```

```cpp
complex c{5.0};   // OK
complex c = 5.0;  // not allowed
```

A member `operator+` uses the left operand as `*this`.

```cpp
complex operator+(const complex& c2) const
{
    return complex(r + c2.r, i + c2.i);
}
```

```text
cc + c4
-> cc.operator+(c4)
-> create and return a new complex object
-> cc and c4 remain unchanged
```

The final `const` means the current object is not modified.

---

## 3. Operator Precedence and Associativity

Operator overloading changes behavior,
but does not change C++ precedence or associativity.

```text
a + b * c
-> a + (b * c)
```

Always check the original operator rules
when designing overloaded operators.

---

## 4. Member Function vs Free Function

Member operator:

```text
a + b
-> a.operator+(b)

left operand = *this
right operand = parameter
```

Free operator:

```text
a + b
-> operator+(a, b)

both operands = function parameters
```

Operators such as `+=` are often natural as member functions.

Symmetric operators such as `+` can also be free functions.

---

## 5. Equality Operator

```cpp
bool operator==(const rational& r2) const = default;
```

- `operator==` returns `bool`.
- `= default` asks the compiler to generate the comparison automatically.
- Members are compared in their stored form.

---

## 6. Spaceship Operator `<=>`

```cpp
auto operator<=>(const value& v2) const = default;
```

- `<=>` is the C++20 three-way comparison operator.
- It represents less, equal, and greater relationships.
- A defaulted `<=>` can support `<`, `>`, `<=`, and `>=`.
- A defaulted member `<=>` can also provide the corresponding equality comparison.
- `auto` lets the compiler determine the proper comparison result type.

---

## 7. Type-System Extension with Operator Overloading

User-defined types can have their own valid operations.

```text
Distance + Distance
-> Distance

Distance / Time
-> Speed
```

Invalid combinations can be rejected at compile time.

```text
Distance + Energy
-> not allowed unless explicitly defined
```

## Key Idea

```text
explicit
-> blocks automatic conversion

member operator+
-> left operand = *this
-> right operand = parameter
-> returns a new result
```

Operator overloading can:

```text
-> make user-defined types behave naturally
-> preserve meaningful operator behavior
-> prevent invalid type combinations
-> extend the C++ type system
```
