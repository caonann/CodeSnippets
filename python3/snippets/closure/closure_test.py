def make_avg():
    total = 0
    count = 0

    def avg(new_val):
        nonlocal total, count #nonlcoal把变量标记为自由变量，
        total += new_val
        count += 1
        return total / count

    return avg


obj = make_avg()
print(obj(10))
print(obj(11))
