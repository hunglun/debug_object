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

b0:
	g++ b0.cpp -o b0.aout 

c0:
	gcc c0.cpp -fno-strict-aliasing -fno-strict-aliasing -I.. -I.. -lm -lpthread -ldl -ltcc -ldl -fpermissive -o c0.out
