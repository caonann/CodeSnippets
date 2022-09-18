import base64

ret = base64.b64encode(bytes("你好啊 abc", encoding="utf-8")).decode("utf-8")
print(f"{ret=}")

decode_content = base64.b64decode(ret)
print(f"{decode_content=}")
decode_content = decode_content.decode("utf-8")
print(f"{decode_content=}")
_ = decode_content.split(" ")
print(_)

# with open('/tmp/VCG41N1035476302.jpg',"rb") as f:
#    r = f.read()
#    encode_str = base64.b64encode(r)
#    print(base64.b64decode(encode_str))


# _ = base64.b64decode(bytes('b5pC656iL', encoding="utf-8"))
# print(_)
