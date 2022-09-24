class Base:
    code = 1
    err_code = code

    def __init__(self, code=None, err_code=None) -> None:
        if code:
            self.code = code
        if err_code:
            self.err_code = err_code

    def __repr__(self) -> str:
        return f"code:{self.code} err_code:{self.err_code}"


class Child(Base):
    def __init__(self, code=None, err_code=None) -> None:
        err_code = code = self.code
        super().__init__(code, err_code)

    code = 2


c = Child()
print(c)
