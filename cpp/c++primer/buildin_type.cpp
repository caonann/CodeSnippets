#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;

// 注释 //,/**/
// 控制流
// 基本内置变量类型

int main(){
    
    /*
    在16位机中，int跟short int一样2字节，long 4字节；
    在32位机中，int 跟long int一样4字节，需要64位int就用long long int，即int64;
    在64位机中，int还是4字节，long int 8字节。
    */
    printf("size of bool:%d,char:%d ,int:%d, short:%d,float:%d, double:%d,long:%d,long long:%d,long double:%d\n",
        sizeof(bool),sizeof(char),sizeof(int),sizeof(short),sizeof(float),sizeof(double),sizeof(long),sizeof(long long),sizeof(long double));
    
    //字面常量
    1L;
    012;
    0xC1;
    
    

    return 0;
}