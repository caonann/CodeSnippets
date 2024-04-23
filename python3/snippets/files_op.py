#!/usr/bin/env python
# coding=utf-8
import os

csv_file_name = "testfile.txt"
with open(csv_file_name, "a+") as f:
    lines = f.readlines()
    print(lines)

file_name = "a.txt"
with open(file_name, "a+") as f:
    content = """
#include <iostrea>
int main(){
    return 0;
}
    """
    f.write(content)


file_path = "/user/local/file.txt"
path, fullflname = os.path.split(file_path)
fname, ext = os.path.splitext(fullflname)

print(f"{path=} {fullflname=} {fname=} {ext=}")


dirname = os.path.dirname(__file__)
print(f"{dirname=}")

from pathlib import Path

path = Path(__file__)
print("path.parent.absolute()", path.parent.absolute())
normalpath = os.path.normpath(__file__)
afternormal = os.path.dirname(normalpath)
print(afternormal)
sp = os.path.split(dirname)[-1]
print(sp)

print("-" * 20)
dirs = os.path.dirname(__file__)
print(dirs)
paths = os.listdir(dirs)
print(paths)
modules = []
sp_dir = os.path.split(dirs)
print(f"{sp_dir=}")
for p in paths:
    abs_path = os.path.join(dirs, p)
    if not p.startswith("__") and os.path.isdir(abs_path):
        modules.append(p)

print(modules)
