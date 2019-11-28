#!/usr/bin/env python3
# coding=utf-8

'''
set(集合)是⼀个⾮常有⽤的数据结构。它与列表(list)的⾏为类似，区别在于set不能包含重复的值
'''

print(set([1,2,3,3,4,4]))

# 求交集
setA = set([1,2,3,4])
setB = set([3,4,5,6])
print(setA.intersection(setB))

# 求差集
print(setA.difference(setB))