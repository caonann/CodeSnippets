def create_virtual_point(path_str, value):
    """
    创建虚拟节点。
    >>>create_virtual_point("a.b",[1,2,3])
    {"a":{"b":[1,2,3]}}
    """
    if not path_str:
        return value
    p = [i for i in path_str.split(".") if i][::-1]

    for i in p:
        if i in [str(i) for i in range(10)]:
            struct = []
            struct.append(value)
            value = struct
        else:
            struct = {}
            struct[i] = value
            value = struct
    return value


if __name__ == "__main__":
    res = create_virtual_point("a.b.c", {"aaa": 123, "bbb": "bbb", "cccc": True})
    print(res)
    res = create_virtual_point("a.0.c.11.9", "list")
    print(res)
    res = create_virtual_point("a.b.c", {"a":{"b":{"c":"dddd"}}})
    
    print(res)