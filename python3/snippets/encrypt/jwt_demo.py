import jwt

key = "aabbccdd"


def encrypt_json_dict(content: dict) -> str:
    return jwt.encode(content, key, algorithm="HS256")


def decode_to_json_dict(content: str) -> dict:
    return jwt.decode(content, key, algorithms=["HS256"])


if __name__ == "__main__":
    ret = encrypt_json_dict({"你好啊": "11234"})
    print(ret)
    ret = decode_to_json_dict(ret)
    print(ret, type(ret))
