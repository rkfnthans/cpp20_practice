# C++20 Practice

This repository is the top-level study workspace for building practical C++20 programming ability, algorithmic problem-solving skills, software-engineering fundamentals, and the technical foundation needed for larger simulation projects.

I have previous experience with C and Python, and I am rebuilding my programming foundation in modern C++ step by step while separately practicing coding-test problems and applied programs.

---

## Purpose

The goals of this repository are to:

- learn modern C++20 through direct implementation,
- understand the differences between C, Python, and C++,
- practice compiling, running, debugging, and designing C++ programs,
- study object-oriented design, resource management, the standard library, and modern C++ techniques,
- develop data-structure and algorithm problem-solving ability through coding-test practice,
- learn how to reason about time and space complexity,
- apply learned concepts through small programs and simulations,
- build basic software-engineering habits for larger projects,
- keep language study and coding-test practice organized but connected,
- build a consistent technical learning history,
- and prepare for the future development of the Living World Engine.

---

# Study Tracks

This repository is organized into parallel study tracks.

```text
Modern C++ / Software Engineering
                │
                ├──────────────┐
                │              │
                │        Coding Test / Algorithms
                │              │
                └──────┬───────┘
                       │
              Applied Simulations
                       │
                       ▼
              Living World Engine
```

The tracks progress in parallel rather than in a strict sequence.

---

## Track A — Modern C++ and Software Engineering

The Modern C++ track focuses on understanding the language, its standard library, software structure, object lifetime, memory management, and performance-oriented programming.

Typical study sessions use:

```text
day_XX_topic/
├── README.md
├── practice.cpp
└── main.cpp
```

### `practice.cpp`

Used as a temporary programming notebook for:

- examples typed while studying,
- syntax experiments,
- selected textbook exercises,
- modified versions of example code,
- comparisons between C++ behaviors,
- and compiler/runtime experiments.

### `main.cpp`

Used when the session includes a meaningful applied program.

Examples include:

- resource calculators,
- file-processing programs,
- character status systems,
- NPC simulations,
- and small world-state simulations.

### Daily `README.md`

Records:

- concepts studied,
- implementation decisions,
- mistakes and corrections,
- differences from C or Python,
- what I can explain after the session,
- and the next topic.

---

# Modern C++ Roadmap

## Stage 1 — C++ Fundamentals

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
- [x] Basic exception handling
- [ ] `std::vector`
- [ ] Consistent `const` usage in function interfaces
- [ ] Multiple source files

### Completion Goal

Be able to write and explain small C++ programs without copying complete examples.

---

## Stage 2 — Classes and Object-Oriented C++

- [x] Define a class — introductory practice
- [x] Use constructors — introductory practice
- [x] Understand `public` and `private`
- [x] Write member functions — introductory practice
- [x] Write `const` member functions
- [x] Operator overloading design
- [x] Comparison operators (`==`, `<=>`) — introductory practice
- [x] Move assignment — introductory practice
- [x] `std::initializer_list` constructor — introductory practice
- [ ] Store objects in containers
- [ ] Understand object lifetime in more depth
- [ ] Separate declarations and implementations
- [ ] Inheritance
- [ ] Virtual functions
- [ ] Polymorphism
- [ ] Composition vs. inheritance

### Completion Goal

Be able to design small classes with clear ownership, behavior, and interfaces.

---

## Stage 3 — C++ Standard Library

- [ ] `std::array`
- [ ] `std::vector`
- [ ] STL iterators
- [ ] STL algorithms
- [ ] `std::sort`
- [ ] Lambda expressions with STL algorithms
- [ ] `std::map`
- [ ] `std::unordered_map`
- [ ] `std::set`
- [ ] `std::unordered_set`
- [ ] `std::stack`
- [ ] `std::queue`
- [ ] `std::deque`
- [ ] `std::priority_queue`
- [ ] `std::optional`
- [ ] `std::variant`
- [ ] Random-number utilities
- [ ] `std::chrono`

