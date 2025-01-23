from typing import Optional

from pydantic import BaseModel, Field


class TestCModel(BaseModel):
    c: str


class TestBaseModel(BaseModel):
    a: int
    b: str
    c: Optional[TestCModel] = Field(default=None)


a = TestBaseModel(a=1, b="2", c=TestCModel(c="3"))
a.model_dump()
aa = a.model_dump()
print(a.c.c)
