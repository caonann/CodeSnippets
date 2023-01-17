from abc import ABC, abstractmethod


class Base(ABC):
    code = 1
    err_code = code

    def __init__(self, code=None, err_code=None) -> None:
        if code:
            self.code = code
        if err_code:
            self.err_code = err_code

    def __repr__(self) -> str:
        return f"code:{self.code} err_code:{self.err_code}"

    @abstractmethod
    def pure_virtual_func(self):
        pass

    @property
    @abstractmethod
    def name(self):
        return "hulk"


class Child(Base):
    def __init__(self, code=None, err_code=None) -> None:
        err_code = code = self.code
        super().__init__(code, err_code)

    code = 2

    def pure_virtual_func(self):
        print("this is sub class")

    @property
    def name(self):
        return "name"


c = Child()
print(c)
print(c.name)