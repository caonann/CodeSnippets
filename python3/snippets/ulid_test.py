"""参考
https://mp.weixin.qq.com/s?__biz=MzA4MjEyNTA5Mw==&mid=2652601507&idx=2&sn=3696a016bfa54e448e36445f3b07b703&chksm=846554e9b312ddff96c0b715c68dc10a69d988a2d85ffec82ac67c41786e7f07521a61373341&mpshare=1&scene=1&srcid=0104VS4QOfFvNoAXPmty8f4e&sharer_shareinfo=be146d044cb082615f0bc081a78bff8e&sharer_shareinfo_first=be146d044cb082615f0bc081a78bff8e#rd
"""
import uuid

# pip install ulid-py
import ulid

if __name__ == "__main__":
    value = uuid.uuid4()
    value = ulid.from_uuid(value)
    print(value)
