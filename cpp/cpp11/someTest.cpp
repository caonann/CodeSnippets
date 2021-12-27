/*************************************************************************
	> File Name: someTest.cpp
	> Author: caonan
	> Mail: caonann@qq.com
	> Created Time: Tue 01 Jun 2021 11:41:38 PM CST
 ************************************************************************/
_Pragma("once");
#include <iostream>
#include <stdio.h>
using namespace std;

void printThisFunc(){
	printf("this func is %s",__func__);
}
int main()
{
	printThisFunc();
    return 0;
}

