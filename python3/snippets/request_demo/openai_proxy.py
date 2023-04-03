import asyncio
import os

import openai

openai.api_key = os.getenv("OPENAI_API_KEY")
https_domain = os.getenv("HTTPS_DOMAIN")
print(https_domain)
if not https_domain:
    print("with out https domain")
    exit(0)
# "https": f"https://{https_domain}",
openai.proxy = f"https://{https_domain}"

completion = openai.ChatCompletion.acreate(
    model="gpt-3.5-turbo", messages=[{"role": "user", "content": "Hello!"}]
)
asyncio.run(completion)
print(completion.choices[0].message)
