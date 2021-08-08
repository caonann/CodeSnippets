#!/usr/bin/env python
# coding=utf-8

csv_file_name='testfile.txt'
with open(csv_file_name, 'a+') as f:
    lines = f.readlines()
    print(lines)