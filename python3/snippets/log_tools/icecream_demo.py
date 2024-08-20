# pip install icecream

from icecream import ic

# ic.disable()
ic.enable()


# 打印函数中间结果
def fibo(n: int) -> None:  # type: ignore
    a, b = 0, 1
    for _ in range(n):
        a, b = b, a + b
        ic(a, b)


# 访问字典
mydict = {"a": [{"b": 1, "c": 2}, {"b": 3, "c": 4}]}


# 打印对象属性
class A:
    aa = 1
    bb = 2

    def __init__(self, a: int, b: int) -> None:
        self.a = a
        self.b = b


# 放在函数中传参
def func(a: int, b: int) -> None:
    return a + b


if __name__ == "__main__":
    fibo(10)
    ic(mydict)
    ic(mydict["a"][0]["b"])
    oA = A(1, 2)
    ic(oA.aa)

    # 运用在条件语句
    if hasattr(oA, "aa"):
        ic()
    else:
        ic()

    func(ic(11), ic(22))
