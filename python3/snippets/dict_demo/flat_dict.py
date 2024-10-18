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