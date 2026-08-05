# Day 04 — Pointers, Dynamic Memory, and Function Parameters

## Purpose

Review pointers and dynamic memory in more detail.

## Reason

Day 03 introduced raw pointers, dynamic arrays, and smart pointers too quickly.

## Material

**Do it! C++ Complete Guide**

## Learning Goals

- Understand addresses and pointer variables
- Distinguish `&` and `*`
- Understand the relationship between arrays and pointers
- Practice `new`, `delete`, `new[]`, and `delete[]`
- Recognize `nullptr`, memory leaks, and invalid memory access
- Understand why smart pointers are useful

---

## 1. Basic Pointer Variables

- A pointer stores the memory address of another variable.
- `char*`, `int*`, and `double*` store addresses of matching object types.
- `&value` obtains the address of a variable.
- `*pointer` accesses the value stored at the pointed-to address.
- Assigning through `*pointer` changes the original variable.
- A pointer can be changed to point to another object without copying that object.

### NPC Application

- An NPC pointer can store the memory address of an NPC object.
- The pointer can later be changed to point to another NPC.
- A memory address is different from an NPC's world position coordinates.
- `target->health` is equivalent to `(*target).health`.

### Pointer Safety

- `nullptr` represents a pointer that points to no object.
- Dereferencing `nullptr` causes invalid memory access.
- A pointer becomes dangling when the pointed-to object no longer exists.
- `std::cout` may interpret `char*` as a character string.

---

## 2. Multiple Pointers

- `int**` stores the address of an `int*` pointer.
- It can be used when a function must change the original pointer.
- This topic needs more practice through functions and NPC relationships.

---

## 3. Arrays and Pointers

- An array name usually converts to the address of its first element.
- `array` and a pointer initialized with `array` point to the same first element.
- `sizeof(array)` returns the total array size.
- `sizeof(pointer)` returns only the pointer size.
- An array name cannot be reassigned, but a pointer can point elsewhere.

---

## 4. Dynamic Memory with `new`

- `new int` creates an `int` object in dynamic memory.
- `new int{100}` creates the object and initializes it to `100`.
- The pointer stores the address returned by `new`, not the value `100`.
- `*pointer` accesses the dynamically allocated value.
- Memory created with `new` must be released with `delete`.
- After deletion, the pointer can be set to `nullptr`.

---

## 5. Dynamic Arrays

- `new int[count]` or `new string[count]` creates an array whose size is decided at runtime.
- The pointer stores the address of the first element.
- `array[i]` and `*(array + i)` access the same element.
- Memory created with `new[]` must be released with `delete[]`.
- `std::vector` is usually preferred in modern C++.

---

## 6. Function Arguments and Return Values

- Function arguments are copied into ordinary value parameters.
- Changing copied parameters does not affect the caller's original variables.
- `return` sends a calculated result back to the caller.

---

## 7. Modifying Original Values with Pointers

- Without a pointer, a function changes only its local copy.
- Passing an address allows the function to access the original variable.
- `*pointer` can read and modify the original value.

---

## 8. Passing Arrays to Functions

- An array parameter receives the address of the first element.
- The array count must be passed separately.
- `array[i]` accesses each element through the received address.
- Integer division removes the decimal part.

---

## 9. Passing Struct Arrays to Functions

- `Person*` receives the address of the first `Person` object.
- `pointer[i]` accesses each object in the array.
- `pointer[i].member` accesses a member of each object.
- The array count must be passed separately.

---

## 10. Static Local Variables

- A normal local variable is recreated on every function call.
- A static local variable is initialized only once.
- A static local variable keeps its value between calls.
- Both normal and static local variables are accessible only inside the function.

---

## 11. Passing Variables by Reference

- `int&` creates an alias for the original variable.
- Changes through the reference affect the original value.
- Without references, only copied values would be changed.
- References provide simpler syntax than pointer parameters when null is not needed.

---

## Review Notes

- Revisit multiple pointers later through practical exercises.
- Prefer `std::vector` over manually managed dynamic arrays in modern C++.
- Prefer references when a function must modify an existing value and nullability is not required.
- Continue the learning sequence instead of stopping until every pointer detail is fully mastered.

- PRACTICE:
  - implemented a small character example with guided assistance
  - used pointers or references to modify character state
  - compiled and tested the program
  - understood the overall structure, but some syntax still requires review