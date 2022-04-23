#include <stdio.h>
 
extern int func(void);
// the definition of func is written in assembly language
__asm__("\n\t	.globl	func\n\t	.type	func, @function\n\tfunc:\n\t.LFB0:\n\t	.cfi_startproc\n\t	endbr64\n\t	pushq	%rbp\n\t	.cfi_def_cfa_offset 16\n\t	.cfi_offset 6, -16\n\t	movq	%rsp, %rbp\n\t	.cfi_def_cfa_register 6\n\t	movl	$7, %eax\n\t	popq	%rbp\n\t	.cfi_def_cfa 7, 8\n\t	ret\n\t	.cfi_endproc"
);

int main(void)
{
    int n = func();
    // gcc's extended inline assembly
    printf("n is %d\n", n);
    fflush(stdout); // flush is intentional 
}
