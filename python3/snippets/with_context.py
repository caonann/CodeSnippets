# 与函数和模块不同，with块没有定义新的作用域
class LookingGlass:
    def __enter__(self):
        import sys

        print("enter...")
        self.original_wirte = sys.stdout.write
        sys.stdout.write = self.reverse_write
        return "heloo hulk"

    def reverse_write(self, text):
        self.original_wirte(text[::-1])

    def __exit__(self, exc_type, exc_value, traceback):
        import sys

        sys.stdout.write = self.original_wirte
        if exc_type is ZeroDivisionError:
            print("dont divide by zero")
            return True
        print("exit ...")


if __name__ == "__main__":
    with LookingGlass() as what:
        print("hi bill and tom")
        print(what)
        a=123
    print(what)
    print(a)