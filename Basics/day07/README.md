# Day 07 — Exception Handling

## Date

2026-08-11

## Topic

Basic exception handling with `try`, `throw`, and `catch`.

## Material

*Do it! C++ Complete Guide* (*Do it! C++ 완전 정복*)

## Practice

### 1. Basic Exception Flow

Practiced throwing different types and handling them with matching `catch`
blocks.

```cpp
throw 1;       // int
throw -1.0f;   // float
throw 'Z';     // char
```

Basic flow:

```text
try
-> throw
-> matching catch
```

When `throw` is executed, the remaining statements in the current `try`
execution path are skipped.

### 2. Input Validation

Practiced checking user input and throwing an exception when the input was
outside the allowed range.

The normal result was stored in a variable and printed after the conditional
logic instead of repeating output in every branch.

### 3. main.cpp — Safe Calculator

Built a simple calculator using:

- `double` operands,
- a `char` operator,
- `+`, `-`, `*`, and `/`,
- division-by-zero detection,
- invalid-operator detection,
- and exception handling.

Error cases:

```cpp
throw 1;   // division by zero
throw 2;   // invalid operator
```

Both are handled by:

```cpp
catch (int error)
```

The value of `error` is then used to identify the error case.

## Mistakes and Corrections

Assignment:

```cpp
op = '+';
```

Comparison:

```cpp
op == '+';
```

`catch` matches a type, not a specific value.

Incorrect:

```cpp
catch (1)
```

Correct:

```cpp
catch (int error)
```

## What I Learned

- `try` contains code that may throw an exception.
- `throw` interrupts normal execution and raises an exception.
- `catch` handles a matching exception type.
- Code after an executed `throw` is skipped.
- Different exception types can be handled by different `catch` blocks.
- Multiple error cases can also share one `catch` block and be distinguished by value.
- Exceptions can separate normal program logic from error-handling logic.

## Next Topic

Continue exception-handling practice and then move toward object-oriented C++.
