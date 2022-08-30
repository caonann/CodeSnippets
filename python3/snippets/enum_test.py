from enum import Enum


class APPState(Enum):
    AUDITING = 0  # 审核中
    ACCEPTED = 1  # 已通过
    REJECTED = 2  # 已拒绝

    def is_accept_state(self):
        print(self.name)
        print(self is self.AUDITING)
        print(self is self.ACCEPTED)
        print(self in (self.ACCEPTED, self.REJECTED))
        print(self in (self.AUDITING, self.REJECTED))


print(APPState.__members__.items())

if 1 in APPState.__members__:
    print("yes")

for name, member in APPState.__members__.items():
    print(member.value)

if 1 in [member.value for _, member in APPState.__members__.items()]:
    print("yes")


# 判断一个类型是否在枚举中
def check_param(data, enumType):
    return data in [
        member.value for _, member in getattr(enumType, "__members__").items()
    ]


ret = check_param(3, APPState)
print(f"{ret=}")

if isinstance(APPState, Enum):
    print("appstate is enum")

if issubclass(APPState, Enum):
    print("appstate is subclass")

if isinstance(APPState.AUDITING, Enum):
    print("APPState.AUDITING is enum")

APPState.AUDITING.is_accept_state()
