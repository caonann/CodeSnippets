class DataType:
    """基本DataType"""

    def __init__(self,
                 required=False,
                 default=None,
                 validator=None,
                 optional=None,
                 autofill=False,  # 是否自动填充
                 disable=None,
                 deprecated=False,
                 list_limit=10,
                 list_validator=None,
                 mutex=None,
                 requirements={},
                 empty_list_enable=False,
                 **wargs):

        if bool(default) and required:
            raise #exception.InvalidParameter.Coexist(value='default(True) and required(True)')
        self.nullable = not required
        self.optional = optional
        self.validator = validator
        self.autofill = True if default is not None else autofill
        self.default_value = default
        self.disable = [] if not disable else disable
        self.list_limit = list_limit
        self.deprecated = deprecated
        self.mutex = [] if not mutex else mutex
        self.list_validator = list_validator
        self.desc = wargs['desc'] if wargs.get('desc') else self.__doc__
        self.requirements = requirements
        self.empty_list_enable = empty_list_enable

    def abspath_list_validator(self, key, data):
        try:
            _data = bone.get_path_point(data, key)
            _data = list(bone.convert_dicts_to_lists(
                copy.deepcopy(_data)).values())
            _v = self.list_validator
            if isinstance(_v, list):
                validators = _v
            else:
                validators = [_v]
            for _validator in validators:
                _validator(key, _data)

        except KeyError:
            raise

    def auto_convert(self, data):
        return data

    def abspath_validator(self, key, data):
        try:
            _data = bone.get_path_point(data, key)
            _data = self.auto_convert(_data)
            if isinstance(_data, list):
                _v = self.list_validator
            else:
                _v = self.validator
            if isinstance(_v, list):
                validators = _v
            else:
                validators = [_v]
            for _validator in validators:
                _validator(key, _data)

        except KeyError:
            raise

    def match_ex(self, key, data):
        debug(f'{key} 分解EX')
        _data = bone.get_path_point(data, key)
        if self.optional:
            if _data not in self.optional:
                raise exception.InvalidParameterValue(
                    parameter=key, value=_data)
        _ = self.match(key, data)

        return _

    def match(self, key, data):
        bone.schema_core_loop(
            bone.create_virtual_point(key, self.__class__.attrs),  # 规则字典,
            data,  # 源数据字典,
            path=key,  # 当前递归的节点
        )
        return _


class Root(DataType):
    # (TODO) 根 DataType。
    pass


class String(DataType):
    """字符串类型"""

    def match(self, key, data):
        _data = bone.get_path_point(data, key)
        if not isinstance(_data, str):
            raise exception.InvalidParameterValue(parameter=key, value=_data)
        default = self.default_value
        if data:
            bone.write_context(key, _data)
            return
        if default:
            bone.write_context(key, default(key) if callable(
                default) else default)


class Integer(DataType):
    """整数类型"""

    def match(self, key, data):
        _data = bone.get_path_point(data, key)
        is_integer = isinstance(_data, int) or (
            isinstance(_data, str) and _data.isdigit())
        if not is_integer:
            raise exception.InvalidParameterValue(parameter=key, value=_data)
        default = self.default_value
        if data:
            bone.write_context(key, int(_data))
            return
        if self.default_value:
            bone.write_context(key, default(key) if callable(
                default) else default)

    def match_ex(self, key, data):
        debug(f'{key} 分解EX')
        _data = bone.get_path_point(data, key)
        if self.optional:
            if str(_data) not in map(str, self.optional):
                raise exception.InvalidParameterValue(
                    parameter=key, value=_data)
        _ = self.match(key, data)
        return _


class Boolean(DataType):
    """布尔类型"""

    def auto_convert(self, _data):
        if _data in {'True', True, 'TRUE', 'true'}:
            return True
        if _data in {'False', False, 'FALSE', 'false'}:
            return False

    def match(self, key, data):
        _data = bone.get_path_point(data, key)
        if _data in {'True', True, 'TRUE', 'true'}:
            bone.write_context(key, True)
            return
        if _data in {'False', False, 'FALSE', 'false'}:
            bone.write_context(key, False)
            return
        raise exception.InvalidParameterValue(parameter=key, value=_data)