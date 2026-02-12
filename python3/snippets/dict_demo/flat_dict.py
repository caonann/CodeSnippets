# pip install flatdict
from flatdict import FlatDict, FlatterDict

# 将嵌套字典扁平化
nested_dict = {"a": {"b": {"c":{"d":123123}}}, "c": {"d": "value2"},"e":[{"abc":{"kkk":"333"}},{"def":456}]}
flat = FlatDict(nested_dict, delimiter='.')
print(dict(flat))  # 输出: {'a.b': 'value', 'c.d': 'value2'}

# 将扁平字典转换为嵌套字典
flat_dict = {'a.b': 'value', 'c.d': 'value2'}
nested = FlatterDict(flat_dict, delimiter='.')
print(dict(nested))  # 输出: {'a': {'b': 'value'}, 'c': {'d': 'value2'}}


def convert_dict_format(flat_dict):
    nested_dict = {}
    for key, value in flat_dict.items():
        keys = key.split('.')
        current = nested_dict
        for i, k in enumerate(keys):
            if i == len(keys) - 1:
                current[k] = value
            else:
                if k not in current:
                    current[k] = {}
                current = current[k]
    return nested_dict

# 用flatdict生成一批dict用来验证convert_dict_format的正确性
import random

def generate_flat_dict(depth, width, max_items=1000):
    def generate_dict(current_depth, max_depth, max_width, remaining_items):
        if current_depth > max_depth or remaining_items <= 0:
            return {}
        
        current_width = min(random.randint(1, max_width), remaining_items)
        result = {}
        for _ in range(current_width):
            key = str(random.randint(1, max_width))
            value = generate_dict(current_depth + 1, max_depth, max_width, remaining_items // current_width)
            if value:
                result[key] = value
            else:
                result[key] = str(random.randint(1, 1000))  # 生成一个随机字符串值
            remaining_items -= 1
        return result

    return generate_dict(1, depth, width, max_items)

# 生成一个深度为3，宽度为2的扁平字典
flat_dict = generate_flat_dict(3, 2)
print("flat_dict",flat_dict)

# 使用convert_dict_format将扁平字典转换为嵌套字典
nested_dict = convert_dict_format(flat_dict)
print(nested_dict)

# 多生成一些用例
for i in range(10):
    flat_dict = generate_flat_dict(30, 20)
    nested_dict = convert_dict_format(flat_dict)
    #print(nested_dict)
    assert nested_dict == flat_dict
