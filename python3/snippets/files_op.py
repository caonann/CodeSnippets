#!/usr/bin/env python
# coding=utf-8

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