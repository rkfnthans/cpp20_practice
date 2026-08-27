# Coding Test Practice

This directory contains coding-test practice written primarily in C++.

The goal is to build problem-solving ability alongside Modern C++ study while keeping coding-test work separate from the main C++ language-learning repository.

## Organization

Problems are organized by **source type**, not by study day.

```text
coding_test/
├── README.md
├── books/
│   ├── programmers/
│   │   ├── README.md
│   │   ├── 01_array/
│   │   ├── 02_stack/
│   │   ├── 03_queue/
│   │   └── ...
│   └── algorithm_problem_solving_strategies/
│       └── ...
└── platforms/
    ├── baekjoon/
    ├── programmers/
    └── ...
```

## Folder Rules

### `books/`

Problems studied from coding-test or algorithm books are stored here.

Each book gets its own directory.

Current book:

```text
books/programmers/
```

Future books are added as sibling directories rather than mixed together.

Example:

```text
books/
├── programmers/
└── algorithm_problem_solving_strategies/
```

### `platforms/`

Problems solved directly from online judges or coding-test platforms are stored separately from book exercises.

Examples:

```text
platforms/
├── baekjoon/
└── programmers/
```

A problem from a book remains under `books/` even when the original problem also exists on an online platform.

## Naming Rules

Book chapter directories preserve the book order and use topic-based names.

Examples:

```text
01_array/
02_stack/
03_queue/
```

If the book combines topics into one chapter, use a combined name such as:

```text
02_stack_queue/
```

Problem source files use:

```text
pNN_short_name.cpp
```

Example:

```text
p01_sort_array.cpp
```

Use concise English `snake_case` names.

## Problem Record Policy

Every solved problem keeps its source code.

Progress is recorded in the README for the relevant book or platform.

A separate problem note (`.md`) is created only when the problem has meaningful review value, such as:

- a new algorithm or data structure was learned,
- a hint was required,
- the time-complexity judgment was wrong,
- multiple incorrect attempts occurred,
- another solution is worth comparing,
- or the problem should be solved again later.

Simple problems do not need a separate note file.

## Study Principle

The purpose of the repository is problem solving, not excessive documentation.

```text
Solve
→ Check correctness
→ Check complexity
→ Save source code
→ Update progress
→ Add a note only when it has review value
```
