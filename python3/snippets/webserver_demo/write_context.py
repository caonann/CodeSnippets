def write(point, path_str, value):
    """
    指定一个 PATH 来写入字典。
    >>>write(map_point, "a.0.b", 1)
    >>>write(map_point, "a.1.c", "skip")
    """

    _point = point
    pre_point = _point
    p = [i for i in path_str.split(".") if i]
    i = 0
    if not p:
        return

    while True:
        if i == len(p):
            pre_point[keyname] = value
            break
        keyname = p[i]
        if keyname.isdigit():
            keyname = int(keyname)
        if keyname in _point:
            pre_point = _point
            _point = _point[keyname]
            i += 1
            continue

        if keyname not in _point:

            # 创建节点
            _point[keyname] = {}

            pre_point = _point
            _point = _point[keyname]
            i += 1

    return point


if __name__ == "__main__":
    point = {}
    write(point, ".e", "eee")
    print(point)
    write(point, "a.b.c", "123")
    print(point)
    write(point, "a.1.d", "456")
    print(point)
