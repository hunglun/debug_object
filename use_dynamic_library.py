#!/bin/env python3

from ctypes import *
libc = CDLL("./debug.so")
fib=libc.fib
print(fib(10))
