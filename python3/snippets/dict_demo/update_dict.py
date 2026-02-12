d1 = {"a":{"b":1,"c":2,"d":3},"bb":111}
d2 = {"a":{"b":22}}
#d1.update(d2)
#print(d1)

def update_nested_dict(d1, d2):
    for key, value in d2.items():
        if isinstance(value, dict):
            d1[key] = update_nested_dict(d1.get(key, {}), value)
        else:
            d1[key] = value
    return d1

res = update_nested_dict(d1,d2)
print(res)

