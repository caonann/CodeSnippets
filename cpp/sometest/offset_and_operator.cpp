/*
比较位移和标准的乘除运算时间差异
*/

#include "../timestamp/timestamp.h"
#include <stdio.h>
using namespace muduo;

static const int knumber = 10000*10000;
//比较位运算和正常操作符的性能
void diff_offset_operator(){
    int ret=0;
    Timestamp start(Timestamp::now());
    for(int i=0;i<knumber;i++){
        ret = i/2;
    }
    Timestamp end(Timestamp::now());
    printf("operator time used %f\n",timeDifference(end,start));

    Timestamp start1(Timestamp::now());
    for(int i=0;i<knumber;i++){
        ret = i>>2;
    }
    Timestamp end1(Timestamp::now());
    printf("offset time used %f\n",timeDifference(end1,start1));
}   

int main(){
    for( int i=0;i<10;i++){
        diff_offset_operator();
    }
    //结论是时间基本差不多，没有什么区别
    return 0;
}