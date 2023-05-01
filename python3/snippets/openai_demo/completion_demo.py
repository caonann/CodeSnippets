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
    "prompt": "Say this is a test",
    "max_tokens": 7,
    "temperature": 0,
}

r = requests.post(
    "https://api.openai.com/v1/completions", headers=headers, json=json_data
)
print(json.dumps(r.json()))
