#include <stdlib.h>
#include <stdio.h>
#include "libtcc.h"

int add(int a, int b) { return a + b; }

char my_program[] =
"int fib(int n) {\n"
"    if (n <= 2) return 1;\n"
"    else return fib(n-1) + fib(n-2);\n"
"}\n"
"int foobar(int n) {\n"
"    printf(\"fib(%d) = %d\\n\", n, fib(n));\n"
"    printf(\"add(%d, %d) = %d\\n\", n, 2 * n, add(n, 2 * n));\n"
"    return 1337;\n"
"}\n";

int main(int argc, char **argv)
{
    TCCState *s;
    int (*foobar_func)(int);
    void *mem;

    s = tcc_new();
    tcc_set_output_type(s, TCC_OUTPUT_DLL);
    tcc_compile_string(s, my_program);
    tcc_add_symbol(s, "add", add);
    int n = tcc_output_file(s, "debug.bin");
    
    tcc_delete(s);

    printf("n is %d\n", n);

    free(mem);
    return 0;
}
