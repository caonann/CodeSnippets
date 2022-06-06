import uuid
import base64
import os

file_names = ['你好', 'abc', r'%-#abc$bcq', 'a ce你好']
name_space = 'test'

for idx, _ in enumerate(file_names):
    b64 = base64.b64encode(bytes(_,encoding='utf-8'))
    print(b64)
    print(f"{idx}: {uuid.uuid1()}")
    uid_namespace = uuid.uuid1()
    print(f"{idx}: {uuid.uuid3(uid_namespace,_)}")
    print(f"{idx}: {uuid.uuid4()}")
    #print(f"{idx}: {uuid.uuid5(name_space,_)}")
    print(base64.b64decode(b64))

file_path = r'/usr/local/src/你好$-%123-*&^.txt'
filepath ,fullflname = os.path.split(file_path)
print((filepath ,fullflname))
print(os.path.splitext(fullflname))