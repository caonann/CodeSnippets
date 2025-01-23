from enum import Enum

from pydantic import BaseModel, Field


class APPState(Enum):
    AUDITING = "AUDITING"
    REJECTED = "REJECTED"
    ACCEPTED = "ACCEPTED"


class Req(BaseModel):
    aaa: str = Field(default=APPState.AUDITING)


a = Req()
print(a.model_dump_json())
print(a.model_dump())
