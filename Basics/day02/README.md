# Day 02 — Streams, File I/O, and Filesystem

## Date

2026-07-31

## Topic

Using C++ streams for file output, reusable output functions, in-memory text storage, file input validation, and basic filesystem inspection.

## What I Studied

- File output with `std::ofstream`
- Opening a file directly through a stream constructor
- Automatic file closing when a stream object leaves scope
- Manual `open()` and `close()` when explicit control is needed
- Reusing one function through a `std::ostream&` parameter
- Writing to `std::cout`, `std::ofstream`, and `std::stringstream`
- Retrieving in-memory text with `stringstream::str()`
- File input with `std::ifstream`
- Stream failure states when a file cannot be opened
- Checking stream state before reading
- Directory iteration with `std::filesystem::directory_iterator`
- Distinguishing regular files from directories
- Using `pwd`, `ls`, and `&&` during compilation and execution

## Code

The examples were written one at a time in `practice.cpp`.

The file was repeatedly modified while testing stream output, string streams, failed file input, and filesystem inspection. The final exercise inspected entries in the current directory.

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

Other representative exercises included:

```cpp
std::ofstream square_file{"squares.txt"};
```

```cpp
void write_something(std::ostream& os)
{
    os << "Hi stream, did you know that 3 * 3 = "
       << 3 * 3 << '\n';
}
```

```cpp
std::ifstream infile{"some_missing_file.xyz"};

if (!infile)
{
    std::cerr << "Failed to open the file.\n";
    return 1;
}
```

## Compilation

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic practice.cpp -o practice
```

To run the program only after successful compilation:

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic practice.cpp -o practice && ./practice
```

## Execution

```bash
./practice
```

Useful checks before compiling:

```bash
pwd
ls
```

The filesystem exercise listed entries such as source files, Markdown files, generated text files, and the executable as regular files.

## What I Changed

- Replaced separate stream construction and `open()` calls with direct constructor initialization.
- Removed explicit `close()` calls when automatic closing at the end of scope was sufficient.
- Passed `std::ostream&` to one function so that the same code could write to the terminal, a file, or a string stream.
- Replaced `int main(int argc, char* argv[])` with `int main()` when command-line arguments were not used.
- Added checks for failed file opening and failed extraction.
- Added the `<filesystem>` header.
- Corrected `std::filesystems` to `std::filesystem`.
- Used `&&` so that an executable runs only after successful compilation.

## Mistakes and Corrections

### Mistake 1 — Compiled the Wrong `practice.cpp`

The terminal was in the Day 01 directory while the intended source file was in the Day 02 directory.

The compiler processed a different file that did not contain the expected `main()` function.

### Correction

I checked the current directory and available files before compiling.

```bash
pwd
ls
```

I then moved to the correct directory and compiled the intended source file.

### Mistake 2 — Executable Not Found After Compilation Failed

After the link step failed, I tried to run:

```bash
./practice
```

No new executable had been created.

### Correction

I compiled successfully before running the program and later combined both steps with:

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic practice.cpp -o practice && ./practice
```

### Mistake 3 — Unused `argc` and `argv`

The program declared command-line parameters but did not use them.

```cpp
int main(int argc, char* argv[])
```

This produced `-Wunused-parameter` warnings.

### Correction

I used the simpler form when command-line arguments were unnecessary.

```cpp
int main()
```

### Mistake 4 — Assumed a Missing File Would Stop the Program

An `std::ifstream` object was constructed for a file that did not exist.

The object itself was still created, but the stream entered a failed state. The program did not stop automatically.

### Correction

I checked the stream immediately after construction.

```cpp
std::ifstream infile{"some_missing_file.xyz"};

if (!infile)
{
    std::cerr << "Failed to open the file.\n";
    return 1;
}
```

I also initialized destination variables and checked whether extraction succeeded before using their values.

```cpp
int i{};
double d{};

if (!(infile >> i >> d))
{
    std::cerr << "Failed to read valid values.\n";
    return 1;
}
```

The earlier output of `0` and `0` was not proof of successful input. The extraction had failed.

### Mistake 5 — Used the Wrong Filesystem Namespace

I wrote:

```cpp
namespace fs = std::filesystems;
```

The correct namespace is singular.

### Correction

I included the correct header and namespace.

```cpp
#include <filesystem>

namespace fs = std::filesystem;
```

### Mistake 6 — Ran an Older Executable After a Compilation Error

A failed compilation did not remove the executable created by an earlier successful build.

Running `./practice` could therefore execute old code and display an unrelated result.

### Correction

I used `&&` so that execution occurs only when the current compilation succeeds.

```bash
clang++ -std=c++20 -Wall -Wextra -Wpedantic practice.cpp -o practice && ./practice
```

## C or Python Comparison

- C++ uses a common stream interface for terminal output, file output, and in-memory formatted output. Python provides separate objects with similar file-like behavior.
- A C++ file stream normally closes automatically when its object leaves scope. Python commonly expresses the same lifetime rule with a `with open(...)` context manager.
- Opening a missing file with Python normally raises `FileNotFoundError`. A default C++ `std::ifstream` instead enters a failed state unless exceptions are explicitly enabled.
- C++ stream extraction can fail without stopping the program, so the stream state must be checked.
- `std::filesystem` provides path and directory operations similar to Python's `pathlib` and `os` modules.

## What I Can Explain Now

- How `std::ofstream` writes text to a file
- Why a stream constructor can replace a separate `open()` call
- Why file streams close automatically at the end of their scope
- When explicit `open()` and `close()` calls may still be useful
- Why a function taking `std::ostream&` can write to different destinations
- How `std::stringstream` stores formatted text in memory
- Why creating an `std::ifstream` object does not guarantee that the file opened successfully
- How to check file-opening and extraction failures
- Why failed compilation may leave an older executable in place
- Why `&&` prevents an old executable from running after a failed build
- How `std::filesystem::directory_iterator` scans the current directory
- How regular files and directories are classified

## Next Topic

Continue studying variables, initialization, types, and expressions in greater detail.
