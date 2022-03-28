#include<iostream>
#include<stdio.h>
class Base{
public:
    virtual void printSomeThing()=0;
};

class Child:public Base{
public:
    //这里加了final，则继承类无法在重载该函数，这个关键字只适合中间类，
    //因为放在基类virtual函数就没有意义了，不如声明成普通成员函数
    void printSomeThing() /*final*/{ 
        printf("this is Child\n");
    }
};

class ChildChild:public Child{
public:
    //override声明了该函数一定是基于基类的重载，避免了书写上的错误和继承关系层数太多导致书写错误
    void printSomeThing() override {
        printf("this is ChildChild\n");
    }

    //函数重载，函数名，形参列表
    void printSomeThing(int a,int b){
        std::cout<<a<<b<<std::endl;
    }

    
};

int main(){
    Base *p= new ChildChild;
    p->printSomeThing();
    return 0;
}