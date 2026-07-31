#include <cassert>



/*
[DAY NOTES]
- ERROR: executable not found
  FIX: compile first, then run with ./practice

- OUTPUT: 9% appeared
  FIX: add '\n'; % was the zsh prompt

- NOTE: brace initialization can initialize variables.

- WARNING: `l2` was declared but not used.
  FIX: print or otherwise use the variable.

- `switch` requires declared and initialized variables.
- `[[fallthrough]]` intentionally continues into the next case.
- Division requires checking whether `y` is zero.

- `do-while` executes the body at least once.
- `eps /= 2.0` is equivalent to `eps = eps / 2.0`.

- Approximated `e^x` using the Taylor series.
- `xn` stores x^n, `fac` stores n!, and `exp_x` stores the accumulated sum.
- The approximation becomes more accurate as more terms are added.

- `int&` passes an argument by reference.
- Modifying `x` inside `increment()` also modifies the original variable.

- `argc` stores the number of command-line arguments.
- `argv[0]` is the program name; user arguments start at `argv[1]`.
- Run example: `./practice apple 123`
- Command-line arguments are written after `./practice`.
- `argv[0]` is the program name; actual user arguments start at `argv[1]`.


*/

