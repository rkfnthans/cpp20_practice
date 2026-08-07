# C++20 Practice

This repository documents my process of learning modern C++20 through syntax experiments, review exercises, and small applied programs.

I have previous experience with C and Python, but I am currently rebuilding my programming foundation in modern C++ step by step.

## Purpose

The goals of this repository are to:

- learn modern C++20 through direct implementation,
- understand the differences between C, Python, and C++,
- practice compiling, running, and debugging C++ programs,
- apply each group of concepts through a small program,
- record mistakes and corrections for later review,
- build a consistent technical learning history,
- and prepare for the future development of the Living World Engine.

## Study Material

- Main book: *Modern C++: Learn Only What You Need* (*필요한 것만 골라 배우는 모던 C++*)
- Supplementary material: *Do it! C++ Complete Guide* (*Do it! C++ 완전 정복*)
- Language standard: C++20
- Compiler: Apple Clang
- Development environment: macOS and Visual Studio Code
- Shell: zsh
- Version control: Git and GitHub

## Learning Method

A typical study session uses the following structure:

```text
day_XX_topic/
├── README.md
├── practice.cpp
└── main.cpp
```

### `practice.cpp`

This file is used as a temporary programming notebook.

It may contain:

- examples typed while reading a book or watching a lecture,
- syntax experiments,
- selected exercises,
- modified versions of example code,
- comparisons between different C++ behaviors,
- and code written to reproduce an error or compiler warning.

### `main.cpp`

This file contains a small applied program that combines the concepts studied during the session.

The program should have a clear purpose rather than simply listing isolated syntax examples.

Examples include:

- a resource calculator,
- a file-processing program,
- a character status system,
- a small NPC simulation,
- and a basic world-state simulation.

### Daily `README.md`

Each daily README records:

- concepts studied,
- program structure,
- implementation decisions,
- mistakes and corrections,
- C or Python comparisons,
- what I can explain after the session,
- and the next topic.

## Learning Process

```text
Read or watch the relevant material
→ Test the syntax in practice.cpp
→ Modify the example without copying it exactly
→ Build a small program in main.cpp
→ Compile and run the program
→ Fix warnings and logic errors
→ Record the result in README.md
→ Commit and push the changes
```

A topic is considered complete only when I can modify the code, predict the result, and explain the main structure without copying the original example.

## Learning Roadmap

### Stage 1 — C++ Fundamentals

- [x] Compile and run a C++20 program
- [x] Variables and initialization
- [x] Operators and expressions
- [x] Conditional statements
- [x] Loops
- [x] Functions
- [x] `std::string`
- [x] References
- [x] Basic pointers
- [x] Dynamic memory fundamentals
- [ ] `std::vector`
- [ ] `const` usage in function interfaces
- [ ] Multiple source files

### Stage 2 — Classes and Object-Oriented C++

- [ ] Define a class
- [ ] Use constructors
- [ ] Understand `public` and `private`
- [ ] Write member functions
- [ ] Write `const` member functions
- [ ] Store objects in containers
- [ ] Separate declarations and implementations
- [ ] Understand basic object lifetime
- [ ] Understand inheritance and virtual functions

### Stage 3 — Standard Library and Data Structures

- [ ] `std::array`
- [ ] `std::vector`
- [ ] STL iterators
- [ ] STL algorithms
- [ ] `std::map`
- [ ] `std::unordered_map`
- [ ] `std::stack`
- [ ] `std::queue`
- [ ] `std::priority_queue`
- [ ] `std::optional`
- [ ] `std::variant`

### Stage 4 — Modern C++ Foundations

- [ ] Lambda expressions
- [ ] Basic templates
- [ ] Copy and move fundamentals
- [ ] RAII
- [ ] Smart pointer review
- [ ] Error handling
- [ ] Basic automated testing
- [ ] CMake

### Stage 5 — Mini World Simulation

- [ ] Create a grid-based world
- [ ] Store resources in each cell
- [ ] Advance simulation time
- [ ] Implement resource production and consumption
- [ ] Implement NPC needs and actions
- [ ] Implement seasonal changes
- [ ] Divide the program into multiple files
- [ ] Add basic tests

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

**Current topic:** Combining structs, functions, references, conditions, loops, and user input

**Current exercise:** Day 05 — NPC Daily Life Simulation

**Next milestone:** Begin object-oriented C++ lectures and rebuild the NPC simulation using a class, constructor, member functions, and file separation.

## Learning Log

### C++ Fundamentals

- [Day 01 — First C++20 Practice Session](basics/day_01/)
- [Day 02 — File, Stream, and Filesystem Practice](basics/day_02/)
- [Day 03 — Smart Pointer and Dynamic Memory Introduction](basics/day_03/)
- [Day 04 — Pointer and Dynamic Memory Review](basics/day_04/)
- [Day 05 — NPC Daily Life Simulation](basics/day_05/)

## Long-Term Direction

The concepts learned in this repository will eventually be applied to the **Living World Engine**, a long-term C++20 simulation project.

The current practice repository contains learning exercises, experiments, and review programs. The future Living World Engine repository will contain reviewed, understood, tested, and progressively optimized systems.
