# -*- coding: utf-8 -*-

import base64
import hashlib
import hmac
import random
import time
import uuid
from hashlib import sha1
from urllib.parse import quote

g_changwai_uri = "url_a"
access_key = "abcdefg"


def hash_hmac(query_str, key, encry_method):
    hmac_code = hmac.new(key.encode(), query_str.encode(), encry_method).digest()
    return base64.b64encode(hmac_code).decode()


def get_signature(params, uri):
    CHANGWAI_URI = g_changwai_uri
    timestamp = int(time.time())
    nonce = random.randint(100000, 999999)
    params["access_key"] = access_key
    params["timestamp"] = timestamp
    params["nonce"] = nonce

    params_list = []
    for i in sorted(params):
        params_list.append("%s=%s" % (i, params[i]))

    query_str = CHANGWAI_URI + uri + "&".join(params_list)
    signature = hash_hmac("GET" + query_str, access_key, "sha1")
    query_str += "&signature=%s" % (quote(signature))
    return query_str


def hmac_test():
    key = "abcabc"
    hmac_infos = [
        (key, "a=111&b=abcabc&n=222"),
        (key, "a=112&b=abcabc&n=333"),
        (key, "a=113&b=abcabc&n=444"),
    ]
    for hmacs in hmac_infos:
        hmac_code = hmac.new(hmacs[0].encode(), hmacs[1].encode(), sha1).digest()
        base64_code = base64.b64encode(hmac_code).decode()
        print(base64_code)


def verify(headers: dict, target_sig: str) -> bool:
    uri = "query_api?"
    sig = get_signature(headers, uri)
    print(f"{sig=} vs {target_sig=}")


def generate_sig():
    timestamp = str(int(time.time()))
    paasid = "abcabc"
    paasToken = "adeadeade"
    nonce = str(uuid.uuid4())
    signature = hashlib.sha256()
    string = f"{timestamp}{paasToken}{nonce}{timestamp}"
    signature.update(string.encode())
    return signature.hexdigest().upper()  # 输出大写的结果


if __name__ == "__main__":
    params = dict(a="aaa", b="bbb")
    uri = "query_api?"
    sig = get_signature(params=params, uri=uri)
    print(sig)
    # hmac_test()

    sig = generate_sig()
    print(sig)
