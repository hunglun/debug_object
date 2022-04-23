all:
	g++ -x c -std=c17  -O2 -Wall -Wextra -pedantic -pthread -pedantic-errors main.cpp -lm  -latomic 

# convert c function into assembly code
a0:
	gcc -S debug.c	

a1:
	g++ -x c -std=c17  -O2 -Wall -Wextra -pedantic -pthread -pedantic-errors a1.cpp -lm  -latomic -o a1.out

a2:
	g++ -x c -std=c17  -O2 -Wall -Wextra -pedantic -pthread -pedantic-errors a2.cpp -lm  -latomic -o a2.out

a3:
	g++ -x c -std=c17  -O2 -Wall -Wextra -pedantic -pthread -pedantic-errors a3.cpp -lm  -latomic -o a3.out
