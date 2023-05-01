import requests
PROXY_DOMAIN="api.openai.com"
#等效于openai.ChatCompletion.create(**kwargs)
def proxy_chat_completion(openai_key,**kwargs):
    stream = kwargs.get("stream", False)
    r = requests.post(
        f"https://{PROXY_DOMAIN}/v1/chat/completions",
        headers={
            "Content-Type": "application/json",
            "Authorization": f"Bearer {openai_key}",
        },
        json=kwargs,
        stream=stream,
    )
    
    if stream:
        return (line for line in r.iter_lines() if line)
    else:
        return r.json()
       
#等效于openai.Completion.create(**kwargs)
def proxy_completion(openai_key,**kwargs):
    stream = kwargs.get("stream", False)
    r = requests.post(
        f"https://{PROXY_DOMAIN}/v1/completions",
        headers={
            "Content-Type": "application/json",
            "Authorization": f"Bearer {openai_key}",
        },
        json=kwargs,
        stream=stream,
    )
    
    if stream:
        return (line for line in r.iter_lines() if line)
    else:
        return r.json()
        
import unittest
import os
class TestCompletion(unittest.TestCase):

    def test_chatcompletion(self):
        api_key = os.getenv("OPENAI_API_KEY")
        input={
            "stream": True,
            "model": "gpt-3.5-turbo1",
            "messages": [{"role": "user", "content": "请例句唐诗三百首"}],
        }
        r = proxy_chat_completion(api_key,**input)
        for line in r:
            print(line)