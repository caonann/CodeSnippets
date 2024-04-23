import dataclasses
from dataclasses import dataclass


@dataclass
class A:
    a: int = 0
    b: bool = False

    def __repr__(self) -> str:
        return f"a:{self.a},b:{self.b}"


aa = A(a=123, b=True)
print(aa)
