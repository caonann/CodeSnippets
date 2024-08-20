import asyncio
from contextlib import asynccontextmanager

import uvicorn
from fastapi import FastAPI


async def func():
    while True:
        print("this is func")
        await asyncio.sleep(1)
@asynccontextmanager
async def lifespan(app: FastAPI):
    print("begin lifespan")
    # 在应用启动时启动后台任务
    task = asyncio.create_task(
        func()
    )
    yield
    # 在应用关闭时取消后台任务
    print("end lifespan")
    task.cancel()
    try:
        await task
        print("cancel task")
    except asyncio.CancelledError:
        print("task cancelled")
    except Exception as e:
        print(e)
       
        
app = FastAPI(lifespan=lifespan)


    

@app.get("/")
def read_root():
    return {"Hello": "World"}   
    
if __name__ =="__main__":
    uvicorn.run(app, host="0.0.0.0", port=8088)