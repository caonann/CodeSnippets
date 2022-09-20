#!/usr/bin/env python3
# coding=utf-8

def func_overloading(param1):
    print(param1)

'''后声明的函数会覆盖前面的函数，并没有实现重新重载'''
def func_overloading(param2,param3=None):
    print(f"param2 {param2},param3 {param3}")

func_overloading("abc")