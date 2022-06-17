import time
from datetime import datetime

print(time.strftime("%Y-%m-%d %H:%M:%S", time.localtime()))
now = datetime.now()
timestamp = datetime.timestamp(now)
print("时间戳 =", int(timestamp))
