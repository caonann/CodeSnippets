import six


def convert_dicts_to_lists(args):
    """
    转换具有数字key的字典到列表。
    """
    if not isinstance(args, dict):
        return args
    for key in args.keys():
        if isinstance(args[key], dict):
            if args[key] == {}:
                continue
            first_subkey = next(six.iterkeys(args[key]))
            if isinstance(first_subkey, int) or first_subkey.isdigit():
                s = args[key]
                args[key] = [convert_dicts_to_lists(s[k]) for k in sorted(s)]
            # elif (first_subkey == 'value' and
            #        len(args[key]) == 1):
            #    args[key] = args[key]['value']
            else:
                s = args[key]
                args[key] = convert_dicts_to_lists(s)
        if isinstance(args[key], list):
            args[key] = [convert_dicts_to_lists(i) for i in args[key]]
    return args


if __name__ == "__main__":
    test_dict1 = {1: {"a": "b", "c": "d"}, "two": 2}
    ret1 = convert_dicts_to_lists(test_dict1)
    print(f"{ret1=}")

    test_dict2 = {1: {2: "b", 4: "d"}, "two": 2}
    ret2 = convert_dicts_to_lists(test_dict2)
    print(f"{ret2=}")

    test_dict3 = {1: {2: {2: "bbb", 1: "aaa"}, 4: "d"}, "two": 2}
    ret3 = convert_dicts_to_lists(test_dict3)
    print(f"{ret3=}")

    test_dict4 = {
        "staffname": "hulkcao",
        "staffid": 123,
        "session_id": "d6b54018-1dd3-4f13-bdb1-db7285063b05",
        "uri_path": "/api/sample/sample1",
        "start_time": 1661779167.145612,
        "a": "123",
        "b": 10,
        "c": True,
        "custom": {"name1": "hulk1", "name2": 1},
        "d": {"0": 123, "1": 456, "2": 789},
    }

    ret4 = convert_dicts_to_lists(test_dict4)
    print(f"{ret4=}")
    print(f"{test_dict4=}")
