# Day 15 — Templates, Namespaces, and ADL

## Date

2026-09-02

## Topic

Template error handling, mixed types, initialization, return type deduction, abbreviated function templates, namespaces, name lookup, and argument-dependent lookup.

## What I Studied

- Template errors during instantiation
- Mixing types in function templates
- Uniform initialization with `{}`
- Return type deduction with `auto` and `decltype(auto)`
- C++20 abbreviated function templates
- Namespaces and name lookup
- Namespace aliases
- Argument-dependent lookup (ADL)
- Qualified and unqualified function calls

## Key Notes

### 1. Handling Template Errors

- Template errors may appear during instantiation.
- The selected type must support the operations required by the template.

```cpp
std::sort(v.begin(), v.end());
```

`std::complex<float>` has no default ordering, so a custom comparison rule is required when sorting it.

### 2. Mixing Types

```cpp
template <typename T>
void f(T a, T b);
```

- One `T` requires compatible deduction for both arguments.
- Mixed types can use explicit conversion or multiple type parameters.

```cpp
template <typename T, typename U>
auto f(T a, U b);
```

### 3. Uniform Initialization

```cpp
int x{10};
```

- `{}` provides list initialization.
- Narrowing conversions are rejected.
- `T{}` can value-initialize an object.
- `initializer_list` constructors may receive preference.

### 4. Return Type Deduction

```cpp
template <typename T, typename U>
auto add(T a, U b)
{
    return a + b;
}
```

- `auto` deduces the return type from the return expression.
- Multiple return statements must deduce to the same type.
- `decltype(auto)` preserves the expression type more exactly.

### 5. Abbreviated Function Templates

```cpp
void f(auto x);
```

- C++20 allows `auto` in function parameters.
- Each `auto` parameter is deduced independently.
- `auto`, `auto&`, `const auto&`, and `auto&&` can be used.

### 6. Namespaces and Name Lookup

- The same name in different namespaces refers to different entities.

```cpp
::same
c1::same
c1::c2::same
```

- Unqualified names are searched from the nearest scope outward.

### 7. Namespace Aliases

```cpp
namespace dv = algebra::vector::dense;
```

- Creates a shorter alias for an existing namespace.
- It does not create a new namespace.

### 8. Argument-Dependent Lookup (ADL)

- ADL searches namespaces associated with function argument types.

```cpp
rocketscience::matrix A;
initialize(A);
```

`A` is a `rocketscience::matrix`, so ADL can find a matching function in `rocketscience`.

### 9. Qualified Calls

```cpp
rocketscience::initialize(E);
```

- `rocketscience::` specifies where the function is found.
- `E` may belong to a different namespace.
- A function template can deduce `E`'s type independently.

## What I Can Explain Now

- Why template errors can appear only after instantiation
- Why one template type parameter can reject mixed argument types
- How `auto` is used for return types and C++20 function parameters
- How namespaces distinguish identical names
- How namespace aliases shorten long namespace paths
- How ADL uses argument types to find related functions
- Why a function's namespace and an argument's namespace do not need to match

## Next Topic

Continue with the next modern C++ language topic and reinforce name lookup through additional examples.
