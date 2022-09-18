import random

# 世界人口数量前10位国家的电话区号
DIAL_CODES = [
    (86, "China"),
    (91, "India"),
    (1, "United States"),
    (62, "Indonesia"),
    (55, "Brazil"),
    (92, "Pakistan"),
    (880, "Bangladesh"),
    (234, "Nigeria"),
    (7, "Russia"),
    (81, "Japan"),
]

d1 = dict(DIAL_CODES)
print("d1:", d1.keys())
d2 = dict(sorted(DIAL_CODES))
print("d2:", d2.keys())
d3 = dict(sorted(DIAL_CODES, key=lambda x: x[1]))
print("d3:", d3.keys())
assert d1 == d2 and d2 == d3

# 验证在不断添加新元素的时候，已有元素键值顺序会不会改变,看例子没有改变,在迭代的时候改变可能会影响正在执行的迭代
source_keys = list(d1.keys())
new_keys = random.sample(range(1000, 100000000), 1000000)
source_keys.extend(new_keys)

print(f"{len(source_keys)=}")
for key in new_keys:
    d1.update({key: str(key)})

for d1_key, d2_key in zip(d1.keys(), source_keys):
    if d1_key != d2_key:
        print(f"{d1_key=} != {d2_key=}")
