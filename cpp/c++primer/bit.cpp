#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <bitset>
using namespace std;

//big-endian and little-endian
//判断机器的字节序
bool isLittleEndian(){
    union{
        int a;
        char b;
    }c;
    c.a = 1;
    return c.b == 1; //联合体union的存放顺序是所有成员都从低地址开始存放
}

bool isLittleEndian2(){
    int a = 1;
    char* p = (char*)&a;
    return *p == 1;
}

class A{};
class B{
    int a;
};
class C{
public:
    int a;
    char b;
    int c;
    static const int d{0};//静态常量成员可以类内初始化
    static constexpr int e{0};
    static int f;
};

int C::f = 0;//静态成员变量的定义需要在类外定义，为了保证编译时类成员的定义只存在于一个目标文件中

int main(){
    /*
    关闭ALSR，随机内存排布，方便观察内存排布
    查看，cat /proc/sys/kernel/randomize_va_space 或 sysctl -a --pattern randomize
    0 = 关闭
    1 = 半随机。共享库、栈、mmap() 以及 VDSO 将被随机化。（留坑，PIE会影响heap的随机化。。）
    2 = 全随机。除了1中所述，还有heap。

    关闭ASLR，临时改变
    sysctl -w kernel.randomize_va_space=0
    gdb调试时改变：
    关闭ASLR：
    set disable-randomization on
    开启ASLR：
    set disable-randomization off
    查看ASLR状态：
    show disable-randomization
    */
    int a=2;
    unsigned int i = 8;
    printf("var a addr:%p\n",&a);
    printf("var i addr:%p\n",&i);   //栈上变量，地址从低到高排布
    int arr[]={1,2,3,4,5};
    for(auto &i:arr){
        printf("arr addr %p\n",&i);
    }

    int *arr_heap = new int[5];
    for(int i=0;i<5;i++){
        printf("heap arr addr:%p\n",&arr_heap[i]);
    }
	cout<<hex<<"hex:i="<<static_cast<unsigned int>(i)<<endl;
	cout<<oct<<"oct:i="<<static_cast<unsigned int>(i)<<endl;
	cout<<dec<<"dec:i="<<static_cast<unsigned int>(i)<<endl;
	cout<<"bin:i="<<bitset<sizeof(unsigned int)*8>(i)<<endl;
    cout<<"bin:-8="<<bitset<sizeof(unsigned int)*8>(-8)<<endl;
    cout<<"is little endian "<<isLittleEndian()<<endl;
    cout<<"is little endian "<<isLittleEndian2()<<endl;

    //char arrmax[9*1024*1024];  栈溢出
    cout<<"size of class A "<<sizeof(A)<<endl;
    cout<<"size of class B "<<sizeof(B)<<endl;
    cout<<"size of class C "<<sizeof(C)<<endl;
    cout<<"size of Class C.a "<<sizeof(C::a)<<endl;
    unsigned long bit_offset = 1UL<<7;
    unsigned long bit_offset1 = 1UL<<6;
    auto ret = bit_offset|bit_offset1;
    cout<<"bin:bit_offset="<<bitset<sizeof(bit_offset)*8>(bit_offset)<<endl;
    cout<<"bin:ret="<<bitset<sizeof(ret)*8>(ret)<<endl;

    union {
        int a:4;
        int b:4;
        int c:8;
    }tmp;
    tmp.a= 1;
    tmp.b=1;
    tmp.c=1;
    cout<<"bin:tmp.a="<<sizeof(tmp)<<" "<<bitset<sizeof(tmp)*8>(tmp.a)<<endl;
    cout<<"bin:tmp.b="<<sizeof(tmp)<<" "<<bitset<sizeof(tmp)*8>(tmp.b)<<endl;
    cout<<"bin:tmp.c="<<sizeof(tmp)<<" "<<bitset<sizeof(tmp)*8>(tmp.c)<<endl;

    /*constexpr*/ bitset<5> b{"10110"};
    printf("%s\n",b.to_string().c_str());
    bitset<5> b1{"11111"};
    bitset<5> b2{"11111"};
    auto b3 = b1&b2;
    cout<<"b3 is "<<b3<<endl;

    //c++11可以对非静态成员变量直接做sizeof，在c++98编译无法通过
    cout<<"C::a size is "<<sizeof(C::a)<<endl;
    cout<<"c::d size is "<<sizeof(C::d)<<endl;
    cout<<"c::f size is "<<sizeof(C::f)<<endl;
    return 0;
}