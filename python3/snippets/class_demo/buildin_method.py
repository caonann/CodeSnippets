# -*- coding: utf-8 -*-

from typing import Any


class A:
    def __getattribute__(self, __name: str) -> Any:
        print(f"get attr ", __name)
        return __name

    def __getitem__(self, __name: str) -> Any:
        print(f"get item ", __name)
        return __name

    def __call__(self, *args: Any, **kwds: Any) -> Any:
        print("calling")

    def call(self, attr_name):
        print("call")


a = A()
a.post
a["get"]
a("abc")

aa = [1, 2, 3]
for index, _ in enumerate(aa):
    print(index)
    print(index == len(aa) - 1)
