# C++20 Practice

This repository documents my process of learning modern C++20 through syntax experiments, exercises, and small applied programs.

I have previous experience with C and Python, but I am currently learning modern C++ from the fundamentals.

## Purpose

The goals of this repository are to:

* learn modern C++20 step by step,
* understand the differences between C, Python, and C++,
* practice writing, compiling, and debugging C++ code,
* apply each concept through a small program,
* prepare for the future development of the Living World Engine.

## Study Material

* Main book: *필요한 것만 골라 배우는 모던 C++*
* Language standard: C++20
* Compiler: Apple Clang
* Development environment: macOS and Visual Studio Code
* Version control: Git and GitHub

## Learning Method

Each study session will contain three files:

```text
dayXX_topic/
├── README.md
├── practice.cpp
└── main.cpp
```

### `practice.cpp`

This file is used as a programming notebook.

It may contain:

* examples typed while reading the book,
* small syntax experiments,
* selected textbook exercises,
* modified values and expressions,
* comparisons between different C++ behaviors.

### `main.cpp`

This file contains a small applied program built using the concepts studied that day.

The program should have a clear purpose rather than simply listing syntax examples.

Examples include:

* a resource calculator,
* a unit converter,
* a simple simulation,
* a score calculator,
* a regional status report.

### Daily `README.md`

Each daily README records:

* the concepts studied,
* what was implemented,
* mistakes and corrections,
* differences from C or Python,
* and the next topic.

## Learning Process

```text
Read the relevant section
→ Test the syntax in practice.cpp
→ Complete a selected exercise
→ Build a small program in main.cpp
→ Compile and run both files
→ Record mistakes and corrections
→ Commit and push the results
```

A topic is considered complete only when I can modify the code and explain the concept without copying the original example.

## Learning Roadmap

### Stage 1 — C++ Fundamentals

* [ ] Compile and run a C++20 program
* [ ] Variables and initialization
* [ ] Operators and expressions
* [ ] Conditional statements
* [ ] Loops
* [ ] Functions
* [ ] `std::string`
* [ ] `std::vector`
* [ ] References and pointers
* [ ] `const`
* [ ] Multiple source files

### Stage 2 — Classes

* [ ] Define a class
* [ ] Use constructors
* [ ] Understand `public` and `private`
* [ ] Write member functions
* [ ] Write `const` member functions
* [ ] Store objects in containers
* [ ] Separate declarations and implementations
* [ ] Understand basic object lifetime

### Stage 3 — Standard Library

* [ ] `std::array`
* [ ] STL iterators
* [ ] STL algorithms
* [ ] `std::map`
* [ ] `std::unordered_map`
* [ ] `std::optional`
* [ ] `std::variant`
* [ ] Random-number utilities

### Stage 4 — Modern C++ Foundations

* [ ] Lambda expressions
* [ ] Basic templates
* [ ] Copy and move fundamentals
* [ ] RAII
* [ ] Smart pointers
* [ ] Error handling
* [ ] Basic automated testing
* [ ] CMake

### Stage 5 — Mini World Simulation

* [ ] Create a grid-based world
* [ ] Store resources in each cell
* [ ] Advance simulation time
* [ ] Implement resource production and consumption
* [ ] Implement seasonal changes
* [ ] Divide the program into multiple files
* [ ] Add basic tests

## Repository Structure

```text
cpp20_practice/
├── README.md
├── .gitignore
├── basics/
├── classes/
├── stl/
├── modern_cpp/
└── mini_projects/
```

The structure will be expanded gradually as the study progresses.

## Current Progress

**Current stage:** Stage 1 — C++ Fundamentals

**Current topic:** Repository setup and development environment

**Current exercise:** Not started

**Next milestone:** Create the first study folder with `practice.cpp` and `main.cpp`

## Learning Log

Daily study records will be linked here.

<!-- Example:

### C++ Fundamentals

- [Day 01 — Variables, Operators, and Expressions](basics/day01_variables_operators/)
- [Day 02 — Conditional Statements](basics/day02_conditionals/)
- [Day 03 — Loops](basics/day03_loops/)

-->

## Long-Term Direction

The concepts learned in this repository will eventually be applied to the **Living World Engine**, a long-term C++20 world simulation project.

This repository contains learning exercises and experiments. The Living World Engine repository will contain reviewed, understood, and tested project code.
