# Programmers Coding Test Book Practice

This directory contains C++ solutions to problems from the current Programmers coding-test book.

Problems are organized by the book's chapter/topic order.

## Structure

```text
programmers/
├── README.md
├── 01_array/
│   ├── p01_sort_array.cpp
│   └── p02_array_control.cpp
├── 02_stack/
├── 03_queue/
└── ...
```

Chapter folder names preserve the order and topic structure of the book.

## Progress

| No. | Date | Chapter | Problem | Topic | Status |
|---:|---|---|---|---|---|
| 1 | 2026-08-27 | Array | 배열 정렬하기 | Array / Sorting | Solved |
| 2 | 2026-08-28 | Array | 배열 제어하기 | Sorting / Unique / Erase | Hint |

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

Examples:

```text
p01_sort_array.cpp
p02_array_control.cpp
```

Use concise English `snake_case` names.

## Note Policy

Every problem keeps its `.cpp` source file.

A separate problem note is **not** required for every problem.

Create a matching `.md` file when:

- a new algorithm or data structure was learned,
- a hint was needed,
- the time-complexity judgment was wrong,
- there were multiple incorrect attempts,
- another solution is worth comparing,
- or the problem should be reviewed later.

For straightforward problems that are understood and solved independently:

```text
.cpp
+ one progress row in this README
```

is enough.

## Current Progress

**Current chapter:** Array

**Problems completed:** 2

**Latest problem:** 배열 제어하기

**Latest file:**

```text
01_array/p02_array_control.cpp
```

### Concepts encountered so far

- `std::vector`
- `std::sort`
- custom sort order
- `std::greater<int>`
- comparator functions
- `std::unique`
- `vector::erase`
- basic time-complexity reasoning
- basic space-complexity reasoning
