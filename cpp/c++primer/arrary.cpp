#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;
int get_size(int n){
    int sum = 10*n;
    return sum;
}
int main(){
    unsigned arr_len = 10;  //非常量表达式为什么也能编译通过？
    string strArr[arr_len];
    //constexpr unsigned sz = 20;
    //string strArr2[sz];
    string strArr3[get_size(2)];
    for(int i =0 ;i<get_size(2);i++){
        cout<<strArr3[i]<<endl;
    }
    return 0;
}