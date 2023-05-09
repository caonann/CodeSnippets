def veryBigHello():
    i = 0
    while i < 10:
        i += 1
        yield "hello"


for i, word in enumerate(veryBigHello()):
    print(i, word)
