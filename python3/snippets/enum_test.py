from enum import Enum


class APPState(Enum):
    AUDITING = 0  # 审核中
    ACCEPTED = 1  # 已通过
    REJECTED = 2  # 已拒绝


print(APPState.__members__.items())

if 1 in APPState.__members__:
    print("yes")

for name, member in APPState.__members__.items():
    print(member.value)

if 1 in [member.value for _, member in APPState.__members__.items()]:
    print("yes")
