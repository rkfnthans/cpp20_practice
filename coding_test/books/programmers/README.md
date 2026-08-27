# Programmers Coding Test Book Practice

This directory contains C++ solutions to problems from the current Programmers coding-test book.

Problems are organized by the book's chapter/topic order.

## Structure

```text
programmers/
├── README.md
├── 01_array/
│   └── p01_sort_array.cpp
├── 02_stack/
├── 03_queue/
└── ...
```

Chapter folder names should preserve the order and topic structure of the book.

Examples:

```text
01_array/
02_stack/
03_queue/
```

If one chapter combines multiple topics, use a combined folder name such as:

```text
02_stack_queue/
```

## Progress

| No. | Date | Chapter | Problem | Topic | Status |
|---:|---|---|---|---|---|
| 1 | 2026-08-27 | Array | 배열 정렬하기 | Array / Sorting | Solved |

## Status

- `Solved` — solved independently and understood
- `Hint` — solved after receiving a hint
- `Review` — solved, but worth reviewing
- `Retry` — not yet solved independently or should be attempted again

## File Naming

Problem source files use:

```text
pNN_short_name.cpp
```

Example:

```text
p01_sort_array.cpp
```

Use concise English `snake_case` names.

## Note Policy

Every problem keeps its `.cpp` source file.

A separate problem note is **not** required for every problem.

Create a matching `.md` file only when:

- a new algorithm or data structure was learned,
- a hint was needed,
- the time-complexity judgment was wrong,
- there were multiple incorrect attempts,
- another solution is worth comparing,
- or the problem should be reviewed later.

Example:

```text
p05_some_problem.cpp
p05_some_problem.md
```

For straightforward problems that are understood and solved independently:

```text
.cpp
+ one progress row in this README
```

is enough.

## Current Progress

**Current chapter:** Array

**Latest problem:** 배열 정렬하기

**Latest file:**

```text
01_array/p01_sort_array.cpp
```
