#!/usr/bin/env python3
# coding=utf-8

"""
set(集合)是⼀个⾮常有⽤的数据结构。它与列表(list)的⾏为类似，区别在于set不能包含重复的值
"""

print(set([1, 2, 3, 3, 4, 4]))

# 求交集
setA = set([1, 2, 3, 4])
setB = set([3, 4, 5, 6])
print(setA.intersection(setB))

# 求差集
print(setA.difference(setB))


setSort = set([4, 2, 1, 5, 8])
print(setSort)

list_a = [["a", "b", "c"], ["e", "f"], ["f", "e"], ["f", "e"]]
t_a = map(tuple, list_a)
print(set(t_a))
