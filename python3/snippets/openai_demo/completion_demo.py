import json
import os

import requests

OPENAI_API_KEY = os.getenv("OPENAI_API_KEY")

headers = {
    # Already added when you pass json= but not when you pass data=
    # 'Content-Type': 'application/json',
    "Authorization": f"Bearer {OPENAI_API_KEY}",
}

json_data = {
    "model": "text-davinci-003",
    "prompt": "唐诗三百首",
    "max_tokens": 700,
    #"temperature": 1,
}

r = requests.post("https://api.openai.com/v1/completions", headers=headers, json=json_data)
print(json.dumps(r.json(), ensure_ascii=False, indent=4))
