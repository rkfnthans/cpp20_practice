

/*
[DAY 14 NOTES]

1)
- TOPIC: Function Templates

- template <typename T>
  -> T is a type parameter.

- One T means both arguments use the same type.

- Different types:
  template <typename T, typename U>

- auto can deduce the return type.

- 10, 0xA, 0b1010 can all be int.
  Number notation != type.

- Generic templates may allow unintended types.
  Later: concepts / requires.


2)

- TOPIC: Function template parameter deduction

- TPara: type deduced by the compiler
- FPara: book notation for the whole parameter type pattern

T p
-> copies the argument into a new parameter p

T& p
-> refers to the original object
-> can modify the original
-> cannot bind to ordinary rvalues

const T& p
-> refers without copying
-> cannot modify through p
-> can bind to lvalues, const lvalues, and rvalues

Example:
int x = 10;
f(x);

void f(int p)
{
    p = 20;
}

-> p is first initialized with 10
-> then p becomes 20
-> x remains 10


3)

- TOPIC: Forwarding references and value categories

- lvalue:
  -> named object that can be referred to again
  -> examples: x, y

- rvalue:
  -> temporary value or expression result
  -> examples: 10, x + 5

template <typename T>
void f(T&& p);

- T&& can be a forwarding reference
- if an lvalue is passed:
  -> T = int&
  -> T&& collapses to int&

- if an rvalue is passed:
  -> T = int
  -> p becomes int&&

Reference collapsing:
&  + &   -> &
&  + &&  -> &
&& + &   -> &
&& + &&  -> &&

Example:
int x = 10;

f(x);      // lvalue -> p is int&
f(10);     // rvalue -> p is int&&
f(x + 5);  // rvalue -> p is int&&

- Do not think of lvalue/rvalue as input/output.
- Think of them as:
  lvalue  -> persistent identifiable object
  rvalue  -> temporary value or calculation result


4)

- Perfect forwarding preserves the original value category.

template <typename T>
void f(T&& p)
{
    g(std::forward<T>(p));
}

- g(p): p is treated as an lvalue
- std::forward<T>(p):
  -> lvalue stays lvalue
  -> rvalue stays rvalue

- std::move(p):
  -> forces p to be treated as an rvalue


5)

- Ordinary rvalue reference:

void f(int&& p);

- binds to rvalues only
- cannot bind to ordinary lvalues
- inside the function, the named variable p is an lvalue expression

- T&& is a forwarding reference only when T is deduced
- if T is already fixed, T&& is an ordinary rvalue reference
*/