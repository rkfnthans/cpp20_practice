#include <iostream>

using namespace std;

class value
{
    private:
        double x;
    public:
        explicit value(double x):x{x}{}
        auto operator<=>(const value& v2) const=default;
};






/*
[DAY 12 NOTES]

1)
- TOPIC: Operator overloading design

- operator+ usually creates and returns a new result.
- It should not modify the original objects.

Example:
Energy operator+(const Energy& other) const
{
    return Energy{value + other.value};
}

a + b
-> a unchanged
-> b unchanged
-> new result returned


- operator+= modifies the left object itself.

Example:
Energy& operator+=(const Energy& other)
{
    value += other.value;
    return *this;
}

a += b
-> a = a + b
-> a is modified
-> b unchanged


- In a member operator:

a + b

is conceptually:

a.operator+(b);

value
-> a.value

other.value
-> b.value


- *this means the current object itself.

return *this;

-> returns the modified current object by reference


KEY IDEA:

a + b
-> create a new result

a += b
-> modify a itself

Good operator overloading should match
the normal meaning of the operator.

2)
- TOPIC: explicit constructor and member operator+

- explicit prevents unintended implicit conversion.

explicit complex(double rn = 0.0, double in = 0.0)
    : r{rn}, i{in} {}

complex c{5.0};   // OK
complex c = 5.0;  // not allowed


- Member operator+ uses the left object as *this.

complex operator+(const complex& c2) const
{
    return complex(r + c2.r, i + c2.i);
}

cc + c4
-> cc.operator+(c4)
-> create and return a new complex object
-> cc and c4 remain unchanged

- The final const means the current object is not modified.



3)
- TOPIC: Operator precedence and associativity

- Operator overloading changes behavior,
  but does not change C++ precedence or associativity.

Example:
a + b * c
-> a + (b * c)

- Always check the original operator rules
  when designing overloaded operators.


4)
- TOPIC: Member function vs free function

Member operator:

a + b
-> a.operator+(b)

- left operand = *this
- right operand = parameter


Free operator:

a + b
-> operator+(a, b)

- both operands are function parameters.

- Operators such as += are often natural as member functions.
- Symmetric operators such as + can also be free functions.


5)
- TOPIC: Equality operator

bool operator==(const rational& r2) const = default;

- operator== returns bool.
- = default asks the compiler to generate
  the comparison automatically.
- Members are compared in their stored form.


6)
- TOPIC: Spaceship operator <=>

auto operator<=>(const value& v2) const = default;

- <=> is the C++20 three-way comparison operator.
- It represents less, equal, and greater relationships.

- A defaulted <=> can support:
  <, >, <=, >=

- A defaulted member <=> can also provide
  the corresponding equality comparison.

- auto lets the compiler determine
  the proper comparison result type.


7)
- TOPIC: Type-system extension with operator overloading

- User-defined types can have their own valid operations.

Examples:

Distance + Distance
-> Distance

Distance / Time
-> Speed

- Invalid combinations can be rejected at compile time.

Example:

Distance + Energy
-> not allowed unless explicitly defined


KEY IDEA:

KEY IDEA:

explicit
-> blocks automatic conversion

member operator+
-> left operand = *this
-> right operand = parameter
-> returns a new result

Operator overloading can:
-> make user-defined types behave naturally
-> preserve meaningful operator behavior
-> prevent invalid type combinations
-> extend the C++ type system

*/