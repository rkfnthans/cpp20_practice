#include <iostream>

namespace rocketscience{
    namespace mat{
        struct sparse_matrix{};
        struct dense_matrix{};
        struct uber_matrix^6{};

        template <typename Matrix>
        double one_norm(const Matrix& A){...}

    }

    namespace vec{
        struct sparse_vector
    }
}




/*
[DAY 15 NOTES]

1)
- TOPIC: Handling Template Errors

- Template errors may appear during instantiation.
- A template can compile until a specific type is used.
- The type must support the operations required by the template.

Example:
std::sort(vector<complex<float>>);

-> sort requires an ordering operation
-> complex<float> has no default operator<
-> provide a custom comparison rule if sorting is needed


2)
- TOPIC: Mixing Types (Review)

template <typename T>
void f(T a, T b);

- One T requires both arguments to deduce the same type.
- Mixed types can cause deduction failure.

f(10, 20);      // OK
f(10, 20.5);    // deduction conflict

Solutions:
- explicit conversion
- explicit template argument
- use multiple type parameters

template <typename T, typename U>
auto f(T a, U b);


3)
- Uniform initialization uses {}.

- Prevents narrowing:
int x{3.14};   // ERROR

- T{} value-initializes T.

- {} may prefer initializer_list constructors.


4)
- TOPIC: Return Type Deduction

- auto deduces the return type from the return expression.

template <typename T, typename U>
auto add(T a, U b)
{
    return a + b;
}

- Mixed input types can produce a different return type.
- Multiple return statements must deduce to the same type.
- decltype(auto) preserves the return expression type more exactly.

5)
- TOPIC: Abbreviated Function Templates

- C++20 allows auto in function parameters.

void f(auto x);

- Similar to:
template <typename T>
void f(T x);

- Each auto parameter is deduced independently.

auto add(auto a, auto b)
{
    return a + b;
}

- auto can also be combined with &, const&, and &&.


6)
- TOPIC: Namespaces and Name Lookup

- Same name in different namespaces means different entities.

::same
c1::same
c1::c2::same

- Unqualified names are searched from the nearest scope outward.


7)
- TOPIC: Namespace Aliases

namespace dv = algebra::vector::dense;

- Creates a shorter alias for an existing namespace.


8)
- TOPIC: Argument-Dependent Lookup (ADL)

- ADL searches namespaces related to argument types.

rocketscience::matrix A;
initialize(A);

- Can find rocketscience::initialize through A's type.


9)
- TOPIC: Qualified Calls

rocketscience::initialize(E);

- rocketscience:: specifies where the function is.
- E may belong to a different namespace.
- Templates can deduce E's type independently.
s*/