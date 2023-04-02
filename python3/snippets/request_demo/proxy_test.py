import os

import requests

https_domain = os.getenv("HTTPS_DOMAIN")
print(https_domain)
proxies = {
    "http": f"https://{https_domain}",
    # "https": "http://127.0.0.1:18800",
    "https": f"https://{https_domain}",
}

r = requests.post(f"https://hello.com/v1/openai-proxy", proxies=proxies, json={})
print(r.content)
