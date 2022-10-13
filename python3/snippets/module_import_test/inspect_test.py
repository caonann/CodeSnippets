import inspect

import c


def get_class(arg):

    clsmembers = inspect.getmembers(arg, inspect.isclass)
    class_members = [c for _, c in clsmembers]
    print(clsmembers)
    return class_members


classes = get_class(c)
print(classes)
for cc in classes:
    if type(c.A()) is cc:
        print("yes")

print(c.A == classes[0])
if isinstance(classes[0](), c.A):
    print("yes yes")
