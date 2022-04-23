# send execution instruction to a running program
inline assembly 

# assemble a user defined function and send the assembly code to a running program to execute
gcc -S debug.c
edit debug.s 
embed the assembly code in a1.cpp

# use python to edit the generated assembly code
edit_assembly_code.py

# put everything together
gcc -S debug.c 
edit_assembly_code.py debug.s | a2

No! Hit a roadblock. A program can not call asm on some string made during runtime. The assembly code in __asm__() must be fixed during compilation time. 


# use mmap and byte code
see b0.cpp
How to convert c program into byte code on development machine?


# use libtcc 
compile c program on the fly in target and run it.
see c0

# b1 : read debug.o into memory and cast it to function does not work

# conclusion : libtcc is the most promising option for creating debug object
c0 can be splitted into 2 parts. The first part involves compilation to be done on sender program.
The second part is to relocate the execution code to runnable memory in the receiver program.

