#!/usr/bin/env python3
# coding=utf-8
from functools import reduce

#map 用法 传入序列参数执行func得结果
def func_map(x,y):
    return x*y

list_ret = list(map(func_map,[1,2,3,4],[5,6,7,8,9]))
print(list_ret)

#filter 用法 筛选列表中符合函数逻辑的参数

list_ret = list(filter(lambda x: x>0,[1,2,3,-1,-2,-3]))
print(list_ret)

'''
reduce 用法 对sequence中的item顺序迭代调用function，如果有starting_value，还可以作为初始值调用
reduce函数，reduce函数会对参数序列中元素进行累积。
py3以后使用，必须导入 from functools import reduce
reduce函数的定义：reduce(function, sequence[, initial]) -> value
function参数是一个有两个参数的函数，reduce依次从sequence中取一个元素，和上一次调用function的结果做参数再次调用function。
第一次调用function时，如果提供initial参数，会以sequence中的第一个元素和initial作为参数调用function，否则会以序列sequence中的前两个元素做参数调用function。
'''

list_ret = reduce(lambda x,y:x+y,range(-5,5),1)
print(list_ret)