def flatten_dict(nested_dict, prefix='', delimiter='.'):
    flat_dict = {}
    for key, value in nested_dict.items():
        new_key = prefix + key if prefix else key
        if isinstance(value, dict):
            flat_dict.update(flatten_dict(value, new_key + delimiter, delimiter))
        elif isinstance(value, list):
            for i, item in enumerate(value):
                item_key = f"{new_key}{delimiter}{i}"
                if isinstance(item, dict):
                    flat_dict.update(flatten_dict(item, item_key + delimiter, delimiter))
                else:
                    flat_dict[item_key] = item
        else:
            flat_dict[new_key] = value
    return flat_dict

def convert_flat_dict_to_nested_dict(nested_dict, prefix="", delimiter="."):
    """
    将嵌套字典扁平化，保留数组结构
    例如：{"a":{"b":1, "c":[1,2,3]}} 转换为 {"a.b":1, "a.c":[1,2,3]}
    """
    flat_dict = {}
    for key, value in nested_dict.items():
        new_key = f"{prefix}{key}" if prefix else key
        if isinstance(value, dict):
            flat_dict.update(convert_flat_dict_to_nested_dict(value, new_key + delimiter))
        else:
            flat_dict[new_key] = value
    return flat_dict

# 测试函数
nested_dict = {"a": {"b": {"c":{"d":123123}}}, "c": {"d": "value2"}, "e":[{"abc":{"kkk":"333"}},{"def":456}],"f":123}
#flat = flatten_dict(nested_dict)
flat =convert_flat_dict_to_nested_dict(nested_dict)
print(flat)