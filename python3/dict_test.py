#!/usr/bin/env python
# coding=utf-8

dict_test={"abc":123}
for i in range(3):
    dict_test.setdefault("arry",[5]).append(i)
print(dict_test)

conf=[{
    "id":123,
    "key":"key-123"
},{
    "id":456,
    "key":"key-456"
}]
'''数组转换为dict'''
tmpmap=[(_['id'],_['key']) for _ in conf]
print(tmpmap,dict(tmpmap),dict(tmpmap).get(123,False))