from dataclasses import asdict, dataclass


@dataclass
class MyDataClass:
    field1: str = None
    field2: int = None

# 使用MyDataClass
my_data_class = MyDataClass(field1="Value1", field2=42)

# 访问和打印
print(my_data_class.field1)  # 输出: Value1
print(my_data_class.field2)  # 输出: 42
my_data_class.field1 = "123"
print(my_data_class)
print(asdict(my_data_class))