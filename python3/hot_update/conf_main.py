import json
import os

import uvicorn
from fastapi import FastAPI, HTTPException
from watchdog.events import FileSystemEventHandler
from watchdog.observers import Observer

app = FastAPI()

config_path = "config.json"
config = {}

"""
热更新配置文件
"""


def load_config():
    global config
    if os.path.exists(config_path):
        with open(config_path, "r") as f:
            config = json.load(f)
    else:
        raise HTTPException(status_code=500, detail="Config file not found.")


load_config()


class ConfigEventHandler(FileSystemEventHandler):
    def on_modified(self, event):
        if event.src_path == config_path:
            load_config()
            print("Config reloaded!")
        else:
            print(f"{event.src_path} == {config_path}")


event_handler = ConfigEventHandler()
observer = Observer()
observer.schedule(event_handler, path="config.json", recursive=False)
observer.start()


@app.get("/")
async def read_root():
    return {"config": config}


if __name__ == "__main__":
    uvicorn.run(
        app, host="0.0.0.0", port=8888, log_level="debug", timeout_keep_alive=30
    )
