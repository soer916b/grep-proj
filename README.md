# mini-grep

A small grep-like command line program written in C as a learning project.

The project was built to practice:

- file I/O
- pointers and memory
- strings in C
- argument parsing
- debugging
- basic error handling

## Features

- searches for a substring using `strstr`
- reads input files line by line using `fgets`
- supports one or more input files
- prefixes matches with filename when multiple files are searched
- supports `-n` to print matching line numbers
- continues processing other files even if one file fails, and returns a non-zero exit code if at least one file could not be processed

## Build

Compile the program with:

```bash```
`make`

## Usage

Search in a single file:

`./bin/grep <pattern> <file>`

Search in one or more files with line numbers:

./bin/grep -n <pattern> <file1> <file2> ...

### Examples

./bin/grep hello notes.txt
./bin/mini-grep -n hello notes.txt other.txt

## Limitations

This is a small learning project, so the implementation is intentionally simple:

- fixed-size line buffer (fgets with a 1024 byte buffer)
- substring matching only, no regular expressions
- case-sensitive matching
- simple argument parsing

## Project structure
src/    source files
bin/    compiled binary
