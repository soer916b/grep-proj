# mini-grep

A small grep-like command line program written in C as a learning project.

The project was built to practice:

- File I/O
- Pointers and memory
- Strings in C
- Argument parsing
- Debugging
- Basic error handling

## Features

- Searches for a substring using `strstr`
- Reads input files line by line using `fgets`
- Supports one or more input files
- Prefixes matches with filename when multiple files are searched
- Supports `-n` to print matching line numbers
- Continues processing other files even if one file fails, and returns a non-zero exit code if at least one file could not be processed

## Build

- Compile the program with `make`
- Clean with `make clean`

## Usage

Search in a single file:

`./bin/grep <pattern> <file>`

Search in one or more files with line numbers:

`./bin/grep -n <pattern> <file1> <file2> ...`

### Examples

`./bin/grep hello notes.txt`
`./bin/mini-grep -n hello notes.txt other.txt`

## Limitations

This is a small learning project, so the implementation is intentionally simple:

- Fixed-size line buffer (fgets with a 1024 byte buffer)
- Substring matching only, no regular expressions
- Case-sensitive matching
- Simple argument parsing

## Project structure
`src/`: source files
`bin/`: compiled binary
