from fastapi import FastAPI, BackgroundTasks
import asyncio
import time

app = FastAPI()

async def periodic_task():
    while True:
        # 这里放你的上报逻辑
        print(f"Periodic task executed at {time.strftime('%X')}")
        await asyncio.sleep(10)  # 指定周期时间，例如10秒

@app.on_event("startup")
async def startup_event():
    asyncio.create_task(periodic_task())

@app.get("/")
async def read_root():
    return {"Hello": "World"}

if __name__ == "__main__":
    import uvicorn
    uvicorn.run(app, host="0.0.0.0", port=8000)