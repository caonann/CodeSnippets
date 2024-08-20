from timeit import Timer

arr = [i for i in range(10000)]
set_arr = set(arr)


def test_function():
    # if in 的判断是从数组元素开始遍历，判断到了就立刻返回
    if 500 in arr:
        pass


def test_function2():
    if 500 in set_arr:
        pass


if __name__ == "__main__":
    t = Timer(
        "test_function()",
        "from __main__ import test_function",
    )
    n = 1000000
    # 运行测试
    execution_time = t.timeit(number=n)
    print(f"test_function 函数执行时间: {execution_time} 秒")

    t2 = Timer(
        "test_function2()",
        "from __main__ import test_function2",
    )
    execution_time = t2.timeit(number=n)
    print(f"test_function 函数执行时间: {execution_time} 秒")
