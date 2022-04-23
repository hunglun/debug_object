#!/bin/env python3
"""
from assembly code, extract code starting with .globl func and ending with .cfi_endproc

	.globl	func
	.type	func, @function
func:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$7, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc

"""
import re
import pdb
import sys

def extract_function_assembly_code(assembly_code):
    m=re.compile("\s+\.globl	func.*\.cfi_endproc", re.MULTILINE | re.DOTALL).search(assembly_code)
    return m.group(0)

def extract_function_assembly_code_in_one_line(assembly_code):
    a = extract_function_assembly_code(assembly_code)
    return a.replace("\n","\\n\\t")

def test_extract_function_assembly_code():
    code = """	.globl	func
	.type	func, @function
func:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$7, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
"""
    assert(extract_function_assembly_code(code))

    
if "__main__" == __name__:
    content = ""
    with open(sys.argv[1]) as f:
        content = f.read()
    print(extract_function_assembly_code(content))
