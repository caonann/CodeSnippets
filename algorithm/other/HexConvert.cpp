/*
 @copyright  2004-2015  Apache License, Version 2.0
 @filename   HexConvert.cpp
 @author     caonan
 @version
 @date       2019/10/03 16:07
 @brief
 @details    2019/10/03 root create
*/
/*************************************************************************
    > File Name: HexConvert.cpp
    > Author: hulkcao
    > Mail: caonann@qq.com
    > Created Time: Mon Sep 23 13:07:11 2019
 ************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <queue>
#include <random>
#include <vector>
#include <bitset>
#include <string.h>
#include <limits.h>
#include <stdio.h>
using namespace std;

// 大数相加
std::string BiggerPlus(string s1, string s2)
{
    int len1, len2;
    len1 = static_cast<int>(s1.size());
    len2 = static_cast<int>(s2.size());
    const int Max = 1000;
    static int a[Max];
    static int b[Max];
    // 初始化
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));

    // 读数据,s1的最后位保存在数组中的开始部分
    for (int i = len1 - 1, k = 0; i != -1; --i)
    {
        a[k] = s1[i] - '0';
        ++k;
    }

    for (int j = len2 - 1, k = 0; j != -1; --j)
    {
        b[k] = s2[j] - '0';
        ++k;
    }

    // 做加法
    int up = 0;

    for (int i = 0; i < Max; ++i)
    {
        a[i] = a[i] + b[i] + up;
        up = a[i] / 10;
        a[i] = a[i] % 10;
    }

    // 从右向左找到a数组中第一个不为0的数
    int k = Max - 1;

    while (a[k] == 0)
    {
        --k;
    }

    // 从右边第一个不为0的数开始，向左输出数组
    std::string out;

    for (int i = k; i != -1; --i)
    {
        out += std::to_string(a[i]);
    }

    return out;
}

// 大数10进制转16进制
std::string ordToHexConvert(const std::string &ord, bool upper_case = true)
{
    static const char *const lut = "0123456789ABCDEF";
    static const char *const slut = "0123456789abcdef";
    static char output[1000];
    memset(output, 0, sizeof(output));
    int len = static_cast<int>(ord.length());

    if (len >= 1000 || len <= 0)
    {
        return std::string();
    }

    vector<int> input;

    for (int i = 0; i < len; i++)
    {
        input.push_back(ord[i] - '0');
    }

    int shang_sum = 1;
    int k = 0;
    int shang = 0;
    int j = 0;
    int yu = 0;

    while (shang_sum)
    {
        shang_sum = 0;

        for (int i = 0; i < len; i++)
        {
            j = i + 1;
            shang = input[i] / 16;
            shang_sum += shang;
            yu = input[i] % 16;

            if (i == (len - 1))
            {
                if (upper_case)
                {
                    output[k++] = lut[yu];
                }
                else
                {
                    output[k++] = slut[yu];
                }

                // cout<<"output "<<output[k-1]<<endl;
            }
            else
            {
                input[j] += yu * 10;
            }

            input[i] = shang;
            // cout<<"shang_sum "<<shang_sum<< " shang "<<shang<<" yu "<<yu<<" inputi "<<i<<" "<<input[i]<<" inputj "<<j<<" "<<(j>=len-1?-111:input[j])<<endl;
        }
    }

    std::string ret;

    if (k == 0)
    {
        ret = std::to_string(0);
    }
    else
    {
        for (int i = k - 1; i >= 0; i--)
        {
            ret += output[i];
        }
    }

    return ret;
}

// 大数10进制转2进制
std::string ordToBinary(const std::string &ord, bool upper_case = true)
{
    static int output[1000];
    memset(output, 0, sizeof(output));
    int len = static_cast<int>(ord.length());

    if (len >= 1000)
    {
        return std::string();
    }

    vector<int> input;

    for (int i = 0; i < len; i++)
    {
        input.push_back(ord[i] - '0');
    }

    int shang_sum = 1;
    int k = 0;
    int shang = 0;
    int j = 0;
    int yu = 0;

    while (shang_sum)
    {
        shang_sum = 0;

        for (int i = 0; i < len; i++)
        {
            j = i + 1;
            shang = input[i] / 2;
            shang_sum += shang;
            yu = input[i] % 2;
            cout << "shang_sum " << shang_sum << " shang " << shang << " yu " << yu << endl;

            if (i == (len - 1))
            {
                output[k++] = yu;
            }
            else
            {
                input[j] += yu * 10;
            }

            input[i] = shang;
        }
    }

    std::string ret;

    if (k == 0)
    {
        ret = std::to_string(0);
    }
    else
    {
        for (int i = k - 1; i >= 0; i--)
        {
            ret += std::to_string(output[i]);
        }
    }

    return ret;
}

std::random_device rd;
std::default_random_engine e(rd());
std::uniform_int_distribution<uint64_t> u(0, UINT_MAX);

void testBigAdd()
{
    for (int i = 0; i < 100; i++)
    {
        uint64_t num1 = u(e);
        uint64_t num2 = u(e);
        uint64_t ret = num1 + num2;
        std::string rets = BiggerPlus(std::to_string(num1), std::to_string(num2));
        assert(static_cast<uint64_t>(std::atoll(rets.c_str())) == ret);
        // printf("%llu,%llu\n",ret,std::atoll(rets.c_str()));
    }
}

int main()
{
    int n = 10;
    std::string binary = std::bitset<8>(n).to_string();
    cout << binary << endl;
    uint64_t Integer = 1274692992;
    char toHex[sizeof(uint64_t) * 8 / 4 + 1];
    bitset<sizeof(uint64_t)> toBin(Integer);
    sprintf(toHex, "%lx", Integer);
    cout << "toHex " << toHex << endl;
    cout << ordToHexConvert("") << endl;
    cout << ordToHexConvert("0") << endl;
    cout << ordToHexConvert("-123") << endl;
    cout << ordToHexConvert("1as2c3") << endl;
    std::random_device rd;
    std::default_random_engine e(rd());
    std::uniform_int_distribution<uint64_t> u(0, UINT_MAX);

    for (int i = 0; i < UINT_MAX; i++)
    {
        uint64_t randnum = u(e);
        // printf("ord:%lu\n",randnum);
        std::string hex_cus = ordToHexConvert(std::to_string(randnum) , false);
        // std::cout << std::hex << randnum << endl;
        char buf[128];
        snprintf(buf, sizeof(buf), "%lx", randnum);
        std::string hex_normal = buf;
        assert(hex_cus == hex_normal);
    }

    // std::string res = BiggerPlus("127469299210501205862","992105012058");
    // cout<<"res "<<res<<endl;
    // testBigAdd();
    // std::string binarytest="4123";
    // ordToBinary(timestamp);
    return 0;
}

