from typing import Dict, List, Tuple

temperature = 98.5
original = temperature

print(temperature, original)
temperature = 9
print(temperature, original)

print(float("3.1415"))
print(int("5b", 16))
print(len("abc"))

"""
set 用法
1.set存储的内容不保证顺序，这点有点像gloang的list
2.只有immutable类型的变量才能存到set中 
"""
print(set("hello world"))
set_test = {"a", "b", "c", 1}
print(set_test)

"""dict用法
"""
key_pairs = [("key1", "value1"), ("key2", 1), (345, "bb")]
print(dict(key_pairs))


"""
Expressions, Operators, and Precedence
is 
is not
== !=

The == operator compares the value or equality of two objects, 
whereas the Python is operator checks whether two variables point to the same object in memory.
https://stackoverflow.com/questions/132988/is-there-a-difference-between-and-is
"""
if temperature is original:
    print("temperature is original")

value_a = 1
value_b = 1
if value_a is value_b:
    print("value_a is value_b")
if value_a == value_b:
    print("value_a == value_b")

"""Python caches small integer objects, which is an implementation detail.
>>> 1000 is 10**3
False
>>> 1000 == 10**3
True
"""

"""Bitwise Operators"""

"""Sequence Operators"""
list_test = [1, 2, 3, 4]
list_test_b = [2, 3, 4, 5]
print(list_test * 4)

alpha = [1, 2, 3]
beta = alpha  # an alias for alpha
beta += [4, 5]  # extends the original list with two more elements
beta = beta + [6, 7]  # reassigns beta to a new list [1, 2, 3, 4, 5, 6, 7]
print(alpha)  # will be [1, 2, 3, 4, 5]


def func_test(
    param1: int, param2: str, param3: List[int], param4: Tuple[str], *names
) -> Dict:
    param1 = 2
    param2 = "abc"
    param3 += [4, 5, 6]
    print(param4)
    return {param1: param1, param2: param2, "param3": param3}


p1 = 3
p2 = "mytest"
p3 = [1, 2, 3]
p4 = (1, 2, 3, 4)
print(func_test(p1, p2, p3, p4))
print(p1, p2, p3)

ip = "255.168.1.3"
a, b, c, d = (lambda ips: list(map(bin, ips)))([int(_) for _ in ip.split(".")])
print(f"{a},{b},{c},{d}")

print(".".join([format(int(_), "08b") for _ in ip.split(".")]))
print("{:08b},{:08b},{:08b},{:08b}".format(*[int(_) for _ in ip.split(".")]))

"""closure 函数闭包实验"""


def func_a(x):
    c = [1, 2, 3]
    n = 0

    def func_b(y):
        c.append(4)
        n = 1
        return x + y

    func_b(3)
    print(c)
    print(f"n is {n}")  # 无法改变n的值
    return func_b


f = func_a(1)
print(f(2))
print(f(3))

print(locals())


if a:= "aaa" if True else None:
    print(a)