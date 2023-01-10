# -*- coding: utf-8 -*-
class MyCustomError(Exception):
    pass

a = dict(a=123, b="bbb")
try:
    raise MyCustomError("my error")
    _ = a["ccc"]
    print("succ")

except KeyError as e:
    print(e, type(e))
except MyCustomError as e:
    print(e)
except:
    print("default")
