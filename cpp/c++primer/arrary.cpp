#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;
int get_size(int n){
    return 10*n;
}
int main(){
    unsigned int arr_len = 10;  //非常量表达式为什么也能编译通过？
    string strArr[arr_len];
    constexpr unsigned sz = 20;
    string strArr2[sz];
    string strArr3[get_size(2)];
    return 0;
}