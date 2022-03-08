#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;

int main(){
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