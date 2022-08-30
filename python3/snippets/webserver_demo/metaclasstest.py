class MetaDataType(type):
    def __new__(mcs, name, bases, dct):
        _ = [(k, v) for k, v in list(dct.items())]
        dct["attrs"] = {}
        for k, v in _:
            dct["attrs"][k] = v

        return type.__new__(mcs, name, bases, dct)


class DataType(object, metaclass=MetaDataType):
    def __init__(self) -> None:
        print("init datatype")
        self.aaa = "aaa"
        self.bbb = "bbb"
        self.ccc = 1

    def show(self):
        print(self.__class__.attrs)


if __name__ == "__main__":
    d = DataType()
    print(d.__class__.attrs)
    d.show()
