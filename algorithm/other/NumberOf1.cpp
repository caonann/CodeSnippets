/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   NumberOf1.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: NumberOf1.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Sun 15 Apr 2018 04:00:11 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int  NumberOf1(int n)
{
    int c = 0;

    while (n)
    {
        c++;
        n = (n - 1)&n;
    }

    return c;
}

int main()
{
    cout << NumberOf1(8) << endl;
    return 0;
}

