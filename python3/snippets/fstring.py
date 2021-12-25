#!/usr/bin/env python
# coding=utf-8
import datetime
#refrence https://imliyan.com/blogs/article/Python3.6%E6%96%B0%E7%9A%84%E5%AD%97%E7%AC%A6%E4%B8%B2%E6%A0%BC%E5%BC%8F%E5%8C%96%E8%AF%AD%E6%B3%95/
name='hulk'
out_str=f"i am {name}"
print(out_str)

# https://mp.weixin.qq.com/s/DcOey8jCVkQbQiixNtbaPA
str_value = "hello，python coders"  
print(f"{ str_value = }")  

num_value = 123  
print(f"{num_value % 2 = }") 

today = datetime.date.today()  
print(f"{today: %Y%m%d}")  
print(f"{today =: %Y%m%d}")  