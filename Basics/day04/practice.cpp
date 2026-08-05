#include <iostream>
using namespace std;

void swap(int &ref_a, int &ref_b)
{
    cout<<"[swap fuc] before swap, ref_a: "<<ref_a<<"ref_b: "<<ref_b<<endl;

    int temp =ref_a;
    ref_a=ref_b;
    ref_b=temp;

    cout<<"[swap func] after swap, ref_a: "<<ref_a<<"ref_b: "<<ref_b<<endl;

}

int main()
{
    int a=5;
    int b=10;

    cout<<"[main] before swap, a: "<<a<<"b: "<<b<<endl<<endl;

    swap(a,b);

    cout<<endl<<"[main] after swap, a: "<<a<<"b: "<<b<<endl;

    return 0;

}

/*
[DAY 04 NOTES]

- PURPOSE: Review pointers and dynamic memory in more detail
- REASON: Day 03 introduced raw pointers, dynamic arrays, and smart pointers too quickly
- MATERIAL: Do it! C++ Complete Guide

- LEARNING GOALS:
  - understand addresses and pointer variables
  - distinguish & and *
  - understand the relationship between arrays and pointers
  - practice new, delete, new[], and delete[]
  - recognize nullptr, memory leaks, and invalid memory access
  - understand why smart pointers are useful

1)
- TOPIC: Basic pointer variables
- NOTE: A pointer stores the memory address of another variable
- NOTE: char* stores the address of a char variable
- NOTE: int* stores the address of an int variable
- NOTE: double* stores the address of a double variable
- NOTE: The pointer type should match the type of the pointed-to variable

- TOPIC: Address operator &
- NOTE: &value obtains the memory address of value
- NOTE: char_pointer_value = &char_value makes the pointer point to char_value
- NOTE: int_pointer_value = &int_value makes the pointer point to int_value
- NOTE: double_pointer_value = &double_value makes the pointer point to double_value

- TOPIC: Dereference operator *
- NOTE: *pointer accesses the value stored at the pointed-to address
- NOTE: *char_pointer_value and char_value access the same char object
- NOTE: *int_pointer_value and int_value access the same int object
- NOTE: *double_pointer_value and double_value access the same double object
- NOTE: Assigning through *pointer changes the original variable

- TOPIC: Direct access versus pointer access
- NOTE: value accesses a variable directly
- NOTE: *pointer accesses the same variable indirectly through its address
- NOTE: The output may be the same, but the access path is different

- TOPIC: Changing the pointed-to object
- NOTE: A pointer can be changed to store the address of another object
- NOTE: Changing the pointer does not copy the original object
- NOTE: Only the address stored in the pointer changes

- TOPIC: Applying pointers to NPC objects
- NOTE: An NPC pointer can store the memory address of an NPC object
- NOTE: The pointer can be changed to point to a different NPC
- NOTE: A memory address is different from an NPC's world position coordinates
- NOTE: A pointer can access and modify the original NPC without copying it
- NOTE: target->health is equivalent to (*target).health

- TOPIC: Pointer safety
- NOTE: nullptr represents a pointer that currently points to no object
- RISK: Dereferencing nullptr causes invalid memory access
- RISK: A pointer becomes dangling if the pointed-to object is destroyed
- NOTE: Check that a pointer is valid before dereferencing it

- WARNING: Pointer variables that are declared but not used produce unused-variable warnings
- FIX: Read the pointed-to value, modify it, or print the pointer information
- CAUTION: std::cout may treat char* as a character string
 
2)
- TOPIC: Multiple pointers
- NOTE: int** stores the address of an int* pointer
- NOTE: It can be used when a function must change the original pointer
- REVIEW: Practice this later with functions and object relationships

3)
- TOPIC: Arrays and pointers
- NOTE: An array name usually converts to the address of its first element
- NOTE: array and pointer_array point to the same first element
- NOTE: sizeof(array) returns the total array size
- NOTE: sizeof(pointer_array) returns only the pointer size
- NOTE: An array name cannot point elsewhere, but a pointer can

4)
- TOPIC: Dynamic memory with new
- NOTE: new int creates an int object in dynamic memory
- NOTE: new int{100} creates the object and initializes it to 100
- NOTE: A pointer stores the address returned by new, not the value 100
- NOTE: Use *pointer to access the stored value
- NOTE: Release memory with delete and then set the pointer to nullptr

5)
- TOPIC: Dynamic string arrays
- NOTE: new string[count] creates an array whose size is decided at runtime
- NOTE: bread stores the address of the first array element
- NOTE: bread[i] and *(bread + i) access the same element
- NOTE: Use delete[] to release memory created with new[]
- NOTE: std::vector is usually preferred in modern C++

6)
- TOPIC: Function arguments and return values
- NOTE: add(2, 3) passes two values to the function
- NOTE: x and y receive copies of the arguments
- NOTE: return sends the calculated result back to the caller

7)
- TOPIC: Modifying the original value with a pointer
- NOTE: Without a pointer, the function receives a copy of the value
- NOTE: Changing the copied value affects only the function's local variable
- NOTE: Passing the address allows the function to modify the original variable
- NOTE: *pointer accesses and changes the original value

8)
- TOPIC: Passing an array to a function
- NOTE: An array parameter receives the address of the first element
- NOTE: The array size must be passed separately
- NOTE: array[i] accesses each element through the received address
- NOTE: Integer division removes the decimal part

9)
- TOPIC: Passing a struct array to a function
- NOTE: Person* receives the address of the first struct element
- NOTE: pointer[i] accesses each Person object in the array
- NOTE: pointer[i].member accesses a member of each struct
- NOTE: The array count must be passed separately

10)
- TOPIC: Static local variables
- NOTE: A normal local variable is recreated on every function call
- NOTE: A static local variable is initialized only once
- NOTE: A static local variable keeps its value between function calls
- NOTE: Both variables can only be accessed inside the function
  

11)
- TOPIC: Passing variables by reference
- NOTE: int& creates an alias for the original variable
- NOTE: Changes through a reference affect the original value
- NOTE: Without references, only copied values would be swapped
- NOTE: References provide simpler syntax than pointer parameters
*/