# C++20 Practice

This repository documents my process of learning modern C++20 through syntax experiments, exercises, and small applied programs.

I have previous experience with C and Python, but I am currently learning modern C++ from the fundamentals.

## Purpose

The goals of this repository are to:

* learn modern C++20 step by step,
* understand the differences between C, Python, and C++,
* practice writing, compiling, and debugging C++ code,
* apply each concept through a small program,
* build a consistent technical learning record,
* and prepare for the future development of the Living World Engine.

## Study Material

* Main book: *Modern C++: Learn Only What You Need* (*필요한 것만 골라 배우는 모던 C++*)
* Language standard: C++20
* Compiler: Apple Clang
* Development environment: macOS and Visual Studio Code
* Shell: zsh
* Version control: Git and GitHub

## Learning Method

A typical study session may contain the following files:

```text
day_XX_topic/
├── README.md
├── practice.cpp
└── main.cpp
```

Some sessions may contain only `practice.cpp` and a `README.md` when the available study time is used to understand, modify, and debug textbook examples.

### `practice.cpp`

This file is used as a programming notebook.

It may contain:

* examples typed while reading the book,
* small syntax experiments,
* selected textbook exercises,
* modified values and expressions,
* comparisons between different C++ behaviors,
* and code written specifically to reproduce an error or warning.

The file may be rewritten several times during one study session. Important examples are preserved separately when they are useful for later review.

### `main.cpp`

This file contains a small applied program built using the concepts studied that day.

The program should have a clear purpose rather than simply listing syntax examples.

Examples include:

* a resource calculator,
* a unit converter,
* a simple simulation,
* a score calculator,
* and a regional status report.

A `main.cpp` file is added only when the session includes enough time and concepts suitable for a meaningful applied program. Completing textbook examples and understanding their behavior takes priority over creating a forced mini-project.

### Daily `README.md`

Each daily README records:

* the concepts studied,
* what was implemented,
* mistakes and corrections,
* differences from C or Python,
* what I can explain after the session,
* and the next topic.

## Learning Process

```text
Read the relevant section
→ Test the syntax in practice.cpp
→ Complete a selected exercise
→ Build a small program in main.cpp when appropriate
→ Compile and run the code
→ Record mistakes and corrections
→ Commit and push the results
```

A topic is considered complete only when I can modify the code and explain the concept without copying the original example.

## Learning Roadmap

### Stage 1 — C++ Fundamentals

* [x] Compile and run a C++20 program
* [ ] Variables and initialization
* [ ] Operators and expressions
* [ ] Conditional statements
* [ ] Loops
* [ ] Functions
* [ ] `std::string`
* [ ] `std::vector`
* [ ] References and pointers
* [ ] `const`
* [x] Basic output streams
* [x] Basic file input and output
* [x] Basic stream-state checking
* [x] Basic filesystem inspection
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
├── Basics/
│   ├── README.md
│   ├── day01_Basic_C++/
│   └── day02/
├── classes/
├── stl/
├── modern_cpp/
└── mini_projects/
```

The structure will be expanded gradually as the study progresses.

## Current Progress

**Current stage:** Stage 1 — C++ Fundamentals

**Current topic:** Streams, file input and output, stream states, and basic filesystem inspection

**Current exercise:** Day 02 completed as a practice-focused session without a separate `main.cpp`

**Next milestone:** Continue the next fundamentals section and create a small applied program only when the studied concepts are ready to be combined meaningfully

## Learning Log

### C++ Fundamentals

- [Day 01 — First C++20 Practice Session](Basics/day01_Basic_C++/)
- [Day 02 — Streams, File I/O, and Filesystem](Basics/day02/)

## Long-Term Direction

The concepts learned in this repository will eventually be applied to the **Living World Engine**, a long-term C++20 world simulation project.

This repository contains learning exercises and experiments. The Living World Engine repository will contain reviewed, understood, and tested project code.
