import os

import openai

openai.api_key = os.getenv("OPENAI_API_KEY")
https_domain = os.getenv("HTTPS_DOMAIN")
print(https_domain)
if not https_domain:
    print("with out https domain")
    exit(0)
    
openai.proxy = {"https": https_domain, "http": https_domain}

completion = openai.ChatCompletion.create(
    model="gpt-3.5-turbo", messages=[{"role": "user", "content": "Hello!"}]
)

print(completion.choices[0].message)
