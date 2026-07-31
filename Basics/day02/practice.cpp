#include <iostream>
#include <filesystem>

int main()
{
    namespace fs=std::filesystem;
    for (auto & p : fs::directory_iterator("."))
        if (is_regular_file(p))
            std::cout<<p<<" is a regular file.\n"; 
        else if(is_directory(p))
            std::cout<<p<<" is a directory.\n";
        else
            std::cout<<p<<"is neither regular file nor directory.\n";

}


/*
[DAY 02 NOTES]
- TOPIC: File output with std::ofstream
- ERROR: compiled the wrong practice.cpp
- FIX: check the directory with pwd and ls before compiling
- NOTE: ./practice works only after successful compilation

- TOPIC: File output with std::ofstream
- NOTE: Constructor opens the file immediately
- NOTE: The file closes automatically when the stream goes out of scope
- USE: open() and close() when manual control is needed

- TOPIC: Using one std::ostream function with cout, ofstream, and stringstream
- WARNING: argc and argv were declared but unused
  FIX: Use int main() when command-line arguments are not needed
- NOTE: ofstream writes to a file, while stringstream stores text in memory
- NOTE: Use && to compile and run in one command

- TOPIC: C++ stream error handling
- NOTE: A stream object can be created even when the file does not exist
- NOTE: The stream enters a failed state instead of stopping the program
- RISK: Input operations may fail silently, leaving variables unchanged
- FIX: Check the stream state with if (!infile) before reading

- TOPIC: Inspecting directory entries with std::filesystem
- NOTE: directory_iterator(".") scans the current directory
- NOTE: Executables and text files are both regular files
- NOTE: is_directory() identifies folders
*/