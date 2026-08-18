# C++ Fundamentals

This directory contains my study records for the fundamental features of modern C++20.

The purpose of this stage is to build a reliable programming foundation before moving to classes, the C++ standard library, data structures, algorithms, resource management, and simulation architecture.

## Learning Objectives

In this stage, I will learn how to:

- compile and run C++20 programs,
- declare and initialize variables,
- use operators and expressions,
- control program flow with conditions and loops,
- write and call functions,
- pass objects by reference,
- use basic pointers and dynamic memory,
- use standard-library strings and containers,
- validate user input,
- organize a small program into clear functions,
- and separate a program into multiple source files.

## Study Structure

Each study session is organized into a separate Day directory.

```text
day_XX/
├── README.md
├── practice.cpp
└── main.cpp
```

### `practice.cpp`

Used as a temporary programming notebook for:

- examples typed while studying,
- syntax experiments,
- selected textbook exercises,
- testing different values and expressions,
- reproducing compiler warnings or errors,
- and comparing alternative implementations.

The file may be rewritten several times during one session.

### `main.cpp`

Contains a small applied program built from the concepts studied during that day.

The objective is to combine syntax into a program with a clear purpose rather than preserving isolated examples only.

### Daily `README.md`

Records:

- topics studied,
- the program that was created,
- implementation decisions,
- mistakes and corrections,
- observations about C++ behavior,
- comparisons with C or Python,
- what I can explain after the session,
- and the next topic.

## Completed and Planned Topics

- [x] First C++20 program
- [x] Variables and initialization
- [x] Operators and expressions
- [x] Conditional statements
- [x] Loops
- [x] Functions
- [x] Arrays
- [x] `std::string`
- [x] References
- [x] Basic pointers
- [x] Pointer reassignment
- [x] Array and pointer size comparison
- [x] `new`, `delete`, `new[]`, and `delete[]`
- [x] Introductory smart pointers
- [x] Value and reference parameters
- [x] File streams and filesystem basics
- [x] Struct-based applied simulation
- [x] Input validation with Boolean return values
- [x] Basic exception handling with `try`, `throw`, and `catch`
- [ ] `std::vector`
- [ ] Consistent `const` usage
- [ ] Header and source file separation
- [ ] Classes and constructors

## Learning Log

- [Day 01 — First C++20 Practice Session](day_01/)
- [Day 02 — File, Stream, and Filesystem Practice](day_02/)
- [Day 03 — Smart Pointer and Dynamic Memory Introduction](day_03/)
- [Day 04 — Pointer and Dynamic Memory Review](day_04/)
- [Day 05 — NPC Daily Life Simulation](day_05/)
- [Day 06 — C++ Fundamentals Review and Exercises](day_06/)
- [Day 07 — Exception Handling](day_07/)

## Day 05 Milestone

Day 05 combines several previously studied fundamentals into one small interactive simulation.

The program includes:

- an `NPC` structure,
- status variables for hunger, energy, and food,
- functions that modify the original NPC through references,
- user-selected actions,
- a Boolean result indicating whether a command was valid,
- a seven-day simulation loop,
- prevention of day progression after an unknown command,
- and final status output.

This exercise is an important transition point between isolated syntax practice and object-oriented C++. Day 06 then reinforces the underlying fundamentals through targeted review and diagnostic exercises.


## Day 06 Milestone

Day 06 reviews core language fundamentals through textbook exercises and direct compiler/runtime experiments.

The session includes:

- narrowing-conversion checks with brace initialization,
- integer literal suffixes and `auto`,
- mathematical expressions using intermediate variables and `std::numbers::pi`,
- a median-of-three program using both nested `if` / `else` and `?:`,
- a bisection-method loop with `std::signbit()` and a `1e-12` tolerance,
- fixed arrays and dynamically allocated arrays,
- correct `new[]` / `delete[]` pairing,
- intentional memory-leak testing with the macOS `leaks` tool,
- deliberate `new[]` / `delete` mismatch testing and Clang diagnostics,
- unit-conversion functions,
- and `assert()` with epsilon-based floating-point comparison.

The session also reinforced the difference between compiler warnings, runtime behavior, and dedicated memory-leak diagnostics.


## Day 07 Milestone

Day 07 introduces basic exception handling using *Do it! C++ Complete Guide*.

The session includes:

- `try`, `throw`, and `catch`,
- throwing and catching different types such as `int`, `float`, and `char`,
- observing that code after an executed `throw` is skipped,
- using exceptions for invalid input,
- distinguishing assignment (`=`) from comparison (`==`),
- learning that `catch` matches exception types rather than specific values,
- and building a simple Safe Calculator that handles division by zero and invalid operators.

The main exercise uses integer error codes with a single `catch(int error)` block to distinguish multiple error cases.

## Completion Criteria

The fundamentals stage will be considered complete when I can:

1. write and compile a small C++20 program without copying a complete solution,
2. explain the purpose of each major statement,
3. modify a program and predict the result,
4. diagnose basic compiler, runtime, and logic errors,
5. use functions, references, pointers, strings, conditions, and loops,
6. validate user input without corrupting program state,
7. use `const` appropriately for read-only function parameters,
8. store multiple objects in a standard-library container,
9. and divide a small program into multiple files.

## Next Stage

After completing the remaining fundamentals, I will continue with:

- classes and objects,
- constructors,
- encapsulation with `private` and `public`,
- member functions,
- `const` member functions,
- inheritance and virtual functions,
- `std::vector`,
- and header/source file separation.

The Day 05 NPC simulation will later be rebuilt as an object-oriented program so that the structural differences can be compared directly.
