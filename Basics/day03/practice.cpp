#include <vector>
#include <cassert>

void vector_add
(
    const std::vector<float>& v1, const std::vector<float>& v2, std::vector<float>& s
)
{
    assert(v1.size() == v2.size());
    assert(v1.size() == s.size());
    for (unsigned i=0;i<v1.size();++i)
        s[i]=v1[i]+v2[i];
}




/*
[DAY NOTES]
- TOPIC: Element-wise array calculation
- NOTE: Array size is inferred from initializer values
- NOTE: Each loop iteration calculates and prints one element
- NOTE: Use the f suffix for float literals


- TOPIC: Passing arrays to a function
- NOTE: vector_add() receives two input arrays and one output array
- NOTE: const prevents v1 and v2 from being modified inside the function
- NOTE: The array size must be passed separately
- RISK: Passing an incorrect size can cause out-of-bounds access

- TOPIC: Dynamic arrays
- NOTE: new double[size] allocates a double array in dynamic memory
- NOTE: x, y, and sum store the addresses of the allocated arrays
- NOTE: Use the same size variable for every array allocation
- FIX: Write new double[size] instead of new double[3] for sum

- TOPIC: Initializing array elements with a loop
- NOTE: x[i] = i + 2.0 creates the values 2, 3, and 4
- NOTE: y[i] = 4.0 - 2.0 * i creates the values 4, 2, and 0
- STYLE: Write x[i] and y[i] assignments as separate statements
- NOTE: A comma can separate expressions, but separate lines are easier to read

- TOPIC: Adding corresponding array elements
- NOTE: vector_add(size, x, y, sum) stores x[i] + y[i] in sum[i]
- RESULT: sum contains 6, 5, and 4

- TOPIC: Releasing dynamic memory
- NOTE: Memory created with new[] must be released with delete[]
- NOTE: new[] and delete[] must be used as a pair
- ERROR: delete x[] is invalid C++ syntax
- FIX: Write delete[] x
- RISK: Missing delete[] can cause a memory leak



- TOPIC: Managing dynamic memory with std::unique_ptr
- NOTE: std::unique_ptr<double> manages one dynamically allocated double
- NOTE: <double> specifies the type managed by the smart pointer
- NOTE: dp stores and manages the address of the allocated double
- NOTE: *dp accesses the value stored in the managed memory
- NOTE: *dp = 7 assigns 7 to the double managed by dp

- TOPIC: Automatic memory cleanup
- NOTE: std::unique_ptr automatically releases its managed memory
- NOTE: delete is not required when using std::unique_ptr
- NOTE: The memory is released when dp goes out of scope
- BENEFIT: Automatic cleanup helps prevent memory leaks

- TOPIC: The std namespace
- NOTE: unique_ptr belongs to the C++ standard library
- NOTE: Write std::unique_ptr because unique_ptr is inside namespace std
- NOTE: std::cout and std::endl also belong to namespace std
- NOTE: Built-in types such as int and double do not require std::

- TOPIC: Required headers
- ERROR: std::cout and std::endl were used without including <iostream>
- FIX: Add #include <iostream>
- NOTE: <memory> provides std::unique_ptr
- NOTE: <iostream> provides std::cout and std::endl

- MODERN C++:
  std::make_unique<double>(7.0) is generally preferred
  to directly writing new double


- TOPIC: Returning std::unique_ptr from a function
- NOTE: f() returns a std::unique_ptr<double>
- NOTE: The function creates a dynamically allocated double
- NOTE: The returned unique_ptr manages the allocated memory
- NOTE: Include <memory> when using std::unique_ptr

- TOPIC: Empty unique_ptr
- NOTE: std::unique_ptr<double> dp3 creates an empty smart pointer
- NOTE: A default-constructed unique_ptr initially contains nullptr
- NOTE: dp3 does not manage an object until it receives the result of f()

- TOPIC: Ownership transfer
- NOTE: dp3 = f() transfers ownership of the returned object to dp3
- NOTE: std::unique_ptr cannot be copied because ownership must remain unique
- NOTE: A temporary unique_ptr can transfer its ownership to another unique_ptr
- NOTE: The managed memory is released automatically when dp3 goes out of scope

- TOPIC: Accessing the managed value
- NOTE: *dp3 accesses the double managed by dp3
- RISK: Do not dereference an empty unique_ptr
- NOTE: Assign or initialize the managed value before reading it

- TOPIC: Program execution order
- NOTE: First, an empty dp3 is created
- NOTE: Next, f() creates and returns a unique_ptr
- NOTE: Then, dp3 receives ownership from the returned unique_ptr
- NOTE: A value is displayed only when an output statement is added
- NOTE: The current example transfers ownership but does not print anything

- MODERN C++:
  Prefer std::make_unique<double>() instead of directly using new double

- SIMPLIFIED FORM:
  auto dp3 = f();


- TOPIC: std::shared_ptr
- NOTE: std::shared_ptr allows multiple smart pointers to share ownership of one object
- NOTE: Include <memory> when using std::shared_ptr
- NOTE: Write std::shared_ptr because shared_ptr belongs to namespace std

- TOPIC: Shared ownership count
- NOTE: use_count() returns the number of shared_ptr objects that currently own the same object
- ERROR: use_cout() is invalid
- FIX: Write use_count()

- NOTE: p1 creates and owns one dynamically allocated double
- NOTE: p3 = p1 makes p3 share ownership of the same double
- RESULT: p1 and p3 share the object, so p3.use_count() is 2

- NOTE: p2 manages a different double and does not share ownership with p1 or p3
- NOTE: Creating separate shared_ptr objects with separate new expressions creates separate objects

- TOPIC: Returning shared_ptr from a function
- NOTE: f() returns a shared_ptr that manages the same object as p1 and p3
- NOTE: The returned shared_ptr is stored in p inside main()
- NOTE: Local shared_ptr variables are destroyed when f() ends
- RESULT: After f() ends, only p remains as an owner, so p.use_count() is 1

- TOPIC: Automatic memory cleanup
- NOTE: The managed object is deleted automatically when the last shared_ptr owner is destroyed
- NOTE: Manual delete is not required

- MODERN C++:
  Prefer std::make_shared<double>() instead of directly writing new double
*/
