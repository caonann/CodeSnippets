#include <stdio.h>
/*
c++11 析构函数默认是noexcept(true)的，但如果显示指定，还是可以抛异常的
*/
class A{
public:
    ~A(){
        printf("destruct A\n");
        throw 1;
    }
};

class B{
public:
    ~B() noexcept(false){
        printf("destruct B\n");
        throw 2;
    }
};

class C{
public:
    B b;
};

int main(){
    try{
        B b;
    }catch(...){
        printf("caught B\n");
    }

    try{
        C c;
    }catch(...){
        printf("caught C\n");
    }

    try{
        A a;
        //a在析构的时候禁止了异常的传播noexcept修饰的函数通过std::terminate的调用来结束程序的执行
    }catch(...){
        printf("caught A\n");
    }
    return 0;
}