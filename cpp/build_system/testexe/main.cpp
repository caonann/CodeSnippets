#include <iostream>
#include "testlib/testlib.hpp"
#include "testlib2/testlib2.hpp"

int main() {
  int a = 10;
  int b = 8;
  int c = 2;
  std::cout << add(a, b) << std::endl;
  std::cout << foo(a, b, c) << std::endl;
}