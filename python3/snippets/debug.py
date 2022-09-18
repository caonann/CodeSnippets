#!/usr/bin/env python3
# coding=utf-8

import pdb

# 命令行执行调试 python -m pdb my_script.py


def show_trace():
    pdb.set_trace()
    return "show_trace done"


def outer_func():
    var_str = show_trace()
    var_str += "succ"
    print("var_str " + var_str)


if __name__ == "__main__":
    outer_func()
