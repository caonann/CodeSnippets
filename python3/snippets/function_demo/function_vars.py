import functools
import sys
from inspect import currentframe, getframeinfo


def func3():
    print("this is func3")


def func0():
    def _(func):
        print("this is func0 ,name is", func.__name__)
        print("test_var is ", getattr(func, "test_var", "none"))
        return func

    return _


def func1(**args):
    def _(func):
        func.test_var = args["test_var"]
        print("this is func1 ,name is", func.__name__)
        print("test_var is ", getattr(func, "test_var", "none"))
        return func

    return _


class A:
    @staticmethod
    def func2(**args):
        def _(func):
            print("this is func2 ,name is", func.__name__)
            print("test_var is ", getattr(func, "test_var", "none"))
            # print(dir(func))

            @functools.wraps(func)
            def wrap(*args, **kwargs):
                print("wrap...")
                print("test_var is ", getattr(func, "test_var", "none"))
                ret = func(*args, **kwargs)
                return ret

            # print(getattr(A.func2, "test_var"))
            return wrap

        return _


@func0()
@func1(test_var="test_var")
@A.func2()
def func3():
    print("this is view func")


# func3()
