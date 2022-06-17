#!/usr/bin/env python
# coding=utf-8
import functools

from request_check.context import Context


def request(func):
    print(f"in request {func.__name__}")

    @functools.wraps(func)
    def wrapper():
        print("hello, %s" % func.__name__)
        func()
        print("goodby, %s" % func.__name__)

    return wrapper


@request
@request
def hello():
    print("hi hulk")


"""
request(request(hello))
"""
hello()


def request2(*args, **kwargs):
    print(f"in request {__name__} keys:{args} {kwargs}")

    def _(func):
        @functools.wraps(func)
        def wrapper(*args, **kwargs):
            print(f"input param {func.__name__} {args} {kwargs}")

        return wrapper

    return _


@request2(a="123", b=123, c=True)
def hi(d="haha", e=456):
    print("entry start")


hi(a="123123", b=123123, c=False)
