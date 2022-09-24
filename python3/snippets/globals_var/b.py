# global g_b

g_b = None
"""python在使用全局变量的时候要用复杂的对象，而不要用简单的对象，简单对象会被import的时候自动复制一份，而复杂的对象例如dict，则用的是引用"""

def print_b():
    print(g_b)
