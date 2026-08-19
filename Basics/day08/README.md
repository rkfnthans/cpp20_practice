# Day 08 — Members and Constructors

## 1. Members and Member Functions

- Data member: stores the state of an object.
- Member function: defines behavior related to the object.

Example:

```text
health -> data member
take_damage() -> member function
heal() -> member function
```

- Member functions can access the object's private data members.
- Instead of directly setting a value, member functions can change state according to rules.

Example:

```text
take_damage(30) -> health decreases by 30
heal(20) -> health increases by 20
```

- This makes the reason for a state change clearer than using simple setters.

---

## 2. Constructors and Default Constructors

- A constructor is called automatically when an object is created.
- The constructor name is the same as the class name.
- Constructors do not have a return type.
- A member initializer list initializes data members directly.

Example:

```cpp
complex(double rnew, double inew)
    : r{rnew}, i{inew}
{
}
```

- A default constructor can create an object without arguments.

Example:

```cpp
complex()
    : r{0.0}, i{0.0}
{
}
```

- `complex c1;` calls the default constructor.
- `complex c2{3.0, 2.0};` calls the constructor with arguments.

---

## 3. Delegating Constructors

- A delegating constructor calls another constructor in the same class.
- It reuses existing initialization logic.

Example:

```cpp
complex()
    : complex{0.0, 0.0}
{
}
```

Direct initialization:

```cpp
: r{0.0}, i{0.0}
```

Delegating initialization:

```cpp
: complex{0.0, 0.0}
```

- Useful for reducing duplicated constructor code.
