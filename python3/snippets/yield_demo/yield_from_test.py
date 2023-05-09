def a():
    if False:
        yield from "aaa"


b = a()
print(type(b))


def c():
    if False:
        yield "bbbb"
    print("kkkk")
    return "kkkk"


cc = c()
print(type(cc))
print(cc())
