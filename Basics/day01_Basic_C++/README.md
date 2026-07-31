# Day 01 — First C++20 Program

## Date

2026-07-29

## Topic

Compiling and running a basic C++20 program.

## What I Studied

- The basic structure of a C++ program
- 

## Code

The main exercise is available in [`main.cp# Day 01 — First C++20 Practice Session

## Date

2026-07-29

## Topic

Compiling and running C++20 programs while practicing basic syntax, control flow, numerical computation, references, and command-line arguments.

## What I Studied

- The C++ compile-and-run workflow
- Brace initialization
- Compiler warnings for unused variables
- `switch` statements and `[[fallthrough]]`
- Division-by-zero checks
- `do-while` loops
- Compound assignment with `eps /= 2.0`
- Taylor-series approximation of `e^x`
- Pass-by-reference with `int&`
- Command-line arguments with `argc` and `argv`

## Code

The exercises were written one at a time in a temporary `practice.cpp` file.

After each example was compiled and tested, the code was changed or removed to make room for the next exercise. Because the file was repeatedly reused during the session, no final `practice.cpp` or `main.cpp` file was preserved for Day 01.

The main value of this session is the record of the errors, corrections, and concepts documented below.

## Compilation

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic practice.cpp -o practice
```

## Execution

```bash
./practice
```

Command-line argument example:

```bash
./practice apple 123
```

## What I Changed

- Added a newline after output so the zsh prompt did not appear on the same line.
- Used or removed variables that caused unused-variable warnings.
- Declared and initialized variables before using them in `switch` statements.
- Added `[[fallthrough]]` when continuation into the next `case` was intentional.
- Checked whether the denominator was zero before division.
- Replaced `eps = eps / 2.0` with `eps /= 2.0`.
- Used a reference parameter to modify the original argument.
- Tested command-line input with `argc` and `argv`.

## Mistakes and Corrections

### Mistake 1 — Executable Not Found

I tried to run the program before creating the executable.

### Correction

I compiled the source file first and then ran the generated executable.

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic practice.cpp -o practice
./practice
```

### Mistake 2 — Output Appeared as `9%`

The program printed `9` without a trailing newline, so the zsh prompt character `%` appeared immediately after the output.

### Correction

I added `\n` to the output statement.

```cpp
std::cout << value << '\n';
```

The `%` character came from zsh, not from the C++ program.

### Mistake 3 — Unused Variable Warning

A variable named `l2` was declared but never used.

### Correction

I used the variable in the program or removed it when it was unnecessary. This showed why compiler warnings should be reviewed rather than ignored.

### Mistake 4 — Incorrect `switch` Usage

The variable used by the `switch` statement was not properly declared or initialized, and the intended fallthrough behavior was not clearly expressed.

### Correction

I initialized the controlling variable and used `[[fallthrough]]` only when continuing into the next `case` was intentional.

```cpp
int option{2};

switch (option) {
case 1:
    break;
case 2:
    [[fallthrough]];
case 3:
    break;
default:
    break;
}
```

### Mistake 5 — Possible Division by Zero

A division operation could receive zero as the denominator.

### Correction

I checked the denominator before performing the calculation.

```cpp
if (y != 0) {
    std::cout << x / y << '\n';
}
```

### Mistake 6 — Misunderstanding the `do-while` Loop

I needed to confirm why the loop body executed before the condition was checked.

### Correction

I learned that a `do-while` loop always executes its body at least once because the condition is evaluated after the body.

### Mistake 7 — Updating a Value Repeatedly

I originally wrote a full assignment when repeatedly halving `eps`.

### Correction

I used the compound assignment operator:

```cpp
eps /= 2.0;
```

This is equivalent to:

```cpp
eps = eps / 2.0;
```

## C or Python Comparison

- C++ source code must normally be compiled before execution, while Python code is commonly executed by an interpreter.
- C++ references such as `int&` provide explicit aliasing to an existing object. Python variables refer to objects, but Python does not use the same reference-parameter syntax.
- C++ exposes command-line arguments through `argc` and `argv`, while Python commonly uses `sys.argv` or `argparse`.
- C++ compiler warnings can reveal issues before execution, while many Python errors are discovered at runtime.
- C++ `switch` statements require integral or enumeration-like controlling values, while Python commonly uses `if`/`elif` or structural pattern matching.

## What I Can Explain Now

- Why a C++ source file must be compiled before its executable can run
- Why the zsh prompt may appear directly after program output
- How brace initialization works
- Why unused-variable warnings occur
- How `switch` and `[[fallthrough]]` work
- Why division requires a zero check
- Why a `do-while` loop executes at least once
- Why `eps /= 2.0` is equivalent to `eps = eps / 2.0`
- How a Taylor series can approximate `e^x`
- How `xn`, `fac`, and `exp_x` can represent `x^n`, `n!`, and the accumulated approximation
- How an `int&` parameter can modify the original variable
- How `argc` and `argv` store command-line arguments

## Next Topic

Variables, initialization, types, and basic expressions in greater detail.
p`](main.cpp).

## Compilation

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic main.cpp -o main
```

## Execution

```bash
./main
```

## What I Changed

-

## Mistakes and Corrections

### Mistake

Record an error or misunderstanding here.

### Correction

Explain how the problem was corrected and what caused it.

## C or Python Comparison

Write one or two differences noticed while studying the topic.

## What I Can Explain Now



## Next Topic

Variables and initialization.
