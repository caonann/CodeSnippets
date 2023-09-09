a = ["aabb"]
b = [["aa", "bb"]]
for aa, bb in zip(a, b):
    print(aa)
    print(bb)

a = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(zip(*a))
print(list(zip(*a)))
print(list(zip(*a))[::-1])
