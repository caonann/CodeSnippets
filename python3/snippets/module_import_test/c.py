import sys
from os.path import abspath, dirname, join

sys.path.append(join(abspath(dirname(__file__))))
import a

print("c import a")


class A:
    def __init__(self) -> None:
        self.a = 1


class B:
    def __init__(self) -> None:
        self.b = 1
