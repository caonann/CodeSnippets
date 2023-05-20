import os

import openai

openai.api_key = os.getenv("OPENAI_API_KEY")
domain = os.getenv("DOMAIN")


openai.api_base = f"http://{domain}/v1"
# openai.api_type = "azure"
# openai.api_version = "2023-03-15-preview"

completion = openai.ChatCompletion.create(
    # engine="gpt-35-turbo-0301",
    model="gpt-3.5-turbo",
    messages=[{"role": "user", "content": "Hello!"}],
    stream=False,
)

# print(completion.choices[0].message)
for i in completion:
    print(i)
