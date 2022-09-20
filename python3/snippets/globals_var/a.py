import b


def func_a(a):
    b.g_b = a


func_a(111)
print(b.g_b)
b.print_b()
if b.g_b:
    print("abc")
