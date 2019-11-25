#!/usr/bin/env python3
# coding=utf-8
import pdb

print("hello world")

#*args **kwargs 用法区别
def test_args(*args):
    for arg in args:
        print("arg ",arg)

def test_kwargs(**kwargs):
    #pdb.set_trace()
    for key,value in kwargs.items():
        print("{0} and {1}".format(key,value))

test_args("a","b","c",1,2,3)
test_kwargs(name='hulk',age=3)

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

fibo_ret = fibon(100)
for item in fibo_ret:
    print(item)
