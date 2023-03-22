#!/usr/bin/env python
# coding=utf-8
import functools

"""这种装饰器是在导包时期执行,并且传入的事func,装饰器上不需要加括号"""


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

"""这种装饰器是在导包时期执行"""


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


@request2
@request
def hihi():
    print("this is hihi")


# 执行期的装饰器，在函数运行时执行，可以获取到flask的request对象
def first():
    def decorator(handler):
        @functools.wraps(handler)
        def wraps(*xargs, **kwargs):
            # from flask import request
            # request.header
            return handler(*xargs, **kwargs)

        return wraps

    return decorator


@first()
def hihihi(a=1):
    print("this is hihihi")


hihihi()