### Completion Goal

Be able to choose and use standard-library containers and algorithms without reimplementing common functionality unnecessarily.

---

## Stage 4 — Modern C++ Foundations

- [ ] Copy semantics
- [ ] Move semantics
- [ ] Rule of Zero
- [ ] Rule of Five
- [x] RAII — introductory practice
- [x] Smart pointer review — introductory practice
- [ ] `unique_ptr` in class ownership
- [ ] `shared_ptr` ownership trade-offs
- [ ] `weak_ptr`
- [x] Basic templates — introductory practice
- [x] Function templates — introductory practice
- [x] Forwarding references — introductory practice
- [x] Perfect forwarding — introductory practice
- [x] Template instantiation errors — introductory practice
- [x] Mixed-type template parameters — introductory practice
- [x] Uniform initialization — review
- [x] Return type deduction with `auto` — introductory practice
- [x] Abbreviated function templates — introductory practice
- [x] Namespaces and basic name lookup — introductory practice
- [x] Namespace aliases — introductory practice
- [x] Argument-dependent lookup (ADL) — introductory practice
- [ ] Class templates
- [ ] Lambda expressions
- [ ] Error handling design
- [ ] Basic automated testing
- [ ] CMake fundamentals

### Completion Goal

Be able to write modern C++ code with explicit ownership, predictable lifetime, and reusable abstractions.

---

## Stage 5 — Applied C++ Projects

- [ ] Build programs using multiple classes
- [ ] Store objects in STL containers
- [ ] Separate `.hpp` and `.cpp` files
- [ ] Build multi-file programs
- [ ] Use CMake for project builds
- [ ] Add basic automated tests
- [ ] Add logging
- [ ] Implement basic file-based save/load
- [ ] Refactor repeated logic
- [ ] Build a small simulation project

### Example Milestone

```text
small simulation
→ multiple classes
→ multiple source files
→ STL containers
→ save/load
→ basic tests
```

### Completion Goal

Move from isolated exercises to maintainable multi-file programs.

---

## Stage 6 — Intermediate and Systems C++

- [ ] Advanced templates
- [ ] Concepts and constraints
- [ ] Ranges
- [ ] Memory layout fundamentals
- [ ] Stack vs. heap behavior
- [ ] Cache-awareness fundamentals
- [ ] Data-oriented design fundamentals
- [ ] Multithreading fundamentals
- [ ] `std::thread`
- [ ] `std::jthread`
- [ ] Mutexes and synchronization
- [ ] Basic atomics
- [ ] Task decomposition
- [ ] Performance measurement
- [ ] Profiling
- [ ] Benchmarking

### Completion Goal

Understand how C++ programs interact with memory, hardware, threads, and performance constraints.

---

## Stage 7 — Software Engineering Practice

- [ ] Larger CMake project structure
- [ ] Unit testing
- [ ] Sanitizers
- [ ] Debugger workflow
- [ ] Logging architecture
- [ ] Configuration files
- [ ] Serialization
- [ ] Save/load versioning
- [ ] Git branching workflow
- [ ] Pull-request workflow
- [ ] Basic CI
- [ ] Refactoring larger codebases
- [ ] Module/interface boundaries
- [ ] Dependency management fundamentals

### Completion Goal

Be able to maintain and evolve a growing C++ codebase rather than only write isolated programs.

---

## Stage 8 — Simulation Engine Prototype

- [ ] Define world state
- [ ] Implement deterministic simulation ticks
- [ ] Implement entities and NPCs
- [ ] Implement resources and consumption
- [ ] Implement NPC needs and actions
- [ ] Implement environmental changes
- [ ] Implement event systems
- [ ] Implement world-state persistence
- [ ] Add deterministic simulation tests
- [ ] Profile simulation performance
- [ ] Separate engine logic from application logic
- [ ] Establish clear module boundaries
- [ ] Prototype large-scale NPC updates
- [ ] Document architecture decisions

