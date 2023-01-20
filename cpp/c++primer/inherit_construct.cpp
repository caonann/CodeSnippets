// c++11 继承构造函数
#include <iostream>
class A {
 public:
  A(int) {}
};

class B : public A {
  using A::A;
  // 使用了继承构造函数，编译器不会为派生类生成默认构造函数
  // 基类构造函数被声明为私有成员函数或，派生类是从基类中虚继承的，编译器不会为派生类生成默认构造函数
};

int main() {
  // B b;  //因此该行编译不过
  B b{1};  // 没问题，编译通过
  return 0;
}