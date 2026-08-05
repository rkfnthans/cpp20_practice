# C++ Fundamentals

This directory contains my study records for the fundamental features of modern C++20.

The purpose of this stage is to build a reliable foundation before studying classes, the C++ standard library, resource management, and simulation architecture.

## Learning Objectives

In this stage, I will learn how to:

- compile and run C++20 programs,
- declare and initialize variables,
- use operators and expressions,
- control program flow with conditions and loops,
- write and call functions,
- use basic standard-library types,
- use console, file, and in-memory streams,
- check stream states before using input data,
- inspect files and directories with `std::filesystem`,
- understand references, pointers, and `const`,
- understand the relationship between arrays and pointers,
- allocate and release dynamic memory,
- pass arrays and struct arrays to functions,
- modify original variables through pointers and references,
- use `std::unique_ptr` and `std::shared_ptr`,
- pass `std::vector` objects by reference,
- and separate a program into multiple source files.

## Study Structure

Each study session is organized into a separate Day directory.

A typical directory contains:

```text
day_XX/
├── README.md
├── practice.cpp
└── main.cpp
```

Some directories may contain only `practice.cpp` and a `README.md` when the session is fully used for textbook examples, syntax experiments, compilation, and debugging.

### `practice.cpp`

Used as a temporary programming notebook for:

- examples typed while reading the book,
- syntax experiments,
- selected textbook exercises,
- testing different values and expressions,
- and checking unexpected compiler or runtime behavior.

The file may be rewritten several times during a study session.

### `main.cpp`

Contains a small applied program built using the concepts studied that day.

Not every study session requires a `main.cpp`. It is added only when the studied concepts and available time support a meaningful applied exercise.

### Daily `README.md`

Records:

- topics studied,
- practice methods,
- programs created,
- mistakes and corrections,
- observations about C++ behavior,
- comparisons with C or Python,
- and the next topic.

## Planned Topics

- [x] First C++20 program
- [ ] Variables and initialization
- [ ] Operators and expressions
- [ ] Conditional statements
- [ ] Loops
- [x] Basic functions and return values
- [x] Basic arrays
- [ ] `std::string`
- [x] Basic `std::vector`
- [x] Basic references
- [x] Basic pointers
- [x] Arrays and pointers
- [x] Dynamic memory with `new` and `delete`
- [x] Dynamic arrays with `new[]` and `delete[]`
- [x] Passing arrays to functions
- [x] Passing struct arrays to functions
- [x] Static local variables
- [x] Basic `const` parameters
- [x] Basic output streams
- [x] Basic file input and output
- [x] Basic stream-state checking
- [x] Basic `std::filesystem`
- [x] Value and reference parameters
- [ ] Header and source file separation

## Learning Log

- [Day 01 — First C++20 Program](day01_Basic_C++/)
- [Day 02 — Streams, File I/O, and Filesystem](day02/)
- [Day 03 — Arrays, Smart Pointers, and std::vector](day03/)
- [Day 04 — Pointers, Dynamic Memory, and Function Parameters](day04/)

Additional daily records will be added as the study progresses.

## Current Focus

Day 04 was completed as a review-focused session using *Do it! C++ Complete Guide*.

The session covered pointer variables, address and dereference operators, multiple pointers, arrays and pointers, dynamic allocation with `new` and `new[]`, cleanup with `delete` and `delete[]`, function arguments and return values, modifying original variables through pointers, passing arrays and struct arrays to functions, static local variables, and reference parameters.

Multiple pointers were introduced, but they will be revisited later through practical function and NPC relationship exercises. The current priority is to continue progressing while strengthening pointers and references through repeated use.

## Completion Criteria

The fundamentals stage will be considered complete when I can:

1. write and compile a small C++20 program without copying,
2. explain the purpose of each major statement,
3. modify a program and predict the result,
4. diagnose basic compiler and runtime errors,
5. use functions, standard-library containers, references, pointers, and `const`,
6. allocate and safely release basic dynamic memory,
7. explain why modern C++ usually prefers containers and smart pointers over manual memory management,
8. check stream states before using file input,
9. inspect basic directory entries with `std::filesystem`,
10. and divide a small program into multiple files.

## Next Stage

After completing this directory, I will continue with classes, constructors, encapsulation, member functions, and object lifetime.
