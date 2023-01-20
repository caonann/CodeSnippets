#include <stdio.h>
#include <iostream>

class A {
 public:
  A() {}
  explicit A(int a) : m_a(a) {}
  A(int a, std::string b) : m_a(a), m_strb(b) {}
  inline void show_var() { printf("m_a: %d,m_strb %s\n", m_a, m_strb.c_str()); }

 private:
  int m_a{0};
  std::string m_strb{"aa"};
};

int main() {
  A a(1, "bb");
  a.show_var();
  A b;
  b.show_var();
  A c(2);
  c.show_var();
  // A d=1;//隐式类型转换 对应构造函数声明了explicit，禁用了隐式类型转换
  // d.show_var();
  return 0;
}