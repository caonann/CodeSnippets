#!/usr/bin/env python
# coding=utf-8
import context

class Context(object):
    """
        请求级别级别上下文
        协议要求：
            * 实现 memorize 装饰器
            * 实现 in 操作符
            * get 方法
            * 动态获取设置属性
            * 重载 [] 运算符，支持获取与设置
    """

    def memorize(self, function):
        def __memorize(*args, **kwargs):
            import context
            from copy import deepcopy
            cache = context.cache
            key = compute_key(function, args, kwargs)
            if key in cache:
                return deepcopy(cache[key])

            result = function(*args, **kwargs)
            cache[key] = result
            return deepcopy(result)

        return __memorize

def test_fun():
    data={"key1":"123","key2":"456","key3":"567"}
    return data

test = Context.memorize(test_fun)
print("test",test())