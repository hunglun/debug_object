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


