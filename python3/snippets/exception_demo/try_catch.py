#!/usr/bin/env python
# coding=utf-8

try:
    assert 1 == 0, "1 != 0"
    print("pass")
except Exception as e:
    print(f"exception {e}")
    import time

    time.sleep(1)


print("succ")


class APIException(Exception):
    message = "未知错误。"
    code = "InternalError"

    # 如果入参是一个列表，需要格式化，而不能依赖python的repr，否则，会暴露后端语言。
    def __init__(self, **kwargs):
        # super().__init__(self,kwargs)
        print(kwargs)
        self.kwargs = kwargs

        self.message = "aaaa"

    def __str__(self):
        return self.message


try:
    raise APIException(message="123")
except APIException as e:
    print(f"this is except {e}")
