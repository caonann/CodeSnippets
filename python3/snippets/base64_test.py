import base64
from urllib.parse import quote

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

test_input = {"request_id": "sample2-111", "a": "a param", "b": str(1), "c": str(True)}
q_string = "?" + "&".join(f"{quote(k)}={quote(v)}" for k, v in test_input.items())
print(q_string)
