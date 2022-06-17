#!/usr/bin/env python3
# coding=utf-8

# Generators 生成器，主要作用是节省内存资源
def generator_functions():
    for i in range(10):
        yield i


for item in generator_functions():
    print(item)
    # yield完毕后 for会自动捕捉StopIteration异常


def fibon(n):
    a = b = 1
    for i in range(n):
        yield a
        a, b = b, a + b


fibo_ret = fibon(10)
for item in fibo_ret:
    print(item)

# 内置函数 next iter
gen = generator_functions()
print(next(gen))
print(next(gen))

str = "this is a string"
print(next(iter(str)))
print(next(iter(str)))
