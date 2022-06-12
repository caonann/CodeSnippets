#!/usr/bin/env python
# coding=utf-8
import os

csv_file_name='testfile.txt'
with open(csv_file_name, 'a+') as f:
    lines = f.readlines()
    print(lines)

file_name='a.txt'
with open(file_name,'a+') as f:
    content='''
#include <iostrea>
int main(){
    return 0;
}
    '''
    f.write(content)


file_path='/user/local/file.txt'
path , fullflname = os.path.split(file_path)
fname, ext = os.path.splitext(fullflname)

print(f"{path=} {fullflname=} {fname=} {ext=}")