### Assemble the NASM file into an object file 
```bash
nasm -f elf64 random.asm -o random.o
```
### Compile the C file and link it with the assembly object file
```bash
gcc main.c random.o -o main
```
### Run the executable
```
./main
```