### Completion Goal

Build a simulation-engine prototype that can serve as a technical bridge to the future Living World Engine repository.

---

# Track B — Coding Test and Algorithms

Coding-test practice is maintained separately under:

```text
coding_test/
```

The purpose is to develop algorithm-selection ability, complexity awareness, and implementation speed.

Problems are organized by source type.

```text
coding_test/
├── README.md
├── books/
│   └── programmers/
│       ├── README.md
│       └── 01_array/
└── platforms/
```

Every solved problem keeps its `.cpp` source file.

A separate problem note is created only when the problem has meaningful review value.

---

# Coding Test Roadmap

## CT Stage 1 — Fundamentals

- [ ] Arrays
- [ ] Strings
- [ ] Sorting
- [ ] Basic simulation
- [ ] Basic implementation problems
- [ ] Time-complexity fundamentals
- [ ] Space-complexity fundamentals

### Completion Goal

Read problem constraints and choose a solution whose complexity is clearly safe.

---

## CT Stage 2 — Core Data Structures

- [ ] Stack
- [ ] Queue
- [ ] Deque
- [ ] Hash table
- [ ] Set
- [ ] Heap
- [ ] Priority queue

### Completion Goal

Recognize common data-structure patterns and implement them using the C++ standard library.

---

## CT Stage 3 — Search, Trees, and Graph Foundations

- [ ] Binary search
- [ ] Recursion
- [ ] DFS
- [ ] BFS
- [ ] Trees
- [ ] Graph representation
- [ ] Graph traversal
- [ ] Shortest-path fundamentals

### Completion Goal

Translate state-space and graph problems into appropriate traversal algorithms.

---

## CT Stage 4 — Algorithmic Techniques

- [ ] Greedy algorithms
- [ ] Divide and conquer
- [ ] Backtracking
- [ ] Dynamic programming
- [ ] Prefix sums
- [ ] Two pointers
- [ ] Sliding window
- [ ] Union-Find
- [ ] Topological sorting

### Completion Goal

Recognize recurring algorithmic patterns rather than treating every problem as entirely new.

---

## CT Stage 5 — Mixed and Timed Problem Solving

- [ ] Mixed-topic problems
- [ ] Solve without hints
- [ ] Complexity-first solution design
- [ ] Compare multiple approaches
- [ ] Timed problem solving
- [ ] Review failed approaches
- [ ] Re-solve selected problems
- [ ] Build reusable problem-solving patterns

### Completion Goal

Solve unfamiliar problems under realistic coding-test constraints with minimal external guidance.

---

# Track C — Mini Projects and Simulation Practice

Mini projects combine the Modern C++ and Coding Test tracks.

Possible projects include:

- resource calculators,
- file-processing tools,
- character systems,
- NPC behavior simulations,
- grid-based world simulations,
- economy simulations,
- event systems,
- and simplified Living World Engine components.

The goal is to move from:

```text
syntax
→ algorithm
→ program structure
→ simulation architecture
```

---

# Study Material

## Modern C++

- Main book: *Modern C++: Learn Only What You Need* (*필요한 것만 골라 배우는 모던 C++*)
- Supplementary material: *Do it! C++ Complete Guide* (*Do it! C++ 완전 정복*)

## Environment

- Language standard: C++20
- Compiler: Apple Clang
- Development environment: macOS and Visual Studio Code
- Shell: zsh
- Version control: Git and GitHub

---

# Repository Structure

```text
cpp20_practice/
├── README.md
├── .gitignore
│
├── basics/
├── classes/
├── stl/
├── modern_cpp/
│   ├── README.md
│   └── day_14/
│       └── README.md
│
├── coding_test/
│   ├── README.md
│   ├── books/
│   │   └── programmers/
│   │       ├── README.md
│   │       └── 01_array/
│   └── platforms/
│
├── mini_projects/
└── ...
```

