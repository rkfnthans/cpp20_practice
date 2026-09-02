# Modern C++

This directory contains study records for modern C++ language features that build on the fundamentals completed in `basics/`.

Day 01 through Day 13 remain under `basics/`. Starting with Day 14, study sessions that focus primarily on modern C++ language mechanics are recorded here.

## Learning Objectives

This stage focuses on:

- function and class templates,
- template parameter deduction,
- forwarding references,
- perfect forwarding,
- copy and move semantics,
- RAII and ownership design,
- smart-pointer usage,
- concepts and constraints,
- and other modern C++ techniques used in reusable and performance-oriented code.

## Study Structure

```text
modern_cpp/
├── README.md
├── day_14/
│   ├── README.md
│   ├── practice.cpp
│   └── main.cpp
└── day_15/
    ├── README.md
    └── practice.cpp
```

A study day may contain only the files that are useful for that session.

### `practice.cpp`

Used for:

- syntax experiments,
- textbook examples,
- template-deduction tests,
- compiler-behavior checks,
- and short review exercises.

### `main.cpp`

Added when the session includes a meaningful applied program.

### Daily `README.md`

Records:

- concepts studied,
- important deduction rules,
- mistakes and corrections,
- what can be explained after the session,
- and the next topic.

## Current Topics

- [x] Basic function templates — introductory practice
- [x] Function-template parameter deduction — introductory practice
- [x] Value parameters
- [x] Lvalue-reference parameters
- [x] Const-reference parameters
- [x] Lvalue and rvalue basics
- [x] Forwarding references
- [x] Reference collapsing
- [x] Perfect forwarding with `std::forward`
- [x] Ordinary rvalue references
- [x] Template instantiation errors
- [x] Mixed-type template parameters
- [x] Uniform initialization
- [x] Return type deduction
- [x] Abbreviated function templates
- [x] Namespaces and basic name lookup
- [x] Namespace aliases
- [x] Argument-dependent lookup (ADL)
- [x] Qualified vs. unqualified function calls
- [ ] Continue template deduction rules
- [ ] Class templates
- [ ] Copy semantics
- [ ] Move semantics in greater depth
- [ ] Rule of Zero / Rule of Five
- [ ] Concepts and `requires`

## Learning Log

- [Day 14 — Function Templates and Forwarding References](day_14/)
- [Day 15 — Templates, Namespaces, and ADL](day_15/)

## Current Progress

**Current day:** Day 15

**Current topic:** Template error handling, return type deduction, abbreviated templates, namespaces, name lookup, and ADL

**Next milestone:** Continue the next modern C++ language topic and reinforce function lookup rules through practice.
