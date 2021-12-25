#!/usr/bin/env python3
# coding=utf-8

print("hello world")

#*args **kwargs 用法区别
def test_args(*args):
    for arg in args:
        print("arg ",arg)

def test_kwargs(**kwargs):
    #pdb.set_trace()
    for key,value in kwargs.items():
        print("{0} and {1}".format(key,value))

def test_args_and_kwargs(*args,**kwargs):
    for arg in args:
        print("test arg",arg)
    for key,value in kwargs.items():
        print("test {0} and {1}".format(key,value))

test_args("a","b","c",1,2,3)
test_kwargs(name='hulk',age=3)
test_args_and_kwargs(1,2,3,4,name="123",keyword="this key")

