# C & C++ System Programming Practice

This repository is a collection of standalone C and C++ programs developed to understand and experiment with core system-level and multithreaded programming concepts.

## 📂 Contents

Below are some of the key topics and corresponding files in this repository:

| File/Folder                        | Description |
|-----------------------------------|-------------|
| `anonymous-pipes.c`               | Demonstrates inter-process communication using anonymous pipes |
| `copy-without-cp.c`               | Manually copies contents of one file to another (without using `cp`) |
| `even_odd-mutex-sync.c`          | Uses threads and mutexes to print even and odd numbers in order |
| `fork-exec.c`                     | Showcases usage of `fork()` and `exec()` system calls |
| `myshell`                         | Custom shell implementation (directory with shell-related logic) |
| `pipe.c`                          | Basic pipe implementation for IPC |
| `signal-handle-SIGINT.c`         | Handling of `SIGINT` (Ctrl+C) signal in C |
| `tcp-server.c`                    | Simple TCP server using socket programming |
| `thread-mutex-multiple-client.c` | Handles multiple client connections using threads and mutexes |
| `reference.cpp`, `refrence`      | Examples demonstrating C++ reference concepts |
| `function.cpp`                   | C++ function usage demonstration |
| `loops.cpp`, `loops1.cpp`, `loops2.cpp` | Looping constructs in C++ |
| `source.txt`, `dest.txt`         | Input/output sample files for file operations |
| `program.c`, `practice.c`, `prac.cpp`, `prac2.cpp` | General practice programs |
| `shm.c`                           | Shared memory usage in C |
| `mutex.c`                         | Mutex implementation example |

> 📝 Many of these files are standalone and can be compiled and run individually.

---

## 🛠️ How to Compile & Run

Use `gcc` for C files and `g++` for C++ files.

Example:

```bash
# For a C file
gcc thread-mutex-multiple-client.c -o thread_example -lpthread
./thread_example

# For a C++ file
g++ reference.cpp -o reference
./reference
