#!/usr/bin/env python3
# coding=utf-8
import os
import sys
import time
import json

class Context():
    def __getattr__(self,name):
        return self.__dict__[name]
    def __setattr__(self,name,value):
        self.__dict__[name] = value
    def get(self,name,default=None):
        try:
            return self.__getattr__(name)
        except KeyError:
            return default
    def __str__(self):
        return str(self.__dict__)
    def __contain__(self,name):
        return name in self.__dict__.keys()

sys.modules['context'] = Context()
sys.modules['common.context'] = Context()


#print(sys.modules)
c=Context()
c.testKey="test a"
print(c.testKey)