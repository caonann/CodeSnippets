import base64

ret = base64.b64encode(b"hello world")
print(ret)
decode_content = base64.b64decode(ret)
decode_content = decode_content.decode("ascii")
_ = decode_content.split(" ")
print(_)

# with open('/tmp/VCG41N1035476302.jpg',"rb") as f:
#    r = f.read()
#    encode_str = base64.b64encode(r)
#    print(base64.b64decode(encode_str))
