all:
	g++ -x c -std=c17  -O2 -Wall -Wextra -pedantic -pthread -pedantic-errors main.cpp -lm  -latomic 

# convert c function into assembly code
f_to_s:
	gcc -S debug.c	
