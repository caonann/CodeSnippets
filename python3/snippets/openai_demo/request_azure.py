import json
import os
from typing import Iterator, Optional

import requests
from sseclient import SSEClient

https_domain = os.getenv("HTTPS_DOMAIN")
openai_key = os.getenv("OPENAI_API_KEY")
print(https_domain, openai_key)


def parse_stream_helper(line: bytes) -> Optional[str]:
    if line:
        if line.strip() == b"data: [DONE]":
            # return here will cause GeneratorExit exception in urllib3
            # and it will close http connection with TCP Reset
            return None
        if line.startswith(b"data: "):
            line = line[len(b"data: ") :]
            return line.decode("utf-8")
        else:
            return None
    return None


def parse_stream(rbody: Iterator[bytes]) -> Iterator[str]:
    for line in rbody:
        _line = parse_stream_helper(line)
        if _line is not None:
            yield _line


def event_stream():
    r = requests.post(
        f"{https_domain}/openai/deployments/gpt-35-turbo-0301/chat/completions?api-version=2023-03-15-preview",
        headers={"Content-Type": "application/json", "api-key": f"{openai_key}"},
        json={
            "stream": True,
            "messages": [{"role": "user", "content": "请例句唐诗三百首"}],
        },
        stream=True,
    )

    
    for line in r.iter_lines():
        if line:
            yield line
    """"""

    # return (json.loads(line) for line in parse_stream(r.iter_lines()))
    return SSEClient(r)



for event in event_stream():
    print(event)
"""
for event in event_stream().events():
    print(event.data)
"""