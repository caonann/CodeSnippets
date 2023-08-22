#include <cassert>
#include <cstdio>
#include <iostream>

int get_size(int n) {
  int sum = 10 * n;
  return sum;
}
int main() {
  unsigned arr_len = 10;  // 非常量表达式为什么也能编译通过？
  std::string str_arr[arr_len];
  // constexpr unsigned sz = 20;
  // string strArr2[sz];
  std::string str_arr3[get_size(2)];
  for (int i = 0; i < get_size(2); i++) {
    std::cout << str_arr3[i] << std::endl;
  }
  return 0;
}
