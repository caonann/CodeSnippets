subet1 = "9.202.16.0/20"
subnet2 = "11.171.42.0/25"
subnet3 = "9.202.28.0/25"
print(subnet3.split(";"))
b = [subet1, subnet2] + subnet3.split(";")

print(b)

list_a = [
    ("11.171.41.10", "9.201.115.19"),
    ("11.171.41.11", "9.201.115.15"),
    ("11.171.41.12", "9.201.115.18"),
    ("11.171.41.14", "9.201.115.14"),
    ("11.171.41.15", "9.201.115.4"),
    ("11.171.41.16", "9.201.115.11"),
    ("11.171.41.17", "9.201.115.16"),
    ("11.171.41.3", "9.201.115.8"),
    ("11.171.41.7", "9.201.115.17"),
    ("11.171.41.8", "9.201.115.12"),
]

list_b = [
    ("11.171.41.3", "9.201.115.8"),
    ("11.171.41.12", "9.201.115.18"),
    ("11.171.41.10", "9.201.115.19"),
    ("11.171.41.7", "9.201.115.17"),
    ("11.171.41.17", "9.201.115.16"),
    ("11.171.41.14", "9.201.115.14"),
    ("11.171.41.16", "9.201.115.11"),
    ("11.171.41.8", "9.201.115.12"),
    ("11.171.41.15", "9.201.115.4"),
    ("11.171.41.11", "9.201.115.15"),
]

# https://stackoverflow.com/questions/1207406/how-to-remove-items-from-a-list-while-iterating
for index_a, ia in enumerate(list_a[:]):
    for index_b, ib in enumerate(list_b[:]):
        if ia[0] == ib[0] and ia[1] == ib[1]:
            list_a.remove((ia[0], ia[1]))
            list_b.remove((ib[0], ib[1]))

print(list_a, len(list_a))
print(list_b, len(list_b))


hidden_rsp_uri_path = ["/api/tts/get_tts_timestamp"]
if "/api/tts/get_tts_timestamp" in hidden_rsp_uri_path:
    print("yes")
