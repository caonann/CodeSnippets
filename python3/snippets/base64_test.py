import base64
ret = base64.b64encode(b"hello world")
print(ret)
print(base64.b64decode(ret))

with open('/tmp/VCG41N1035476302.jpg',"rb") as f:
    r = f.read()
    encode_str = base64.b64encode(r)
    print(base64.b64decode(encode_str))