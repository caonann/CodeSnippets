#!/usr/bin/env python
# coding=utf-8

def request(func):
    def wrapper():
        print("hello, %s" % func.__name__)
        func()
        print("goodby, %s" % func.__name__)
    return wrapper

@request
@request
def hello():
    print("hi hulk")

hello()