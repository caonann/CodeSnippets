class Context:
    """
    请求级别级别上下文
    协议要求：

        * 实现 in 操作符
        * get 方法
        * 动态获取设置属性
        * 重载 [] 运算符，支持获取与设置
    """

    def __contains__(self, name):
        return name in self.__dict__

    def __call__(self):
        self.__dict__ = {}

    def get(self, name, default=None):
        try:
            return self.__dict__[name]
        except KeyError:
            return default

    def __getitem__(self, name):
        return self.__dict__[name]

    def __getattr__(self, name):
        return self.__dict__[name]

    def __setitem__(self, name, val):
        self.__dict__[name] = val

    def __setattr__(self, name, val):
        self.__dict__[name] = val

    def keys(self):
        return self.__dict__.keys()


if __name__ == "__main__":
    c = Context()
    print(c.get("a"))

    c.url = "http:abc.txt"
    print(c.url)
    print(c.keys())
    if "url" in c:
        print("yes")
    print(c["url"])
    c["name"] = "hahah"
    print(c.name)
