# Day 05 — NPC Daily Life Simulation

## Date

2026-08-07

## Topic

Building a small interactive NPC daily-life simulation by combining structs, functions, references, conditions, loops, Boolean return values, and user input.

## Purpose

The purpose of this exercise was to stop practicing isolated syntax and build one complete program using the C++ fundamentals studied so far.

The simulation controls one NPC for seven days. During each day, the user chooses one action, the NPC's state changes, time passes, and the day advances only when a valid command is entered.

## NPC Data

The NPC is represented with a structure containing four fields:

```cpp
struct NPC
{
    std::string name;
    int hunger;
    int energy;
    int food;
};
```

The variables represent:

- `name`: NPC name,
- `hunger`: current hunger level,
- `energy`: current energy level,
- `food`: number of food units owned by the NPC.

## Functions

### `pass_time(NPC& npc)`

Represents the passage of one day.

- increases hunger by 15,
- decreases energy by 10,
- limits hunger to a maximum of 100,
- and prevents energy from becoming negative.

### `eat(NPC& npc)`

Consumes one food unit when food is available.

- decreases food by 1,
- decreases hunger by up to 40,
- prevents hunger from becoming negative,
- and prints a message when no food is available.

### `rest(NPC& npc)`

Recovers energy.

- adds 50 energy when energy is 50 or lower,
- sets energy to 100 when adding 50 would exceed the limit,
- and prints a message when the NPC already has full energy.

### `work(NPC& npc)`

Converts energy into food.

- requires at least 40 energy,
- decreases energy by 40,
- increases food by 2,
- and prints an explanation when the NPC does not have enough energy.

### `choose_action(NPC& npc)`

Reads a command from the user and calls the corresponding action function.

Supported commands:

```text
eat
rest
work
```

The function returns:

- `true` when the command is recognized,
- `false` when the command is unknown.

### `print_status(NPC& npc)`

Displays the NPC's current:

- name,
- hunger,
- energy,
- and food.

## Main Simulation Flow

The program creates the NPC with an initial state:

```cpp
NPC npc{"Jack", 70, 50, 2};
```

The simulation runs for seven valid days.

```text
Display current day
→ Print NPC status
→ Read an action command
→ Execute eat, rest, or work
→ Reject unknown commands
→ Pass time only after a valid command
→ Advance the day
→ Print the final status after Day 7
```

## Invalid Command Handling

The main loop stores the result of `choose_action()`:

```cpp
bool action_completed{choose_action(npc)};
```

When the result is `false`, `continue` restarts the loop without calling `pass_time()` or increasing the day.

```cpp
if (!action_completed)
{
    continue;
}
```

This prevents an unknown command from consuming a simulation day.

## Compilation

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic main.cpp -o main
```

## Execution

```bash
./main
```

## Example Interaction

```text
=======================
========day 1=========
========================
NAME : Jack
Hunger : 70
Energy : 50
Food : 2
Choose action: eat
Jack eats food.
```

When an invalid command is entered:

```text
Choose action: sleep
Unknown action.
Choose again.
```

The same day is displayed again because time does not pass and the day counter does not increase.

## What I Implemented

- Created an `NPC` structure.
- Passed the original NPC to functions using `NPC&`.
- Separated each action into its own function.
- Added minimum and maximum limits for status values.
- Used user input to select actions.
- Changed `choose_action()` to return `bool`.
- Used `continue` to repeat the current day after an invalid command.
- Created a seven-day simulation loop.
- Printed the final NPC state after the simulation.

## Mistakes and Corrections

### Mistake 1 — Missing Semicolon After the Structure

A structure definition must end with a semicolon.

```cpp
struct NPC
{
    // members
};
```

### Mistake 2 — Returning a Value From a `void` Function

The first version of `choose_action()` was declared as `void`, but invalid input needed to communicate failure to `main()`.

### Correction

The return type was changed to `bool`.

```cpp
bool choose_action(NPC& npc)
```

The function now returns `true` for a recognized command and `false` for an unknown command.

### Mistake 3 — Unknown Commands Could Advance Time

If the program always called `pass_time()` after input, an invalid command would still consume a day.

### Correction

The return value of `choose_action()` is checked before time passes.

```cpp
if (!action_completed)
{
    continue;
}
```

### Mistake 4 — Hunger Could Become Negative

Subtracting 40 directly from a hunger value below 40 would produce a negative number.

### Correction

The program checks the hunger value before subtraction and sets it to zero when necessary.

### Mistake 5 — Status Values Could Exceed Their Intended Range

Time passage or recovery could move hunger or energy outside the range from 0 to 100.

### Correction

The functions include boundary checks that limit hunger and energy.

## C or Python Comparison

- C++ uses explicit reference syntax such as `NPC&` to modify the original object through a function parameter.
- A C++ function must declare its return type, so `bool choose_action()` clearly communicates whether input was accepted.
- Python commonly uses `while` loops or exceptions for input validation, while this program uses a Boolean return value and `continue`.
- C++ requires explicit structure field types, while Python classes or dictionaries can store values more dynamically.

## What I Can Explain Now

- Why `NPC&` modifies the original NPC instead of a copy
- How a structure groups related state variables
- Why each action is separated into its own function
- How `if`, `else if`, and `else` select an action
- How `bool` communicates success or failure to `main()`
- Why `continue` prevents the day from advancing after invalid input
- How the `for` loop advances manually with `++day`
- Why hunger and energy need boundary checks
- How the final state reflects all actions and time changes during the simulation

## Current Design Notes

A recognized command counts as the day's action even when the action cannot be completed, such as attempting to work without enough energy or attempting to eat without food. This is an acceptable rule for the current version because the command itself was valid.

The program currently processes the selected action before calling `pass_time()`. Therefore, the daily order is:

```text
current status
→ selected action
→ time passage
→ next day
```

## Possible Later Improvements

These improvements are intentionally postponed until after the current fundamentals review:

- change `print_status(NPC& npc)` to `print_status(const NPC& npc)`,
- add a quit command,
- let the user enter the NPC's initial name and values,
- store multiple NPCs in `std::vector`,
- move repeated boundary checks into a helper function,
- replace string commands with an `enum class`,
- rebuild the program using an `NPC` class,
- and separate the program into `NPC.h`, `NPC.cpp`, and `main.cpp`.

## Next Topic

Begin object-oriented C++ lectures and rebuild this simulation using:

- an `NPC` class,
- private data members,
- a constructor,
- member functions,
- `const` member functions,
- and separate header and source files.
