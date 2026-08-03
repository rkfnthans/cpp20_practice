# Day 02 — Streams, File I/O, and Filesystem

## Date

2026-07-31

## Topic

Practicing C++ output streams, file input and output, stream-state checking, and basic filesystem inspection.

## What I Studied

- File output with `std::ofstream`
- Opening a file with `open()`
- Opening a file directly through the `std::ofstream` constructor
- Automatic file closing when a stream object leaves scope
- Manual `open()` and `close()` when direct control is needed
- Reusing one function with a `std::ostream&` parameter
- Writing to `std::cout`, `std::ofstream`, and `std::stringstream`
- Retrieving stored text with `stringstream::str()`
- File input with `std::ifstream`
- Failed stream states when a file does not exist
- Checking stream state before reading
- Directory iteration with `std::filesystem::directory_iterator`
- Distinguishing regular files from directories
- Checking terminal paths with `pwd` and `ls`
- Running a program only after successful compilation with `&&`

## Practice Method

The examples were written and tested one at a time in `practice.cpp`.

The file was repeatedly overwritten while moving through the textbook examples. The session focused on understanding the examples, observing compiler and runtime behavior, and recording mistakes and corrections.

A separate `main.cpp` was not created during Day 02 because the available study time was required for the examples themselves. This session therefore remains a practice-focused record rather than an applied mini-project.

## Representative Code

### File output through a constructor

```cpp
#include <fstream>

int main()
{
    std::ofstream square_file{"squares.txt"};

    for (int i = 0; i < 10; ++i)
        square_file << i << "^2 = " << i * i << '\n';
}
```

The constructor opens the file immediately. The stream closes automatically when the object leaves scope.

### Reusing one output function

```cpp
#include <fstream>
#include <iostream>
#include <sstream>

void write_something(std::ostream& os)
{
    os << "Hi stream, did you know that 3 * 3 = "
       << 3 * 3 << '\n';
}

int main()
{
    std::ofstream myfile{"example.txt"};
    std::stringstream mysstream;

    write_something(std::cout);
    write_something(myfile);
    write_something(mysstream);

    std::cout << "mysstream is: " << mysstream.str();
}
```

A function taking `std::ostream&` can write to the terminal, a file, or an in-memory string stream.

### Checking failed file input

```cpp
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream infile{"some_missing_file.xyz"};

    if (!infile)
    {
        std::cerr << "Failed to open the file.\n";
        return 1;
    }

    int i{};
    double d{};

    if (!(infile >> i >> d))
    {
        std::cerr << "Failed to read valid values.\n";
        return 1;
    }

    std::cout << "i is " << i << ", d is " << d << '\n';
}
```

A stream object can be constructed even when its file cannot be opened. The stream enters a failed state instead of stopping the program automatically.

### Inspecting the current directory

```cpp
#include <filesystem>
#include <iostream>

int main()
{
    namespace fs = std::filesystem;

    for (const auto& entry : fs::directory_iterator{"."})
    {
        if (entry.is_regular_file())
            std::cout << entry.path() << " is a regular file.\n";
        else if (entry.is_directory())
            std::cout << entry.path() << " is a directory.\n";
        else
            std::cout << entry.path()
                      << " is neither a regular file nor a directory.\n";
    }
}
```

`directory_iterator(".")` scans the current directory. Source files, text files, Markdown files, and executables are all regular files.

## Compilation

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic practice.cpp -o practice
```

To run the program only when compilation succeeds:

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic practice.cpp -o practice && ./practice
```

## Execution

```bash
./practice
```

Before compiling, the current directory and files can be checked with:

```bash
pwd
ls
```

## What I Changed

- Opened a file directly through an `std::ofstream` constructor.
- Learned that explicit `close()` is not always required because the stream closes at the end of its scope.
- Kept `open()` and `close()` as an option when direct lifetime control is needed.
- Used one `std::ostream&` function with `std::cout`, `std::ofstream`, and `std::stringstream`.
- Changed `int main(int argc, char* argv[])` to `int main()` when command-line arguments were not used.
- Added stream-state checks before reading from a file.
- Included `<filesystem>` and used `std::filesystem`.
- Used `&&` to prevent execution after a failed compilation.

## Mistakes and Corrections

### Mistake 1 — Compiled the Wrong `practice.cpp`

The terminal was in the Day 01 directory while the intended source file was in the Day 02 directory.

The wrong file was compiled, and the linker could not find the expected `main()` function.

```text
Undefined symbols for architecture arm64:
  "_main"
```

### Correction

I checked the current directory and file list before compiling.

```bash
pwd
ls
```

I then moved to the correct Day 02 directory.

### Mistake 2 — Tried to Run an Executable That Was Not Created

After compilation failed, I ran:

```bash
./practice
```

The new executable did not exist because the build had failed.

### Correction

I compiled successfully first and later connected compilation and execution with `&&`.

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic practice.cpp -o practice && ./practice
```

### Mistake 3 — Unused `argc` and `argv`

The program declared command-line parameters but did not use them.

```cpp
int main(int argc, char* argv[])
```

This produced unused-parameter warnings.

### Correction

I used:

```cpp
int main()
```

when command-line arguments were unnecessary.

### Mistake 4 — Assumed a Missing File Would Produce an Immediate Error

An `std::ifstream` object was constructed for a file that did not exist.

The stream object was still created, but it entered a failed state. The program continued running unless the state was checked.

### Correction

I checked the stream before attempting input.

```cpp
if (!infile)
{
    std::cerr << "Failed to open the file.\n";
    return 1;
}
```

I also learned that failed extraction can leave variables unchanged, so input success should be checked before using their values.

### Mistake 5 — Used `std::filesystems`

I wrote the namespace name in plural form.

```cpp
namespace fs = std::filesystems;
```

### Correction

The correct namespace is:

```cpp
namespace fs = std::filesystem;
```

The `<filesystem>` header must also be included.

### Mistake 6 — Ran an Older Executable After Compilation Failed

A failed compilation did not delete the executable from the previous successful build.

Running `./practice` could therefore run older code and display an unrelated result.

### Correction

I used `&&` so that execution occurs only after the current source file compiles successfully.

## C or Python Comparison

- C++ uses the common `std::ostream` interface for terminal output, file output, and string-stream output.
- Python also uses file-like objects, but C++ expresses the shared interface through stream inheritance and references.
- A C++ file stream closes automatically when its object leaves scope. Python commonly uses `with open(...)` for the same resource-lifetime purpose.
- Opening a missing file in Python normally raises `FileNotFoundError`. A default C++ `std::ifstream` instead enters a failed state unless exceptions are enabled.
- C++ stream input can fail without stopping the program, so stream states must be checked explicitly.
- `std::filesystem` provides functionality similar to Python's `pathlib` and `os` modules.

## What I Can Explain Now

- How `std::ofstream` writes data to a file
- The difference between opening a file with `open()` and through a constructor
- Why file streams close automatically at the end of their scope
- When manual `open()` and `close()` may be useful
- Why one function taking `std::ostream&` can write to several destinations
- How `std::stringstream` stores formatted text in memory
- Why a constructed `std::ifstream` does not guarantee a successfully opened file
- How to check failed file opening and failed extraction
- Why unused `argc` and `argv` parameters produce warnings
- Why a failed compilation may leave an older executable in the directory
- Why `&&` is safer for compile-and-run commands
- How `std::filesystem::directory_iterator` scans a directory
- How regular files and directories are distinguished

## Next Topic

Continue with the next C++ fundamentals examples.

A separate `main.cpp` will be added when the studied concepts and available time support a meaningful applied program.
