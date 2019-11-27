#!/usr/bin/env python3
# coding=utf-8

#Generators 生成器
def generator_functions():
    for i in range(10):
        yield i

for item in generator_functions():
    print(item)

def fibon(n):
    a=b=1
    for i in range(n):
        yield a
        a,b=b,a+b

fibo_ret = fibon(10)
for item in fibo_ret:
    print(item)
