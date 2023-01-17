#!/usr/bin/env python
# coding=utf-8

try:
    assert 1==0,"1 != 0"
    print("pass")
except Exception as e:
    print(f"exception {e}")
    import time
    time.sleep(1)
    print("retry")
    assert 1==0,"1 != 0"

print("succ")