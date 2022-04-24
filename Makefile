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
	g++ b0.cpp -o b0.out 

b1:
	g++   b1.cpp -g -o b1.out 
b2:
	g++   b2.cpp -g -o b2.out 
c0:
	gcc c0.cpp -fno-strict-aliasing -fno-strict-aliasing -I.. -I.. -lm -lpthread -ldl -ltcc -ldl -fpermissive -o c0.out

c1:
	gcc c1.cpp -fno-strict-aliasing -fno-strict-aliasing -I.. -I.. -lm -lpthread -ldl -ltcc -ldl -fpermissive -o c1.out

# use dynamic library created from tcc, much smaller than gcc shared library
c2:	c1
	./c1.out && python3 use_dynamic_library.py

# use python3 ctype and gcc dynamic library
d0:
	gcc debug.c -c -fPIC && gcc debug.o -shared -o libdebug.so \
&& python3 -c "from ctypes import *; libc = CDLL('./libdebug.so'); print(libc.func())"
