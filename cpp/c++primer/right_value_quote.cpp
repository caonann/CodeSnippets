#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;
class test_obj{
public:
    test_obj(int a,std::string b):a(a),b(b){
        cout<<__func__<<" constructed"<<endl;
        //arrs_.resize(a);
        i++;
    }
    test_obj(){
        cout<<__func__<<" default constructed"<<endl;
    }
    test_obj(test_obj& rval){
        a = rval.a;
        b = rval.b;
        arrs_ = rval.arrs_;
        rval.b="abc";
        cout<<__func__<<" copyied pass by reference non const"<<endl;
    }
    
    test_obj(test_obj&& rval){
        cout<<__func__<<"copyied as rvalue reference"<<endl;
        //test_obj news = std::move(rval);
    }

    test_obj(const test_obj& rval){
        a = rval.a;
        b = rval.b;
        arrs_ = rval.arrs_;
        cout<<__func__<<" copyied pass by reference"<<endl;
    }

    //因为定义了test_obj(test_obj&& rval)，所以必须定义下面的函数？todo:
    //这个函数如果没有，编译会报错use of deleted function 'test_obj& test_obj::operator=(const test_obj&)
    //因为arrs_的成员是test_obj，所以会触发=重载操作符的拷贝
    test_obj& operator=(const test_obj& t){
        a = t.a;
        b = t.b;
        arrs_ = t.arrs_;
        return *this;
    }
    ~test_obj(){
        cout<<__func__<<" destructed"<<endl;
    }

    static void show_i() {
        printf("constructer calls %d times\n",i);
    }

private:
    int a;
    std::string b;
    vector<test_obj> arrs_;
    static int i;
};

int test_obj::i = 0;

test_obj returnRvalueTest(){
    return test_obj(0,"abc");
}

void acceptVal(test_obj){}
void acceptRef(const test_obj&){}

//对象创建的时候会隐士创建哪些函数？
/*
拷贝构造函数
重载赋值操作符
隐式类型转换函数（隐式类型转换的危害？）
*/

/*
编译器中被称为RVO/NRVO的优化（RVO, Return Value Optimization，返回值优化，或者NRVO，Named Return Valueoptimization)
-fno-elide-constructors 可以关闭这个功能
    The C++ standard allows an implementation to omit creating a
    temporary which is only used to initialize another object of the
    same type.  Specifying this option disables that optimization, and
    forces G++ to call the copy constructor in all cases.
*/

void test_case1(){
    test_obj b = returnRvalueTest();
    b.show_i();
    printf("obj address %p\n",&b);
    test_obj &&c = returnRvalueTest();
    cout<<"test_obj&& is rvalue reference "<<is_rvalue_reference<test_obj&&>::value<<endl;
    cout<<"object c is rvalue reference "<<is_rvalue_reference<decltype(c)>::value<<endl;
    cout<<"object b is not rvalue reference "<<is_rvalue_reference<decltype(b)>::value<<endl;
}

void test_case2(){
    acceptVal(returnRvalueTest());
    cout<<"--------------------"<<endl;
    acceptRef(returnRvalueTest());
    /*with -fno-elide-constructors
        test_obj constructed
        test_objcopyied as rvalue reference
        ~test_obj destructed
        test_objcopyied as rvalue reference
        ~test_obj destructed
        ~test_obj destructed
        --------------------
        test_obj constructed
        test_objcopyied as rvalue reference
        ~test_obj destructed
        ~test_obj destructed
    */

    /*without -fno-elide-constructors
        test_obj constructed
        ~test_obj destructed
        --------------------
        test_obj constructed
        ~test_obj destructed
    */
}

void test_case3(){
    test_obj::show_i();
}

int main(){
    //g++ right_value_quote.cpp -fno-elide-constructors -g
    test_case2();
    return 0;
}