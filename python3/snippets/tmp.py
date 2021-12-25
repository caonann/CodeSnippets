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