# 测试threadpool多线程作为客户端能否真正并行请求下游
import functools
import time
from concurrent.futures import ThreadPoolExecutor

import requests


def req(i: int):
    print(f"reqing {i}")
    r = requests.get("http://localhost:8000/benchmark")
    return r.content


def metric(fn):
    @functools.wraps(fn)
    def wrapper(*args, **kw):
        start = time.perf_counter()
        ret = fn(*args, **kw)
        end = time.perf_counter()
        print("{} took {} ms".format(fn.__name__, (end - start) * 1000))
        return ret

    return wrapper


@metric
def process():
    with ThreadPoolExecutor(max_workers=600) as executor:
        rets = executor.map(req, [1] * 600)
        for ret in rets:
            print(ret)


if __name__ == "__main__":
    for i in range(100):
        process()
    print("done")
