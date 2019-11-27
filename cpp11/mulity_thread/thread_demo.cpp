//
// Created by cn on 2019/4/25.
//

#include <iostream>
#include <assert.h>
#include <list>
#include <deque>
#include <vector>
#include <map>
#include <initializer_list>
#include <memory>
#include <assert.h>
#include <string.h>
#include <type_traits>
#include <thread>
#include <atomic>
using namespace std;

atomic_llong total{0};

void func_total(int)
{
    for (int64_t i = 0; i < 100000000LL; i++)
    {
        total++;
    }
}

void test_thread_demo1()
{
    auto func = [](int)->void {
        for (int64_t i = 0; i < 100000000LL; i++)
        {
            total++;
        }
    };

    std::thread t1(func_total,0);
    std::thread t2(func_total,0);
    t1.join();
    t2.join();
    cout<<"total is "<<total<<endl;
}

int main()
{
    cout<<"trehad_demo"<<endl;
    //todo:得到得结果不符合预期
    test_thread_demo1();

    return 0;
}