#include <iostream>

class complex
{
    public:
        complex(double rnew, double inew)
        : r{},i{}
        {
            r=rnew; i=inew;
        }
    private:
        double r, i;
};

int main()
{
    complex c1,c2;
    c1.set_r(3.0);
    c1.set_i(2.0);

    c2.set_r(c1.get_r());
    c2.set_i(c1.get_i());

    return 0;

}



/*
[DAY 08 NOTES]
1)
- TOPIC: Members and member functions

- Data member: stores the state of an object.
- Member function: defines behavior related to the object.

Example:
- health -> data member
- take_damage() -> member function
- heal() -> member function

- Member functions can access the object's private data members.
- Instead of directly setting a value, member functions can change state according to rules.

Example:
- take_damage(30) -> health decreases by 30
- heal(20) -> health increases by 20

- This makes the reason for a state change clearer than using simple setters.


2)
- TOPIC: Constructors and default constructors

- A constructor is called automatically when an object is created.
- The constructor name is the same as the class name.
- Constructors do not have a return type.

- A member initializer list initializes data members directly.

Example:
complex(double rnew, double inew)
    : r{rnew}, i{inew}
{
}

- A default constructor can create an object without arguments.

Example:
complex()
    : r{0.0}, i{0.0}
{
}

- complex c1; calls the default constructor.
- complex c2{3.0, 2.0}; calls the constructor with arguments.


3)
- TOPIC: Delegating constructors

- A delegating constructor calls another constructor in the same class.
- It reuses existing initialization logic.

Example:
complex()
    : complex{0.0, 0.0}
{
}

- Direct initialization:
  : r{0.0}, i{0.0}

- Delegating initialization:
  : complex{0.0, 0.0}

- Useful for reducing duplicated constructor code.
*/