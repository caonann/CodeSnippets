# -*- coding: utf-8 -*-
class A:
    class_attr=0
    def __init__(self) -> None:
        self.instance_attr=1
        
print(A.class_attr)
print(A.instance_attr)#wrong 类不能调实例的变量
a = A()
print(a.instance_attr)
print(a.class_attr)