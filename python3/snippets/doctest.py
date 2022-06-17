class ABC:
    """this is a doc test"""

    def __init__(self) -> None:
        pass

    def func_test(self):
        """this is a func test desc"""
        print("haha")


if __name__ == "__main__":
    print(ABC.__doc__)
    a = ABC()
    print(a.__doc__)
    print(ABC.func_test.__doc__)
    print(__name__)
