#!/usr/bin/env python
# coding=utf-8

dict_test={"abc":123}
for i in range(3):
    dict_test.setdefault("arry",[5]).append(i)
print(f"{i=}")
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

# 合并两个dict
dict_a={"a":123,"b":456}
dict_b={"b":567,"c":789}
dict_merge={**dict_a,**dict_b}
print(dict_merge)

ret = dict_merge.update({"update":"test"})
print(dict_merge)
print(ret)


judgestr='ROOT'
if judgestr in ('root','boot'):
    print("hello")
else:
    print("not found")


tmpmap={}
tmpmap.setdefault("def", {}).setdefault("abc",[]).append("abc")
tmpmap.setdefault("def", {}).setdefault("abc",[]).append("abc")
tmpmap.setdefault("def", {}).setdefault("abc",[]).append("abc")
tmpmap.setdefault("def", {}).setdefault("abc",[]).append("abc")
tmpmap.setdefault("def", {}).setdefault("abc",[]).append("abc")
tmpmap.setdefault("def", {}).setdefault("abc",[]).append("abc")
print(tmpmap)
print(tmpmap["def"]["abc"][2:])

if " ":
    print("yes")

test_dict ={
    'a':"aaaa",
    'b':'bbbb',
    'c':'cccc'
}

for key,val in test_dict.items():
    if val == 'bbbb':
        test_dict[key]='kkkk'
    
print(test_dict)

a = {}
if "abc" in a:
    print('aaa')

_ = ','.join(["ababab",'kkkk'])
print(_)
_ = ','.join([])
print(_)

for i in range(1,4):
    print(i)
print(f"{i=}")