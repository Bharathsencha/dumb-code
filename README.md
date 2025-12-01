# Minimal C Benchmark Project (No libc)

This project implements a tiny standalone benchmark system written in pure C
without using `stdio.h`, `scanf`, `printf`, or `time.h`.  
All input/output is performed using raw Linux syscalls, and timing is done using
the CPU's `rdtsc/rdtscp` instructions.

## Files

- `printf.c` / `printf.h` — minimal output functions (`putstr`, `putnum`, `puthex`)
- `scanf.c` / `scanf.h` — minimal input function (`read_uint`)
- `time.c` / `time.h` — cycle-accurate timing using RDTSC
- `main.c` — example program demonstrating usage

## Build

Compile all files together using:

```bash
gcc -O2 main.c printf.c scanf.c time.c -o test
