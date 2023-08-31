import asyncio
from concurrent.futures import ThreadPoolExecutor
from uuid import uuid4

import uvicorn
from fastapi import FastAPI, Path, Query

app = FastAPI()
import time

import requests


@app.get("/benchmark")
async def benchmark_handler(q: int = Query(None, alias="enable_sleep")):
    uid = str(uuid4())
    if q:
        await asyncio.sleep(1)
    return {"message": f"Benchmark path hit done! {uid}"}


executor = ThreadPoolExecutor()


def blocking_task():
    r = requests.get("http://localhost:8000/benchmark")
    return r.content


@app.get("/downstream")
async def downstream_handler():
    start = time.perf_counter()
    response = await asyncio.get_event_loop().run_in_executor(executor, blocking_task)
    time_diff = time.perf_counter() - start
    return {"message": f"Downstream path hit done! {response} {time_diff}"}


if __name__ == "__main__":
    uvicorn.run(app, host="0.0.0.0", port=8000)