The structure will be expanded gradually as each study area grows.

---

# Learning Process

## Modern C++ Track

```text
Read or watch the relevant material
→ Test syntax and behavior in practice.cpp
→ Modify examples without copying them exactly
→ Complete selected exercises
→ Build a small program in main.cpp when appropriate
→ Compile and run
→ Fix warnings and logic errors
→ Record important findings
→ Commit and push
```

A topic is considered complete only when I can modify the code, predict the result, and explain the main structure without copying the original example.

## Coding-Test Track

```text
Read the problem
→ Identify input/output and constraints
→ Estimate acceptable complexity
→ Choose a data structure or algorithm
→ Implement the solution
→ Check correctness
→ Check time and space complexity
→ Save the source code
→ Update the progress README
→ Add a separate note only when it has review value
```

The purpose of coding-test practice is problem solving, not excessive documentation.

---

# Current Progress

## Modern C++

**Current stage:** Stage 4 — Modern C++ Foundations (introductory)

**Current topic:** Day 15 — Templates, namespaces, and argument-dependent lookup

**Current exercise:** Template error handling, mixed types, abbreviated templates, namespace lookup, and ADL

**Next milestone:** Continue the next modern C++ language topic and reinforce function lookup rules through practice.

Completed introductory topics include:

- compilation and execution,
- variables and initialization,
- operators and expressions,
- conditions and loops,
- functions,
- strings,
- references,
- basic pointers and dynamic memory,
- exception handling,
- classes and constructors,
- const member functions,
- operator overloading,
- comparison operators,
- RAII and smart-pointer review,
- move assignment,
- `std::initializer_list` constructor practice,
- basic function templates,
- function-template parameter deduction,
- forwarding references and reference collapsing,
- template instantiation errors and mixed-type deduction,
- uniform initialization and return type deduction,
- C++20 abbreviated function templates,
- namespaces, aliases, and name lookup,
- argument-dependent lookup (ADL),
- perfect forwarding with `std::forward`,
- and ordinary rvalue references.

## Coding Test

**Current source:** Programmers coding-test book

**Current chapter:** Array

**Problems solved:** 1

**Latest problem:** 배열 정렬하기

**Latest source file:**

```text
coding_test/books/programmers/01_array/p01_sort_array.cpp
```

---

# Study Records

Detailed study logs are split by learning stage.

### Basics

- Day 01 — First C++20 Practice Session
- Day 02 — File, Stream, and Filesystem Practice
- Day 03 — Smart Pointer and Dynamic Memory Introduction
- Day 04 — Pointer and Dynamic Memory Review
- Day 05 — NPC Daily Life Simulation
- Day 06 — C++ Fundamentals Review and Exercises
- Day 07 — Exception Handling
- Day 08 — Members and Constructors
- Day 09 — User-Defined Literals and Object Creation
- Day 10 — RAII, shared_ptr, and Custom Deleters
- Day 11 — Member Access and Reference-Qualified Operators
- Day 12 — Operator Overloading Design
- Day 13 — Polynomial and Rational Practice

### Modern C++

- [Day 14 — Function Templates and Forwarding References](modern_cpp/day_14/)
- [Day 15 — Templates, Namespaces, and ADL](modern_cpp/day_15/)

Coding-test progress is maintained separately in:

```text
coding_test/books/programmers/README.md
```

---

# Long-Term Direction

The repository is intended to connect several levels of practice:

```text
Modern C++ language study
          +
Data structures and algorithms
          ↓
Software engineering practice
          ↓
Applied simulations
          ↓
Simulation Engine Prototype
          ↓
Living World Engine
```

The current repository contains learning exercises, experiments, coding-test solutions, and small applied programs.

The future Living World Engine repository will contain reviewed, understood, tested, and progressively optimized systems built from these foundations.
