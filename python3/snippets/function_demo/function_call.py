def test_func():
    def test_func_sub():
        print("this is sub func")


if __name__ == "__main__":
    a = test_func
    # a.test_func_sub()
    外层函数无法直接调用内层函数
