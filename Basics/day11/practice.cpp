#include <iostream>

using namespace std;

class vector
{
    public:
        double& operator[](int i)& {..}
        const double& operator[](int i) const&{...}
};


/*
[DAY 11 NOTES]

- TOPIC: Member access, subscript operators, const member functions,
         and reference-qualified member functions

1) ACCESS METHODS

- A member function can return a member variable.

Example:
double real() const
{
    return r;
}

- Returning by value gives a copy of the member.
- Changing the returned value does not change the original member.

- Returning by non-const reference gives access to the original member.

Example:
double& real()
{
    return r;
}

- real() returns a reference to r.
- Therefore, the original member can be modified from outside.

Example:
c.real() += 5;

- This changes the actual value of c.r.

- A reference is an alias for the original object or variable.

Example:
double& rr = real(c);

- rr refers to c.r, not to the entire complex object.

If:
c.r = 3.0;

then:
rr = 10.0;

changes:
c.r = 10.0;


2) NON-MEMBER ACCESS FUNCTION

- Access can also be provided through a non-member function.

Example:
inline double& real(complex& c)
{
    return c.real();
}

- real(c) calls the public member function c.real().
- It eventually returns a reference to c.r.


3) FRIEND FUNCTION

- A friend function is not a member function,
  but it can access private members of the class.

Example:
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

- Without friend, a non-member function cannot directly access c.r
  when r is private.


4) TEMPORARY OBJECTS AND REFERENCES

- A reference to a member of a normal object is safe
  while the original object remains alive.

Example:
complex c{3.0, 7.0};
double& rr = real(c);

- rr refers to c.r.
- c must remain alive while rr is used.

- A temporary object is destroyed at the end of its full expression.

Example:
double r2 = real(complex{3.0, 7.0}) * 2.0;

Flow:
temporary complex object
-> access its real member
-> use the value in the expression
-> store the result in r2
-> expression ends
-> temporary object is destroyed

- Using a temporary member inside the same expression can be safe.
- Keeping a reference to a destroyed temporary object creates
  a dangling reference.


5) SUBSCRIPT OPERATOR

- operator[] allows a class object to be used with [] syntax.

Example:
int& operator[](int index)
{
    return data[index];
}

- These two forms are conceptually related:

goblin[0]

goblin.operator[](0)

- Returning int& gives access to the actual array element.

Example:
goblin[0] = 80;

- This changes the original data[0] value.


6) CONST SUBSCRIPT OPERATOR

- A const version can provide read-only access.

Example:
const int& operator[](int index) const
{
    return data[index];
}

- The first const prevents modification through the returned reference.
- The final const means the member function does not modify the object.

Example:
const Stats boss;

boss[0];       // allowed
boss[0] = 80;  // not allowed


7) at()

- operator[] normally performs direct indexed access.
- at() can check whether an index is within the valid range.
- An invalid index can cause an out_of_range exception.

Concept:
operator[]
-> direct access

at()
-> checked access


8) CONST MEMBER FUNCTIONS

- A const member function promises not to modify the current object.

Example:
double real() const
{
    return r;
}

- const objects can call const member functions.
- Non-const member functions generally cannot be called on const objects.

- Getter-like functions are commonly declared const.


9) REFERENCE-QUALIFIED MEMBER FUNCTIONS

- A ref-qualifier controls what kind of object can call
  a member function.

Example:
double& operator[](int i) &
{
    return data[i];
}

- The final & means the function can be called on an lvalue object.
- The returned double& refers to the original element
  and allows modification.

Example:
vector v;
v[0] = 10.0;


10) CONST LVALUE VERSION

Example:
const double& operator[](int i) const &
{
    return data[i];
}

Meaning:
const double&
-> return a read-only reference

const
-> do not modify the current object

&
-> callable on an lvalue object


11) RVALUE / TEMPORARY OBJECT VERSION

Example:
double operator[](int i) &&
{
    return data[i];
}

- The final && means the function is called on an rvalue
  or temporary object.

Example:
double x = vector{}[0];

Flow:
temporary vector
-> operator[]() &&
-> copy the element value
-> store it in x
-> temporary vector is destroyed
-> x remains valid

- Returning by value is safer here than returning a reference
  to a member of a temporary object.


12) IMPORTANT DIFFERENCE

double& operator[](int i) &
-> lvalue object
-> return original element by reference
-> modification allowed

double operator[](int i) &
-> lvalue object
-> return a copy
-> original element cannot be modified through the result

const double& operator[](int i) const &
-> const lvalue object
-> read-only reference

double operator[](int i) &&
-> temporary/rvalue object
-> return a copied value


KEY IDEA:

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
*/