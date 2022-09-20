b = 123


def f2(a):
    print(a)
    print(b) #这行会报错，因为有下面的b的赋值，函数会判断b是一个局部变量
    b = 3 


f2(2)
