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
    
    int test_i = 0;
    int *p1 = &test_i;
    int *p2 = &test_i;
    assert(p1 == p2); //p1,p2存储的对象地址相同
    assert(&p1!=&p2); //p1,p2本身的地址不相同

    const int c1 = test_i;
    int *test_i2 = new int(0);
    const int c2 = *test_i2;
    cout<<c2<<endl;
    const int *pp;
    int* const pp1 = &test_i;
    *pp1 = 2;
    cout<<test_i<<endl;

    const int v2 = 0;
    int v1 = v2;

    const int &v3 = 1;
    const int &v4 = v3;
    return 0;
}