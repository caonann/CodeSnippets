class Context:
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
            from copy import deepcopy

            import context

            cache = context.cache
            key = compute_key(function, args, kwargs)
            if key in cache:
                return deepcopy(cache[key])

            result = function(*args, **kwargs)
            cache[key] = result
            return deepcopy(result)

        return __memorize

    def __contains__(self, name):
        return name in _get_current_context(tid_requestid_map[_tid()])

    def __call__(self):
        self.__dict__ = {}

    def get(self, name, default=None):
        if name == "__wrapped__":
            return False
        try:
            return _get_current_context(tid_requestid_map[_tid()])[name]
        except KeyError:
            return default

    def __init__(self):
        pass

    def __getitem__(self, name):
        return _get_current_context(tid_requestid_map[_tid()])[name]

    def __getattr__(self, name):
        if name == "__wrapped__":
            return
        return _get_current_context(tid_requestid_map[_tid()])[name]

    def __setitem__(self, name, val):
        _get_current_context(tid_requestid_map[_tid()])[name] = val

    def __setattr__(self, name, val):
        _get_current_context(tid_requestid_map[_tid()])[name] = val

    def keys(self):
        return _get_current_context(tid_requestid_map[_tid()]).keys()

