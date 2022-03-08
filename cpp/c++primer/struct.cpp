#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;
struct Foo{};

void test_func(){
    struct Foo2{
        int a;
    };
    Foo2 f;
}
int main(){
    test_func();
    return 0;
}