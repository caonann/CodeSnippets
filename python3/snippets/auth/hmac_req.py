import hmac
import time
import uuid

import requests

timestamp = str(int(time.time()))
access_key = "aabbcc" #类似appid，标识是哪个应用，由后台分发
security_key = "abc"  # 私钥，后台分发，不可暴露
nonce = str(uuid.uuid4())
message = f"{timestamp}{security_key}{nonce}{timestamp}"
signature = hmac.new(security_key.encode(), message.encode(), "sha1").hexdigest().upper()

headers = {
    "ailab-access-key": access_key,
    "ailab-timestamp": timestamp,
    "ailab-nonce": nonce,
    "ailab-signature": signature,
}


url = "http://127.0.0.1:8080/api/sample/sample4"

data = {"a": 2}
response = requests.post(url, json=data, headers=headers)

ret = response.json()
print(ret)
