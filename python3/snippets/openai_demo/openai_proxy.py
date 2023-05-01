import asyncio
import os

import openai

openai.api_key = os.getenv("OPENAI_API_KEY")
https_domain = os.getenv("HTTPS_DOMAIN")
print(https_domain)


# openai.api_base = f"https://{https_domain}"
# openai.api_type = "azure"
# openai.api_version = "2023-03-15-preview"

completion = openai.ChatCompletion.create(
    # engine="gpt-35-turbo-0301",
    model="gpt-3.5-turbo",
    messages=[{"role": "user", "content": "Hello!"}],
    stream=True,
)

# print(completion.choices[0].message)
for i in completion:
    print(i)
