def get_path_point(_point, path_str="", zero=False):
    """
    通过一个指针，通过指定的path得到新指针，未来可以查表化。
    """
    print(f"get_path_point {path_str}{_point}")
    if not path_str:
        return _point
    p = [int(i) if i.isdigit() else i for i in path_str.split(".") if i]
    for i in p:
        if isinstance(_point, list):
            _point = _point[0 if zero else int(i)]
        else:
            if i in _point:
                _point = _point[i]
            else:
                _point = _point[str(i)]
    return _point


if __name__ == "__main__":
    dict_1 = {"a": ["aa1", "aa2"], "b": {"bb": "bbb"}, "c": 1}
    print(get_path_point(dict_1, ".a"))
    print(get_path_point(dict_1, ".a.0"))
    print(get_path_point(dict_1, ".b.bb"))
    print(get_path_point(dict_1, ".c"))
