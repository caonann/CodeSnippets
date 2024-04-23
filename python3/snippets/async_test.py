import asyncio


async def task(n):
    if n == 2:
        raise "err"
    await asyncio.sleep(1)
    return n * n, "a", "b"


async def main():
    # 并发运行三个task()协程
    results = await asyncio.gather(task(1), task(2), task(3), return_exceptions=True)
    print(results)  # 将会输出: [1, 4, 9]
    for result in results:
        if isinstance(result, Exception):
            print(f"Caught an exception: {result}")
        else:
            print(f"Task result: {result}")

    return results


ret = asyncio.run(main())
print("ret is", ret)
